#include <stdio.h>
#include <cmath>
#include <ctime>

//定义常量
#define FlOAT_PI = 3.15159f;
//定义常量
extern const float INT_PI = 3.1415;
//定义全局变量
extern float INT_E = 2.71828;

enum WeekType;

int main(int arg, char *args)
{
    //单行注释
    /*多行注释
    多行注释
    多行注释*/
    cout<<"HelloWorld!"<<endl;
}

#region 参数实验

void ParamTest()
{
	int a1 = 10, b1 = 20;
	int a2 = 10, b2 = 20;
	int a3 = 10, b3 = 20;
	printf("a1:%d,b1:%d\n", a1, b1);
	Swap1(a1, b1);
	printf("a1:%d,b1:%d\n", a1, b1);
	printf("a2:%d,b2:%d\n", a2, b2);
	Swap2(&a2, &b2);
	printf("a2:%d,b2:%d\n", a2, b2);
	printf("a3:%d,b3:%d\n", a3, b3);
	Swap3(a3, b3);
	printf("a3:%d,b3:%d\n", a3, b3);
}

void Swap1(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void Swap2(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void Swap3(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

#endregion

void DateAndTime_Pratice()
{
    //获取当前系统时间
    time_t now = time(0);
    //获取时间字符串
    char *ptStr=ctime(&now);
    //获取tm结构指针
    tm *ptm = gmtime(&now);

}

//定义枚举
enum WeekType
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};