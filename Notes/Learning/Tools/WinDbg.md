# WinDbg

## 下载

- [Windbg相关资料](http://www.windbg.org/)
- [微软下载地址](https://docs.microsoft.com/zh-cn/windows-hardware/drivers/debugger/debugger-download-tools)
- https://docs.microsoft.com/zh-cn/windows-hardware/drivers/download-the-wdk

## 符号下载

- 设置符号文件路径：
- 命令：

> .symfix [绝对路径]
> EG：
> .symfix d:\symbolsCache


## 扩展符号


## 常见问题

一：WinDBG分X86和X64两个版本
　　如果你用的是32位的WinDBG，那直接打开就行；你如果用的是64位的版本，那么如果调试64位代码也直接打开，如果调试x86的代码，要使用Wow64下的WinDBG.exe。

二：确定SOS和CLR的位置和版本
　　如果安装了Visual Studio的机器，可以打开VS的命令行，输入where sos.dll命令，可以找到sos.dll的全路径（需要说明的是，找到的不一定是全部的文件）。它的一般位置在C:\Windows\Microsoft.NET\Framework?\version?\SOS.dll。其中Framework?包括Framework和Framework64两个版本；version?包括v2.0.50727，v3.0，v3.5和v4.0.30319等版本。文件确切路径的选择依据要调试程序的版本而定，一般为C:\Windows\Microsoft.NET\Framework\v4.0.30319\SOS.dll，CLR为同一目录下的CLR.dll文件。

三：加载SOS和CLR

　　使用命令.load C:\Windows\Microsoft.NET\Framework\v4.0.30319\SOS.dll可以加载成功。
如果失败，特别是出现The call to LoadLibrary(C:\Windows\Microsoft.NET\Framework\v4.0.30319\sos.dll) failed, Win32 error 0n193这样的错误，请确认加载sos.dll的版本是否正确。
　　此外，加载不出错，并不见得可以直接使用。可以尝试命令.loadby sos clr。如果命令成功，那么测试环境好了。如果出现了“Unable to find module 'clr'”这样的错误。请键入g让调试程序运行一会儿，停下来的时候再尝试命令.loadby sos clr，这时一般都会成功。
