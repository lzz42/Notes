# CLR via C\#

## 3常量和字段

- 7.1  常量
  - 常量值必须在编译时能确定，编译器将常量值保存在程序集元数据中（只能使用基元类型定义常量）
  - 基元类型：Boolean,Char,Byte,SByte,Int16,Int32,Int64,UInt16,UInt32,UInt64,Single,Double,Decimal,String
  - 或者非基元类型，值为null
  - 常量被视为静态成员，定义常量将创建元数据
  - 编译器会直接将常量值嵌入程序集的IL代码，不为常量分配内存，不能获取常量地址，不能传递引用方式传递
  - 所以运行时从一个程序集中提取另一个程序集中的常量，应该使用readonly字段
  - 7.2 字段
  - 修饰词：
  - static（static） Instance（默认）
  - InitOnly（readonly） 只能由构造器方法中写入（可以用反射修改readonly值）
  - Volatile（volatile） 不执行线程不安全的优化，只能使用以下类型：引用类型，值类型基元类型，基础类型为基元值类型的枚举类型
  - 字段何时分配内存？
  - 字段存储在动态内存中，仅能在运行时获取
  - 类型字段（静态字段） - 在类型对象中分配，类型对象在类型加载到第一个AppDomain时创建，
  - 加载时间：引用了该类型的任何方法时首次进行JIT编译时；
  - 实例字段    -   构造类型的一个实例时分配
  - 内联初始化：代码中直接赋值来初始化
  - 当引用类型标记为readonly时，不可修改的是引用，并非字段引用的对象

## 方法

- 8.1 实例构造器和类 - 引用类型
- 构造器 constructor
- 方法定义元数据表：.ctor
- 创建引用类型实例过程：
  - 1.为实例的数据字段分配内存（内存归0）；
  - 2.初始化对象的附加字段，即类型对象指针/同步块索引；
  - 3.调用类型的实例构造器；
- 若修饰符为abstract，则可访问性为protected
- 若修饰符为static，编译器不会在类定义中生成默认构造器
- 特殊情况：可以在不调用类型构造器时创建一个类型实例
- A.Object.MemberwiseClone()
  - 1.分配内存；
  - 2.初始化对象附加字段；
  - 3.将源对象的字节数复制到新对象中；
- B.使用运行时反序列化器反序列话对象；
  - 反序列化使用：System.Runtime.Serialization.FormatterServices的
  - GetUninitializedObject或者GetSafeUninitializedObject分配内存；

## 其他：

- 线程基础
  - 线程对CPU进行虚拟化
  - 线程开销
  - 组成：
    - 1、线程内核对象Thread kernel object 一个数据结构：线程属性描述；线程上下文（包含CPU寄存器集合，在x86上使用约700byte，x64约1240byte，IA64约2500byte）；
    - 2.线程环境块 thread environment block TEB，用户模式下的内存块，消耗一个内存页x86和x64为4K，IA64为8K包含：1.异常处理链首；2.线程本地数据；3.GDI和OpenGL的数据结构；
    - 3.用户模式栈 user-mode stack ：存储传递给方法的局部变量和实参，以及方法返回的地址，默认情况分配1MB内存，
    - 4.内核模式栈 kernel-mode stack：x86为12K，x64为24K
    - 5.DLL线程链接和线程分离通知 attach detach：在线程创建时，会调用进程中加载的所有DLL的DllMain方法，并传递标识DLL_THREAD_ATTACH和DLL_THREAD_DETACH
    - 6.上下文切换：将当期CPU寄存器值保存到当期线程内核对象的上下文结构；选择可调度的线程运行，若不同进程需要切换虚拟地址空间；将新线程上下文加载到CPU；windows每30ms进行一次上下文切换；
    - 7.执行垃圾回收，会挂起所有线程；