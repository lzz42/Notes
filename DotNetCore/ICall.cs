using System;
namespace DotNetCore
{
    public interface ICall
    {
        int Add(int a,int b);
        int Subtract(int a,int b);
        int Multiply(int a,int b);
        float Divide(int a,int b);
        int Mod(int m,int n);
        int Pow(int m,int n);
        void Swap(ref int m,ref int n);
    }
}