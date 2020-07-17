#define unsafe

using System;
using System.Threading;
using System.Numerics;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Runtime;
using System.Runtime.Intrinsics;
using System.Runtime.Intrinsics.X86;

namespace UseIntrinsics
{
    //https://devblogs.microsoft.com/dotnet/hardware-intrinsics-in-net-core/
    public class Use_Intrinsics
    {
        static void Main()
        {
            Console.WriteLine("Sse.IsSupported"+Sse.IsSupported);
            Console.WriteLine("Sse.X64.IsSupported"+Sse.X64.IsSupported);
            Console.WriteLine("Sse2.IsSupported"+Sse2.IsSupported);
            Console.WriteLine("Sse2.X64.IsSupported"+Sse2.X64.IsSupported);
            int[] arry = new int[10000*1];
            var random = new Random(17);
            for (int i = 0; i < arry.Length; i++)
            {
                arry[i] = random.Next(0,1024*4);
            }
            ReadOnlySpan<int> source = new ReadOnlySpan<int>(arry);
            var watch = new Stopwatch();
            var times = new List<double>();
            Use_Intrinsics use = new Use_Intrinsics();

            watch.Start();
            use.Sum(source);
            watch.Stop();
            times.Add(watch.Elapsed.TotalMilliseconds);

            watch.Reset();
            
            watch.Start();
            use.Sum_Unrolled(source);
            watch.Stop();
            times.Add(watch.Elapsed.TotalMilliseconds);
            
            watch.Reset();

            watch.Start();
            use.Sum_VectorT(source);
            watch.Stop();
            times.Add(watch.Elapsed.TotalMilliseconds);
            
            watch.Reset();

            watch.Start();
            use.Sum_Vectorized(source);
            watch.Stop();
            times.Add(watch.Elapsed.TotalMilliseconds);

            Console.WriteLine(string.Format("Sum:\t{0}",times[0]));
            Console.WriteLine(string.Format("Sum unrolled:\t{0}",times[1]));
            Console.WriteLine(string.Format("Sum vectorT:\t{0}",times[2]));
            Console.WriteLine(string.Format("Sum vectoried:\t{0}",times[3]));

        }

        public int Sum(ReadOnlySpan<int> source)
        {
            int result = 0;
            for (int i = 0; i < source.Length; i++)
            {
                result += source[i];
            }
            return result;
        }

        public unsafe int Sum_Unrolled(ReadOnlySpan<int> source)
        {
            int result = 0;
            int i = 0;
            int lastBlockIndex = source.Length - (source.Length % 4);
            fixed (int* pSource = source)
            {
                while (i < lastBlockIndex)
                {
                    result += pSource[i + 0];
                    result += pSource[i + 1];
                    result += pSource[i + 2];
                    result += pSource[i + 3];
                    i += 4;
                }
                while (i < source.Length)
                {
                    result += source[i];
                    i++;
                }
            }
            return result;
        }

        public int Sum_VectorT(ReadOnlySpan<int> source)
        {
            int result = 0;
            Vector<int> vresult = Vector<int>.Zero;
            int i = 0;
            int lastBlockIndex = source.Length - (source.Length % Vector<int>.Count);
            while (i < lastBlockIndex)
            {
                vresult += new Vector<int>(source.Slice(i));
                i += Vector<int>.Count;
            }
            for (int n = 0; n < Vector<int>.Count; n++)
            {
                result += vresult[n];
            }
            while (i < source.Length)
            {
                result += source[i];
                i++;
            }
            return result;
        }
        public int Sum_Vectorized(ReadOnlySpan<int> source)
        {
            if (Sse2.IsSupported)
            {
                return Sum_VectorizedSse2(source);
            }
            else
            {
                return Sum_VectorT(source);
            }
        }

        private unsafe int Sum_VectorizedSse2(ReadOnlySpan<int> source)
        {
            int result = 0;
            fixed (int* pSource = source)
            {
                Vector128<int> vresult = Vector128<int>.Zero;
                int i = 0;
                int lastBlockIndex = source.Length - (source.Length % 4);
                while (i < lastBlockIndex)
                {
                    vresult = Sse2.Add(vresult, Sse2.LoadVector128(pSource + i));
                    i += 4;
                }
                if (Ssse3.IsSupported)
                {
                    vresult = Ssse3.HorizontalAdd(vresult, vresult);
                    vresult = Ssse3.HorizontalAdd(vresult, vresult);
                }
                else
                {
                    vresult = Sse2.Add(vresult, Sse2.Shuffle(vresult, 0x4E));
                    vresult = Sse2.Add(vresult, Sse2.Shuffle(vresult, 0xB1));
                }
                result = vresult.ToScalar();
                while (i < source.Length)
                {
                    result += pSource[i];
                    i++;
                }
            }
            return result;
        }
    }
}