using System;
using System.Collections;

/*
命令行使用：csc编译单个cs文件
EG：
csc /out:cc.exe .\FindMaxSubArray.cs
将编译FindMaxSubArray.cs生成cc.exe到源文件的同级目录下
*/
namespace FindMaxSubArrayNS
{
    public class FindMaxSubArrayClass
    {
        public static Tuple<int, int, int> FindMaxSubArrayCrossMid(int[] array, int low, int mid, int hig)
        {
            if (hig == low)
                return new Tuple<int, int, int>(low, hig, array[low]);
            int sum = 0, llow = mid, hhig = mid + 1;
            int lsum = int.MinValue, rsum = int.MinValue;
            for (int i = mid; i >= low; i--)
            {
                sum += array[i];
                if (sum > lsum)
                {
                    lsum = sum;
                    llow = i;
                }
            }
            sum = 0;
            for (int i = mid + 1; i <= hig; i++)
            {
                sum += array[i];
                if (sum > rsum)
                {
                    rsum = sum;
                    hhig = i;
                }
            }
            return new Tuple<int, int, int>(llow, hhig, lsum + rsum);
        }

        public static Tuple<int, int, int> FindMaxSubArray(int[] array, int low, int hig)
        {
            if (low == hig)
                return new Tuple<int, int, int>(low, hig, array[low]);
            int mid = (low + hig) / 2;
            var left = FindMaxSubArray(array, low, mid);
            var right = FindMaxSubArray(array, mid + 1, hig);
            var cross = FindMaxSubArrayCrossMid(array, low, mid, hig);
            if (left.Item3 > right.Item3 && left.Item3 > cross.Item3)
            {
                return left;
            }
            else if (right.Item3 > left.Item3 && right.Item3 > cross.Item3)
            {
                return right;
            }
            else
            {
                return cross;
            }
        }

        static void Main()
        {
            Tuple<int, int, int> res;
            res = FindMaxSubArray(new int[1] { 8 }, 0, 0);
            Console.WriteLine(string.Format("Low:{0}\tHIG:{1}\tSUM:{2}\t", res.Item1, res.Item2, res.Item3));
            res = FindMaxSubArray(new int[2] { 8, 9 }, 0, 1);
            Console.WriteLine(string.Format("Low:{0}\tHIG:{1}\tSUM:{2}\t", res.Item1, res.Item2, res.Item3));
            res = FindMaxSubArray(new int[2] { -8, -9 }, 0, 1);
            Console.WriteLine(string.Format("Low:{0}\tHIG:{1}\tSUM:{2}\t", res.Item1, res.Item2, res.Item3));
            res = FindMaxSubArray(new int[3] { 8, 9, 10 }, 0, 2);
            Console.WriteLine(string.Format("Low:{0}\tHIG:{1}\tSUM:{2}\t", res.Item1, res.Item2, res.Item3));
            res = FindMaxSubArray(new int[]{1,2,3,4,5,6,7}, 0, 6);
            Console.WriteLine(string.Format("Low:{0}\tHIG:{1}\tSUM:{2}\t", res.Item1, res.Item2, res.Item3));
            res = FindMaxSubArray(new int[]{10,-2,3,-4,-5,-6,7}, 0, 6);
            Console.WriteLine(string.Format("Low:{0}\tHIG:{1}\tSUM:{2}\t", res.Item1, res.Item2, res.Item3));
        }
    }
}