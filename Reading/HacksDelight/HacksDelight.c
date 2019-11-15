#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void PrintInt(int x, int y)
{
    char s[32];
    char s2[32];
    itoa(x, s, 2);
    itoa(y, s2, 2);
    printf("\n%s\n%s\n", s, s2);
}

void Chapter_Two_Basic()
{
    int x = 0b01011000;
    int y = 0;
    y = x & (x - 1); 
    // 将最右侧的1位改为0
    PrintInt(x, y);
    x = 0b01001100;
    y = x & (x + 1); //检测是否为2^n - 1形式
    PrintInt(x, y);
    x = 0b01011000;
    y = x & (-x);//析出最右侧1位
    PrintInt(x, y);
    y = ~x & (x + 1);//析出最右侧0位
    PrintInt(x, y);
}

void main()
{
    printf("Hack's Delight Experiment.\n");
    Chapter_Two_Basic();
}