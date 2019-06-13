using System;

namespace DotNetCore
{
    public class Py_Call : ICall
    {
        public int Add(int a, int b)
        {
            return a + b;
        }
        public int Subtract(int a, int b)
        {
            return a - b;
        }
        public int Multiply(int a, int b)
        {
            return a * b;
        }
        public float Divide(int a, int b)
        {
            System.Diagnostics.Contracts.Contract.Requires(b != 0);
            return a / b;
        }
        public int Mod(int m, int n)
        {
            return m % n;
        }
        public int Pow(int m, int n)
        {
            int sum = 1;
            int tmp = m;
            int nt = n;
            while (nt != 0)
            {
                if ((nt & 1) == 1)
                {
                    sum *= tmp;
                }
                tmp *= tmp;
                nt = nt >> 1;
            }
            return sum;
        }
        public void Swap(ref int m, ref int n)
        {
            m ^= n;
            m ^= n;
            n ^= n;
        }
    }
}
