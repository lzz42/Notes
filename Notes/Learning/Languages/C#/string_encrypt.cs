// https://leetcode-cn.com/problems/sort-array-by-parity-ii/
using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
 
namespace MyEncrypt
{
    public class Encrypt
    {

        /// <summary>
        /// 加密字符串
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public static string Encrypt(string value)
        {
            if (string.IsNullOrEmpty(value))
            {
                return null;
            }
            var BSKEY = Convert.FromBase64String("pB79LqQBSZY=");
            var BSIV = Convert.FromBase64String("HDztqlBKcME=");
            byte[] data = Encoding.Unicode.GetBytes(value);//待加密字符串
            string deStr = null;
            using (var ms = new MemoryStream())
            {
                //用内存流实例化加密流对象
                CryptoStream cts = new CryptoStream(ms, new DESCryptoServiceProvider().CreateEncryptor(BSKEY, BSIV), CryptoStreamMode.Write);
                cts.Write(data, 0, data.Length);//向加密流中写入数据
                cts.FlushFinalBlock();//将数据压入基础流
                deStr = Convert.ToBase64String(ms.GetBuffer(), 0, (int)ms.Length);
                cts.Close();//关闭加密流
                ms.Close();//关闭内存流
            }
            return deStr;
        }

        /// <summary>
        /// 解密字符串
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public static string Decrypt(string value)
        {
            if (string.IsNullOrEmpty(value))
            {
                return null;
            }
            var BSKEY = Convert.FromBase64String("pB79LqQBSZY=");
            var BSIV = Convert.FromBase64String("HDztqlBKcME=");
            byte[] data = Convert.FromBase64String(value);//待加密字符串
            string encryptedStr = null;
            using (var ms = new MemoryStream(data))
            {
                //用内存流实例化加密流对象
                CryptoStream cts = new CryptoStream(ms, new DESCryptoServiceProvider().CreateDecryptor(BSKEY, BSIV), CryptoStreamMode.Read);
                var reader = new StreamReader(cts,Encoding.Unicode);
                encryptedStr = reader.ReadToEnd();
                cts.Close();//关闭加密流
                ms.Close();//关闭内存流
                reader.Close();
            }
            return encryptedStr;
        }
    }
}