using System;
using System.Collections;
using System.Text;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Reflection;

/*
csc编译

csc .\dotNetKnown.cs /OUT:d.exe /unsafe

*/

namespace dotNetKnown
{
    public class Program
    {
        static int k = 2;
        //验证堆栈变量地址，从高到低一次进行分配
        static void ShowStack_VariableAddress()
        {
            var a0 = 301415926;
            var a1 = 20000;
            var a2 = 20101;
            var a3 = 20202;
            var a4 = 20303;
            var a5 = 20404;
            Console.WriteLine("Start");
            unsafe
            {
                int* pp = &a1;
                for (int i = 0; i < 4; i++)
                {
                    pp--;
                    Console.WriteLine(string.Format("Int32:\t{0}\tInt64:\t{0}\t", (Int32)pp, (Int32)pp));
                    Console.WriteLine(string.Format("地址值:\t{0}", *pp));
                }
            }
            Console.WriteLine("Done");
            if (k > 0)
            {
                k--;
                Console.WriteLine("************");
                ShowStack_VariableAddress();
            }
        }

        static void ShowObject_Size()
        {
            var user1 = new User();
            var suser2 = new SUser();
            unsafe
            {
                Console.WriteLine("User :\t{0} SUser:\t{1}", sizeof(User), sizeof(SUser));
            }
        }

        public static void TestInherit()
        {
            ABase s10 = new Sub();
            Sub s11 = new Sub();
            ABase s20 = new SSub();
            Sub s21 = new SSub();
            SSub s22 = new SSub();
            Console.WriteLine("****{0}\t{1}\t{2}", s10.ID, s10.GetName(), s10.PrintType());
            Console.WriteLine("****{0}\t{1}\t{2}", s11.ID, s11.GetName(), s11.PrintType());
            Console.WriteLine("****{0}\t{1}\t{2}", s20.ID, s20.GetName(), s20.PrintType());
            Console.WriteLine("****{0}\t{1}\t{2}", s21.ID, s21.GetName(), s21.PrintType());
            Console.WriteLine("****{0}\t{1}\t{2}", s22.ID, s22.GetName(), s22.PrintType());
        }
        static void Main(string[] args)
        {
            //ShowStack_VariableAddress();
            //ShowObject_Size();
            TestInherit();
        }
    }

    public struct User
    {
        public int Age;
        public bool IsAlive;
        public char X;
    }

    public struct SUser
    {
        public int No;
    }
    #region

    public abstract class ABase
    {
        public int ID = 2000;
        public abstract string GetName();
        public virtual string PrintType()
        {
            return this.GetType().Name;
        }
    }

    public class Sub : ABase
    {
        public new int ID = 3000;
        public override string GetName()
        {
            return "SubName1";
        }

        public override string PrintType()
        {
            return this.GetType().Name;
        }
    }

    public class SSub : Sub
    {
        public new int ID = 4000;
        public string GetName()
        {
            return "SubName2";
        }

        public new string PrintType()
        {
            return this.GetType().Name;
        }
    }

    #endregion

}