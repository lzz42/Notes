
```C#
        #region LZW

        public static Dictionary<string, ushort> Root { get; set; }
        public static ushort Max { get; set; }

        public static Dictionary<ushort, string> DecodeRoot { get; set; }
        public static ushort DecodeMax { get; set; }

        /*
         https://www.cnblogs.com/jillzhang/archive/2006/11/06/551298.html
        */

        public static void InitLzw()
        {
            Root = new Dictionary<string, ushort>();

            for (byte i = 0x20; i <= 0x7E; i++)
            {
                var s = Encoding.ASCII.GetString(new byte[1] { i });
                Root.Add(s, i);
            }
            Max = 0x7E + 1;
            var encoding = Encoding.GetEncoding("GB2312");
            for (var area = 16; area <= 55; area++)
            {
                int len = area == 55 ? 89 : 94;
                for (int j = 0; j <= len; j++)
                {
                    byte[] buff = new byte[2]
                    {
                        (byte)(area + 0xA0),
                        (byte)(j + 0xA0),
                    };
                    var str = encoding.GetString(buff);
                    for (int i = 0; i < str.Length; i++)
                    {
                        Root.Add(str[i].ToString(), Max);
                        Max++;
                    }
                }
            }
            var cnsymbols = new List<string>() { "（", "）", "，", "“", "：", "？", "。", "、", "！", "》", "《", "—", "；", "‘" };
            cnsymbols.ForEach(s =>
            {
                Root.Add(s, Max);
                Max++;
            });
            // var lisc = new List<string>()
            // {
            //     "[NotRender:",
            //     "[Name:",
            //     "[Text:",
            //     "[CIdx:",
            //     "[RIdx:",
            //     "[MouseWheel:",
            // };
            // var rootkk = new List<string>();
            // lisc.ForEach(s =>
            // {
            //     for (int i = 2; i <= s.Length; i++)
            //     {
            //         var ss = s.Substring(0, i);
            //         if (!rootkk.Contains(ss))
            //             rootkk.Add(ss);
            //     }
            // });
            // var lisx = new List<string>()
            // {
            //     "[CIdx:{0}]",
            //     "[RIdx:{0}]",
            //     "[CIdx:{0}",
            //     "[RIdx:{0}",
            // };
            // lisx.ForEach(s =>
            // {
            //     for (int i = 0; i < 7; i++)
            //     {
            //         rootkk.Add(string.Format(s, i));
            //     }
            // });
            // rootkk.Add("[CIdx:0][CIdx:0]");
            // rootkk.Add("[RIdx:0][RIdx:0]");
            // string idx = "[RIdx:{0}]";
            // string idxx = "[RIdx:0]";
            // for (int i = 1; i < 6; i++)
            // {
            //     idxx += string.Format(idx, i);
            //     rootkk.Add(idxx);
            // }
            // idx = "[CIdx:{0}]";
            // idxx = "[CIdx:0]";
            // for (int i = 1; i < 6; i++)
            // {
            //     idxx += string.Format(idx, i);
            //     rootkk.Add(idxx);
            // }
            foreach (var item in rootkk)
            {
                Root.Add(item, Max);
                Max++;
            }
            DecodeMax = Max;
            DecodeRoot = new Dictionary<ushort, string>();
            foreach (var item in Root)
            {
                DecodeRoot.Add(item.Value, item.Key);
            }
        }

        public static void LZWEncode(string istr, out string ostr)
        {
            ostr = null;
            var dic = Root;
            List<ushort> outs = new List<ushort>();
            ushort max = Max;
            string prefix = "";
            for (int i = 0; i < istr.Length; i++)
            {
                string sprefix = prefix + istr[i];
                if (dic.ContainsKey(sprefix))
                {
                    prefix = sprefix;
                    continue;
                }
                else
                {
                    outs.Add(dic[prefix]);
                    dic.Add(sprefix, max);
                    max++;
                    prefix = istr[i].ToString();
                }
            }
            outs.Add(dic[prefix]);
            Max = max;
            var builder = new StringBuilder(outs.Count);
            for (int i = 0; i < outs.Count; i++)
            {
                builder.Append(string.Format("{0:x}", outs[i]).PadRight(4,'0'));
            }
            ostr = builder.ToString();
            Trace.WriteLine(string.Format("{0}---{1}", istr.Length, ostr.Length));
        }

        public static void LZWDecode(string istr, out string ostr)
        {
            ostr = null;
            List<ushort> outs = new List<ushort>();
            for (int i = 0; i < istr.Length; i = i + 4)
            {
                outs.Add(ushort.Parse(istr.Substring(i, 4), System.Globalization.NumberStyles.HexNumber));
            }
            var dic = DecodeRoot;
            StringBuilder builder = new StringBuilder(outs.Count);
            builder.Append(dic[outs[0]]);
            string prefix = dic[outs[0]];
            string p = "";
            string c = "";
            for (int i = 1; i < outs.Count; i++)
            {
                if (dic.ContainsKey(outs[i]))
                {
                    builder.Append(dic[outs[i]]);
                    p = prefix;
                    c = p[0].ToString();
                    dic.Add(Max, p + c);
                    Max++;
                }
                else
                {
                    p = prefix;
                    c = prefix[0].ToString();
                    builder.Append(p + c);
                    dic.Add(Max, p + c);
                    Max++;
                }
            }
            ostr = builder.ToString();
        }

        #endregion LZW
```
