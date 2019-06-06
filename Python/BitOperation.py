# -*- coding:utf-8 -*-

# https://mp.weixin.qq.com/s/C6o6T9ju34vAxNBg5zobWw

import math
import os


def JudgeEvenOrOddNumber(num):
    if num % 2 == 1:
        print("{0} is Odd.".format(num))
    else:
        print("{0} is Even.".format(num))
    if num & 1 == 1:
        print("{0} is Odd.".format(num))
    else:
        print("{0} is Even.".format(num))
    pass


def SwapTwoNumber(x, y):
    print("Before Swap X:{0},Y:{1}.".format(x, y))
    # Triditional Method
    temp = x
    x = y
    y = temp
    print("After Swap X:{0},Y:{1}.".format(x, y))
    # Use Bit Operation
    x = x ^ y
    y = x ^ y
    x = x ^ y
    print("After Swap X:{0},Y:{1}.".format(x, y))
    pass


def FindNoRepeatNumber(arr):
    # X ^ X = 0
    a = 0
    i = 0
    while i < len(arr):
        a = a ^ arr[i]
        i+=1
    print("Not Repeat Number is {0}.".format(a))
    pass

def Pow(m,n):
    # m^n
    i = 0
    r = 0
    while i < n:
        r = r * m
        i+=1
    print("{0}^{1} is {2}.".format(m,n,r))
    #  
    pass

if __name__ == "__main__":
    pass
