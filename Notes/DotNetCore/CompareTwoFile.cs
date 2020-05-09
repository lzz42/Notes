using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;

namespace DotNetCore
{
    /// <summary>
    /// 比较两个文件是否一样
    /// </summary>
    public class CompareTwoFile
    {
        private const int Buffer_Length = 1024 * 1024 * 1;
        /// <summary>
        /// 使用MD5进行文件比较
        /// </summary>
        /// <param name="lfile"></param>
        /// <param name="rfile"></param>
        /// <returns></returns>
        public static bool CompareFileByMd5(string lfile, string rfile)
        {
            using (MD5 md5 = MD5.Create())
            {
                byte[] lvalue, rvalue;
                using (FileStream f = File.Open(lfile, FileMode.Open))
                {
                    lvalue = md5.ComputeHash(f);
                }
                using (FileStream f = File.Open(lfile, FileMode.Open))
                {
                    rvalue = md5.ComputeHash(f);
                }
                return BitConverter.ToString(lvalue) == BitConverter.ToString(rvalue);
            }
        }

        /// <summary>
        /// 读取文件进行内容比较 将Bytes[]转为string
        /// </summary>
        /// <param name="lFile"></param>
        /// <param name="rFile"></param>
        /// <returns></returns>
        public static bool CompareFileByString(string lFile, string rFile)
        {
            int buffSize = Buffer_Length;
            using (FileStream lf = File.Open(lFile, FileMode.Open))
            using (FileStream rf = File.Open(rFile, FileMode.Open))
            {
                byte[] lBytes = new byte[buffSize];
                byte[] rBytes = new byte[buffSize];
                while (true)
                {
                    int lLen = lf.Read(lBytes, 0, buffSize);
                    int rLen = rf.Read(rBytes, 0, buffSize);
                    if (BitConverter.ToString(lBytes) != BitConverter.ToString(rBytes))
                    {
                        return false;
                    }
                    if (lLen == 0 || rLen == 0)
                    {
                        break;
                    }
                }
            }
            return true;
        }

        /// <summary>
        /// 读取文件进行内容比较 使用Linq SequenceEqual
        /// </summary>
        /// <param name="lFile"></param>
        /// <param name="rFile"></param>
        /// <returns></returns>
        public static bool CompareFileBySequenceEqual(string lFile, string rFile)
        {
            int buffSize = Buffer_Length;
            using (FileStream lf = File.Open(lFile, FileMode.Open))
            using (FileStream rf = File.Open(rFile, FileMode.Open))
            {
                byte[] lBytes = new byte[buffSize];
                byte[] rBytes = new byte[buffSize];
                while (true)
                {
                    int lLen = lf.Read(lBytes, 0, buffSize);
                    int rLen = rf.Read(rBytes, 0, buffSize);
                    if (!lBytes.SequenceEqual(rBytes))
                    {
                        return false;
                    }
                    if (lLen == 0 || rLen == 0)
                    {
                        break;
                    }
                }
            }
            return true;
        }

        /// <summary>
        /// 读取文件进行内容比较 While逐字节进行比较
        /// </summary>
        /// <param name="lFile"></param>
        /// <param name="rFile"></param>
        /// <returns></returns>
        public static bool CompareFileByArray(string lFile, string rFile)
        {
            int buffSize = Buffer_Length;
            using (FileStream lf = File.Open(lFile, FileMode.Open))
            using (FileStream rf = File.Open(rFile, FileMode.Open))
            {
                byte[] lBytes = new byte[buffSize];
                byte[] rBytes = new byte[buffSize];
                while (true)
                {
                    int lLen = lf.Read(lBytes, 0, buffSize);
                    int rLen = rf.Read(rBytes, 0, buffSize);
                    int index = 0;
                    while (index < lLen && index < rLen)
                    {
                        if (lBytes[index] != rBytes[index])
                        {
                            return false;
                        }
                        index++;
                    }
                    if (lLen == 0 || rLen == 0)
                    {
                        break;
                    }
                }
            }
            return true;
        }

        /// <summary>
        /// 读取文件进行内容比较 byte[]转为ReadOnlySpan进行比较
        /// </summary>
        /// <param name="lFile"></param>
        /// <param name="rFile"></param>
        /// <returns></returns>
        public static bool CompareFileByReadOnlySpan(string lFile, string rFile)
        {
            int buffSize = Buffer_Length;
            using (FileStream lf = File.Open(lFile, FileMode.Open))
            using (FileStream rf = File.Open(rFile, FileMode.Open))
            {
                byte[] lBytes = new byte[buffSize];
                byte[] rBytes = new byte[buffSize];
                while (true)
                {
                    int lLen = lf.Read(lBytes, 0, buffSize);
                    int rLen = rf.Read(rBytes, 0, buffSize);
                    ReadOnlySpan<byte> lSpan = new ReadOnlySpan<byte>(lBytes);
                    ReadOnlySpan<byte> rSpan = new ReadOnlySpan<byte>(rBytes);
                    if (!lSpan.SequenceEqual(rSpan))
                    {
                        return false;
                    }
                    if (lLen == 0 || rLen == 0)
                    {
                        break;
                    }
                }
            }
            return true;
        }


        public static void Main(string[] args)
        {
            string[] files = new string[2]
            {
                @"D:\ffmpeg.exe",
                @"D:\ffmpeg2.exe"
            };
            int t0 = Environment.TickCount;
            bool r1 = false, r2 = false, r3 = false, r4 = false, r5 = false;
            r1 = CompareFileByMd5(files[0], files[1]);
            int t1 = Environment.TickCount;

            r2 = CompareFileByString(files[0], files[1]);
            int t2 = Environment.TickCount;

            r3 = CompareFileBySequenceEqual(files[0], files[1]);
            int t3 = Environment.TickCount;

            r4 = CompareFileByArray(files[0], files[1]);
            int t4 = Environment.TickCount;

            r5 = CompareFileByReadOnlySpan(files[0], files[1]);
            int t5 = Environment.TickCount;

            string str1 = string.Format("Func:{0},Time:{1,6}ms,Result:{2}", "CompareFileByMd5           ", t1 - t0, r1);
            string str2 = string.Format("Func:{0},Time:{1,6}ms,Result:{2}", "CompareFileByString        ", t2 - t1, r2);
            string str3 = string.Format("Func:{0},Time:{1,6}ms,Result:{2}", "CompareFileBySequenceEqual ", t3 - t2, r3);
            string str4 = string.Format("Func:{0},Time:{1,6}ms,Result:{2}", "CompareFileByArray         ", t4 - t3, r4);
            string str5 = string.Format("Func:{0},Time:{1,6}ms,Result:{2}", "CompareFileByReadOnlySpan  ", t5 - t4, r5);

            Trace.TraceInformation("Start Test CompareTowFile....");
            Trace.TraceInformation(str1);
            Trace.TraceInformation(str2);
            Trace.TraceInformation(str3);
            Trace.TraceInformation(str4);
            Trace.TraceInformation(str5);
            Trace.TraceInformation("End Test CompareTowFile....");

            Console.WriteLine("Start Test CompareTowFile....");
            Console.WriteLine(str1);
            Console.WriteLine(str2);
            Console.WriteLine(str3);
            Console.WriteLine(str4);
            Console.WriteLine(str5);
            Console.WriteLine("End Test CompareTowFile....");
            Console.WriteLine("Version::" + Environment.Version.ToString());
        }
    }
}