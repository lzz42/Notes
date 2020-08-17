# -*- coding: UTF-8 -*-

"""
参考：
    https://pythonnet.github.io/
使用Python 调用C#动态库
1.安装pythonnet https://github.com/pythonnet/pythonnet python -m pip install pythonnet
2.导入clr以及相关命名空间
3.导入第三方DLL  clr.FindAssembly([dll file])
4.添加dll路径 sys.path.append(DLL_Path)
5.添加dll命名空间 clr.AddReference([name space name])
6.使用C#内的自定义类
"""

import os
import re
import time
import sys
import clr
from System import *
from System import Environment
from System import Windows
from System.Collections import *
from System.Windows import Forms
from System.Drawing import *

def loadAssembly():
    # clr.AddReference("System.Collections")
    # from System.Windows.Forms import Form
    drivers = Environment.GetLogicalDrives()
    if drivers is not None:
        for d in drivers:
            print(d)
    # Use Class
    from System.Drawing import Point
    p1 = Point(10, 10)
    from System import String, Char, Int32
    s1 = String.Overloads[Char, Int32]('A', 10)
    # s2 = String.__overloads_[__Char,Int32]('A',10)
    # Use Generics
    from System.Collections.Generic import Dictionary
    d1 = Dictionary[String, String]()
    d2 = Dictionary[Int32, String]()
    d3 = Dictionary[String, Type]()
    d11 = Dictionary[int, str]()
    d22 = Dictionary[int, float]()
    d33 = Dictionary[int, String]()
    # Use Fileds and Properties
    name = Environment.MachineName
    print(name)
    Environment.ExitCode = 1
    # Use Indexers
    hTable = Hashtable()
    hTable['ok'] = 'fine'
    # Useing Method
    drives = Environment.GetLogicalDrives()
    print(drives)
    # Warning:当一个类的静态方法和实例方法完全相同时，CLR不知道哪个方法被调用，将总是调用静态方法
    # Overloaded and Generic Methods 重载方法和泛型方法
    from System import Console
    Console.WriteLine.Overloads[bool](true)
    Console.WriteLine.Overloads[str]("true")
    Console.WriteLine.__overloads[__int](42)
    someobject.SomeGenericMethod[int](10)
    someobject.SomeGenericMethod[str]("10")
    # Delegate and Events 委托和事件
    d = AssemblyLoadEventHandler(assembly_load_handler)
    AppDomain.CurrentDomain.AssemblyLoad += d
    # 订阅事件
    object.SomeEvent += d
    object.SomeEvent -= d
    # fire events
    object.SomentEvent()
    # 异常捕获
    from System import NullReferenceException
    try:
        raise NullReferenceException('NULL')
    except NullReferenceException as e:
        print(e.Source)
        print(e.Message)
        pass


def assembly_load_handler(source, args):
    print(source)
    print(args)
    pass


# def assembly_call_button():
#     # 导入Button命名空间
#     from System import Windows
#     from System.Windows import Forms
#     file = DLL_Path + "\\" + DLL_Name
#     print(file)
#     clr.FindAssembly(file)
#     sys.path.append(DLL_Path)  # 加载c#dll文件路径
#     clr.AddReference("TestAutoIt")
#     from TestAutoIt import *
#     btn = ControlTest.GetControl()
#     btn.PerformClick()
#     pass

def demonstrate_invoke_csharp():
    # 指定DLL路径
    sys.path.append('D:\\test\\bin')
    # 查找并加载DLL
    clr.FindAssembly('text.dll')
    # 添加引用
    clr.AddReference('text')
    # 导入类
    from text import tClass
    # ------------------
    # 函数调用演示 out参数
    str=""
    ret = tClass.GetLastError(str)
    # 返回值：0无错误 非0有错误
    print(ret[0])
    # out参数值 错误信息
    print(ret[1])
    # str不变
    print(str)
    # ------------------
    # 函数调用演示 默认值参数
    ret = tClass.IsConnected(2000)
    print(ret)
    ret = tClass.IsConnected()
    print(ret)
    # -----------------
    pass

if __name__ == "__main__":
    # assembly_call_button()
    demonstrate_invoke_csharp()
    pass
