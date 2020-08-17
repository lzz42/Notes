# Python基础知识

## 函数与方法的区别 Function Method

- 参考：
  - https://segmentfault.com/a/1190000009157792
- Definition
  - Function： A series of statements which returns some value toa caller. It can also be passed zero or more arguments which may beused in the execution of the body.
  - Method：A function which is defined inside a class body. Ifcalled as an attribute of an instance of that class, the methodwill get the instance object as its first argument (which isusually called self).
- 区别：
  - Function：不需要类型，属于FunctionObject
  - Method：需要在类型内，属于PyMethodObject

## Bound Method and Unbound Method

- 区别：
  - BoundMethod：需要实例绑定，即，a.f()
  - UnboundMethod:不需要实例绑定，即：A.f(a)
  - 但都需要一个实例才能调用，两种方法本质上等价
- 定义：
  - 在类内定义方法都要显式传入self参数，self表示实例化的对象

## Python Module Index

- `__future__` :将来声明定义
- `__main__`:环境运行的顶级脚本
- `_dummy_thread`:用来替换_thread模块
- `_thread`:低级别的线程API

## 虚拟环境 virtualenv

- 安装：`pip install virtualenv`
- 创建环境：`virtual myenv`
- 进入环境：
  - `cd myenv/Scripts`
  - `activate`
- 退出环境：
  - `deactivate`


## Tutorial

### 使用Python解释器

- 调用解释器：
  - 退出解释器：quit()
  - `python -c command [arg]`:作为命令执行
  - `python -m module [arg]`：作为模块执行
- 参数传递
  - 脚本名和参数会转换为字符串列表list，在sys模块的argv变量中，即`sys.argv`
  - 标准输入：sys.argv[0]是'-'
  - -c command 时：sys.argv[0]是'-c'
  - -m module 时：sys.argv[0]是模块的全名
- 源代码编码
  - 默认编码为utf-8
  - 指定编码：必须在文件的第一行指定`# -*- coding: encoding -*-`
