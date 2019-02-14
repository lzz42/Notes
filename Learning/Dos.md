# DOS 命令

```DOS
:: 注释
REM
set name=$(TargetName)-%Date:~0,4%%Date:~5,2%%Date:~8,2%%Time:~0,2%%Time:~3,2%.vsix
COPY $(TargetName).vsix %name%
```

- 用扩展表示方法,"%0"代表当前批处理的路径..
- 如果你的批处理a.bat放在光盘G的abc文件夹下,那么:
- %0 为 G:/abc/a.bat
- %~dp0 为 G:/abc/
- %~d0 为G:
- %~p0 为/abc/

https://github.com/zodiacon/WindowsInternals
https://docs.microsoft.com/zh-cn/sysinternals/downloads/