using System;
using System.IO;
using System.Reflection;
using System.Buffers;
using System.Text;

namespace DotNetCore
{
    public class CheckCodingType
    {
        internal class EncodingDetect
        {
            public static readonly byte[] UTF8Bom = { 0xEF, 0xBB, 0xBF };
            public static readonly byte[] UTF16LeBom = { 0xFF, 0xFE };
            public static readonly byte[] UTF16BeBom = { 0xFE, 0xFF };
            public static readonly byte[] UTF32LeBom = { 0xFF, 0xFE, 0x00, 0x00 };
        }

        internal enum CodingType
        {
            None,
            // 0-255
            Ansi,
            // 0-127
            ASCII,
            // UTF16 Bom
            UnicodeBom,
            // UTF16 No Bom
            UnicodeNoBom,
            Utf8Bom,
            Utf8NoBom,
            BigEndianUnicodeBom,
            BigEndianUnicodeNoBom,
            Utf32Bom,
            Utf32NoBom,
        }

        public static string DetectWithBom(Stream stream)        
        {
            byte[] buffer = new byte[10];
            int size = stream.Read(buffer, 0, 10);
            if (size > 2)
            {
                if (size >= 3
                && buffer[0] == EncodingDetect.UTF8Bom[0]
                && buffer[1] == EncodingDetect.UTF8Bom[1]
                && buffer[2] == EncodingDetect.UTF8Bom[2])
                {
                    return "UTF8Bom";
                }
                if (size >= 2
                && buffer[0] == EncodingDetect.UTF16LeBom[0]
                && buffer[1] == EncodingDetect.UTF16LeBom[1])
                {
                    return "UTF16LeBom";
                }
                if (size >= 2
                && buffer[0] == EncodingDetect.UTF16BeBom[0]
                && buffer[1] == EncodingDetect.UTF16BeBom[1])
                {
                    return "UTF16BeBom";
                }
                if (size >= 4
                && buffer[0] == EncodingDetect.UTF32LeBom[0]
                && buffer[1] == EncodingDetect.UTF32LeBom[1]
                && buffer[2] == EncodingDetect.UTF32LeBom[2]
                && buffer[3] == EncodingDetect.UTF32LeBom[3])
                {
                    return "UTF32LeBom";
                }
            }
            return null;
        }

        static void Main(string[] args)
        {
            var dir = Assembly.GetExecutingAssembly().Location;
            var f1 = Path.Combine(dir,"utf8");

        }
    }
}