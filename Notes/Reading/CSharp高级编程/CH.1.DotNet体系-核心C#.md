# C#高级编程

## .Net体系结构

### C#与.net

- 1.专门为.net framework设计的编程语言
- 2.面向对象设计方法的编程语言
- 3.只是一种语言

### 公共语言运行库 - CLR

- Common Language Runtime
- 1.执行编译好的源代码即IL代码
- 2.将IL代码编译为平台专用的机器码
- 平台无关性 - IL语言支持
- 语言互操作 - IL语言支持
  - VB
  - C++：托管C++（在托管C++中调用非托管C++代码时，不需要使用COM互操作）
  - COM，COM+
- 中间语言 IL
  - 1.面向对象和接口的支持
  - 2.值类型和引用类型之间的显著差异
  - 3.强数据类型化
  - 4.使用异常处理错误
  - 5.使用特性
- 运行环境提供.net应用程序所需的核心服务，主要：内存分配、清理服务
- 运行环境-公共语言基础结构CLI-Common Language Infrastructure
- 规范性：主要定义了可执行代码和运行环境的规范；
- CLR
- 公共语言运行时（Common Language Runtime）-确保应用程序符合安全规则，并为应用程序提供资源；
- 微软专用的运行环境CLR遵循标准就是CLI；
- VES
- 运行环境-Virtual Execution System
- CTS
- CLI的核心组成-通用类型系统（Common Type System），定义编程语言的类型和操作规范；
- CLS
- 公共语言规范-（Common Language Specification）-提供高级语言互操作的规范；
- Managed Code
- 托管代码-通过.net编写的程序；
- CIL
- 托管代码通过公共中间语言（Common Intermediate Language ）和文件格式进行传输和存储
- 所有的源代码语言都要编译成CIL指令集。MSIL-Microsoft实现的CIL；
- 托管数据由CLR自动分配和释放，存储在托管堆上（managed heap），通过垃圾回收机制自动释放数据。
- 托管堆（managed heap）
- 应用程序第一次启动，CLR为该应用程序预留一块内存即托管堆
- 堆：带有内存基址的一块内存区。内存区连续，存储区按线性方式分配，垃圾回收

### 程序集 assembly

> [参考](https://www.cnblogs.com/damonlan/p/3221347.html)

- 自描述的逻辑单元，可以存在多个文件中
- 可执行程序集与库代码区别：是否具有主程序入口点
- 程序集包含内容：
  - 1.Windows文件首部：程序集类型：ASP.NET 还是Winform还是控制台应用程序，如何查看windows首部：VS命令行下输入dumpbin /headers [文件名]
  - 2.CLR文件首部：.net运行程序集标识，查看：VS命令行下输入dumpbin /clrheader [文件名]
  - 3.元数据：
  - 4.程序集清单：
  - 5.内嵌资源：
- 私有程序集
  - 可以通过应用程序配置文件指定查找私有程序集的路径

  ```XML
  <?xml version="1.0" encoding="utf-8" ?>
  <configuration>
    <runtime>
      <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
        <probing privatePath="MyAllLibraries" />
      </assemblyBinding>
    </runtime>
  </configuration>
  ```

- 共享程序集
  - 供机器上其他程序集使用
  - 一般按照在GAC（Global Assembly Cache）路径：windows\assembly
  - 对于程序集需要解决的问题：
    - 1.名称冲突：类型名称冲突问题；
    - 2.程序集被同一个程序集不同版本覆盖；
  - 解决：
    - 1.对于名称冲突：使用强名称strong name，保证唯一性
    - 2.覆盖问题：程序集清单中指定版本信息：
  - 强名称：
    - 1.如何生存强名称？
      - a.生成强命名文件 *.snk：使用sn.exe工具：sn -k [mingc].snk
      - b.将snk文件放入程序中：AssemblyInfo.cs中添加特性：`[assembly:AssemblyKeyFile("{snk文件路径}")]`
      - c.安装强名称的程序集到GACgacutil.exe工具`gacutil.exe -i`,卸载`gacutil.exe -u`,查看`gacutil.exe -l`  

## 核心C\#

- 变量声明
- 预定于数据类型
  - 值类型：
    - 枚举
    - 内置值类型
    - 用户定义值类型
  - 引用类型
    - 指针
    - 接口
    - 自描述类型：
      - 数组
      - 类类型
        - 委托
        - 装箱的值类型
        - 用户定义的类