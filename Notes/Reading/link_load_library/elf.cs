
using System;
using System.Collections.Generic;
using System.Collections;
using System.Diagnostics;
using System.IO;
using System.Text;

using Elf32_Addr    = System.UInt32;
using Elf32_Half    = System.UInt16;
using Elf32_Off     = System.UInt32;
using Elf32_Word    = System.UInt32;
using Elf32_Sword   = System.Int32;


using Elf64_Addr    = System.UInt64;
using Elf64_Half    = System.UInt16;
using Elf64_Off     = System.UInt64;
using Elf64_Word    = System.UInt32;
using Elf64_Sword   = System.Int32;

namespace ELF
{
    public class ELF
    {
        public static void ReadELF(string file)
        {
            if(string.IsNullOrEmpty(file))
            {
                Trace.WriteLine("file is null");
                return;
            }
            if(!File.Exists(file))
            {
                Trace.WriteLine("file is exist");
                return;
            }
            var reader = new StreamReader(File.Open(file));
            var buff = new byte[16];
            reader.Read()
            var firstByte = reader.Read();


        }

    }

    public struct Elf32_Ehdr
    {
        public char[] e_ident;
        public Elf32_Half e_type;
        public Elf32_Half e_machine;
        public Elf32_Word e_version;
        public Elf32_Addr e_entry;
        public public Elf32_Off e_phoff;
        public Elf32_Off e_shoff;
        public Elf32_Word e_flags;
        public Elf32_Half e_ehsize;
        public Elf32_Half e_phentsize;
        public Elf32_Half e_phnum;
        public Elf32_Half e_shentsize;
        public Elf32_Half e_shnum;
        public Elf32_Half e_shstrndx;
    }
    public struct Elf64_Ehdr
    {
        public char[] e_ident;
        public Elf64_Half e_type;
        public Elf64_Half e_machine;
        public Elf64_Word e_version;
        public Elf64_Addr e_entry;
        public Elf64_Off e_phoff;
        public Elf64_Off e_shoff;
        public Elf64_Word e_flags;
        public Elf64_Half e_ehsize;
        public Elf64_Half e_phentsize;
        public Elf64_Half e_phnum;
        public Elf64_Half e_shentsize;
        public Elf64_Half e_shnum;
        public Elf64_Half e_shstrndx;
    }
}