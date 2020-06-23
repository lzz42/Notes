#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

using std::map;
using std::vector;

//https://www.cnblogs.com/yc_sunniwell/archive/2010/07/14/1777416.html

const int g_int_a = 10;
int cosnt g_int_b = 10;
const char &g_pchar;
const std::map g_map;

/*
1.常量
    const int _G_INT_A=10;,在编译时已知其值，不需要分配存储
    C标准中，常量是全局的，C++中视其声明位置确定其作用域
2.指针和常量
    指针本身、以及指针指向的对象
    使指针指向的对象为常量(指向一个常量的指针)：
    不能修改指针指向对象的内容，可以修改指针的内容（指向其他对象）
        const char *p_cstr1;
        char const *p_str2;
    使指针本身成为常量（指向一个对象的常指针）：
    不能修改指针指向的内容（不能指向其他对象），可以修改指针指向对象的内容
        char *const cp_str1;
    赋值约束：
        可以把非const对象的地址赋给指向const对象的指针，但不能把const对象地址赋给普通的非const对象的指针
3.const修饰函数传入参数
    提高函数效率，指定该调用参数，不能修改参数对象的值，指针参数声明为const,不能修改指针所指对象的值
    通常修饰指针参数和引用参数
    void fun(const A *in);//修饰指针参数
    void fun(const A &in);//修饰引用参数
4.const修饰函数返回值
    阻止用户修改函数返回值，应将返回值赋给一个常量或者常量指针
5.const修饰成员函数
    const对象只能访问const成员，非const对象可以访问所有成员
    const对象的成员不能修改，通过指针维护的对象可以修改
    const成员函数不能修改对象的数据，不管该对象是否具有const

*/

int main(int argc[], char **argv)
{
    int x = 1024;
    const int *m10= &x;
    int const *m11 = &x;
    int *const m20 = new int(200);
    /*
    const只对其左边的东西生效，当const在最左边时，对右边生效
    m10,m11是常量指针：即指向一个常对象的普通指针
    m20是常指针：即指向一个普通对象的常指针
    */
   *m10 = 512;//将产生错误
   *m11 = 512;//将产生错误
    x=513;//可以通过x修改
    int* n10=(int*)m10;
    *n10=514;//可以使用其他指针修改


    return 0;
}

void fun(int a,const int b,int const * cpa,const int* pca){
    a=100;//可以改
    b=100;//不能修改
    int* p =new int(200);
    cpa =p;//指针内容不能改
    *cpa=100;//指针对象可以改
    *pca = 100;//指针对象不能改
    pca = p;//指针内容可以改
}

int len(char *pchar)
{
    return 0;
}

int len_ex(const char *pchar)
{
    return 0;
}