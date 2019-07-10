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
	cout << "HelloWorld!" << endl;
}

#region 参数实验
//传值调用
void Swap_Value(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	return;
}
//引用调用
void Swap_Ref(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	return;
}
//指针调用
void Swap_Point(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	return;
}

void TestMethodCall()
{
	int a = 10, b = 20;
	int a1 = 10, b1 = 20;
	int a2 = 10, b2 = 20;
	printf("A:%d,B:%d\n", a, b);
	printf("Call Swap_Value\n");
	Swap_Value(a, b);
	printf("A:%d,B:%d\n", a, b);
	printf("A1:%d,B1:%d\n", a1, b1);
	printf("Call Swap_Ref\n");
	Swap_Ref(a1, a1);
	printf("A1:%d,B1:%d\n", a1, b1);
	printf("A2:%d,B2:%d\n", a2, b2);
	printf("Call Swap_Point\n");
	Swap_Point(&a2, &b2);
	printf("A2:%d,B2:%d\n", a2, b2);
}

#endregion

void DateAndTime_Pratice()
{
	//获取当前系统时间
	time_t now = time(0);
	//获取时间字符串
	char *ptStr = ctime(&now);
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