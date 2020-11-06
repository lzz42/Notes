# PDB文件解析

## 参考资料

- https://www.jianshu.com/p/7ad20a047bb4
- https://docs.microsoft.com/en-us/windows/win32/dxtecharts/debugging-with-symbols
- https://www.cnblogs.com/itech/archive/2011/08/15/2136522.html
- https://www.aldeid.com/wiki/PEView
- https://archive.codeplex.com/?p=ccimetadata
- https://docs.microsoft.com/zh-cn/windows/win32/debug/debug-help-library

## 使用符号进行调试

- https://docs.microsoft.com/en-us/windows/win32/dxtecharts/debugging-with-symbols
- 符号文件的来源
符号文件的种类：CodeView符号、COFF、DBG、SYM、PDB 以及二进制可执行文件的导出符号
这里仅讨论VS.Net和PDB格式的符号，他们通过VS编译工程时产生<br>
对于可执行文件产生符号文件与不产生符号文件的区别：<br>
产生符号文件时：PDB文件的路径文件名会嵌入到可执行文件中
产生符号文件的编译器开关`/Zi or /Zl`,配合`/DEBUG`<br>
默认情况下，符号文件包含以下内容：<br>
  - 公共符号（所有的函数、静态和全局变量）
  - 可执行代码相关的对象文件清单
  - FPO - 帧指针优化信息
  - 本地变量和数据结构的命令空间和类型信息
  - 源文件和行号信息
可以使用链接器选项：`/PDBSTRIPPED:filename`来去掉PDB文件的产生，针对已有文件可以使用工具：pdbcopy来去掉私人信息<br>
默认情况下，去掉私人信息的PDB包含以下内容:<br>
  - 公共符号（所有的函数、静态和全局变量）
  - FPO - 帧指针优化信息
  - 可执行代码相关的对象文件清单
这是允许调试是最小信息
- 使用符号调试
1.未加载符合或者符合丢失情况下，调试的堆栈不可信
2.FPO指定和保存了调试关键的调用堆栈信息
- 获取所需的符号
调试器搜索符号的路径：<br>
对于Visual Studio 可以设置：工具-选项-调试-符号，中配置符号文件路径<br>
系统环境变量：`_NT_SYMBOL_PATH`<br>
调试器搜索匹配的PDB位置：<br>
  - DLL或者可执行文件内部(默认情况下，链接器会将PDB文件的全路径以及文件名内置到DLL或者Exe中)
  - DLL或者EXE的用一目录下
  - 所有的本地符号缓存文件夹
  - 所有的本地网络文件符号服务器
  - 所有的互联网符号服务器
如何检测和验证符号？<br>
使用 symchk.exe (内置在Windows Kits)<br>

## 崩溃dump分析

- https://docs.microsoft.com/zh-cn/windows/win32/dxtecharts/crash-dump-analysis