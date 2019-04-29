# -*- coding: UTF-8 -*-

"""
参考：
    https://pythonnet.github.io/
使用Python 调用C#动态库
1.安装pythonnet https://github.com/pythonnet/pythonnet
2.
"""

import os

import clr
from System import *
from System.Collections import *
from System import Environment


def loadAssembly():
    # clr.AddReference("System.Collections")
    # from System.Windows.Forms import Form
    drivers = Environment.GetLogicalDrives()
    if drivers is not None:
        for d in drivers:
            print(d)
    # Use Class
    from System.Drawing import Point
    p1 = Point(10,10)
    from System import String,Char,Int32
    s1 = String.Overloads[Char,Int32]('A',10)
    # s2 = String.__overloads_[__Char,Int32]('A',10)
    # Use Generics
    from System.Collections.Generic  import Dictionary
    d1 = Dictionary[String,String]()
    d2 = Dictionary[Int32,String]()
    d3 = Dictionary[String,Type]()
    d11 = Dictionary[int,str]()
    d22 = Dictionary[int,float]()
    d33 = Dictionary[int,String]()
    # Fileds and Properties
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
    AppDomain.CurrentDomain.AssemblyLoad+=d
    # 事件
    object.SomeEvent+=d
    object.SomeEvent-=d
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
    




def assembly_load_handler(source,args):
    print(source)
    print(args)
    pass



if __name__ == "__main__":
    loadAssembly()
    pass
