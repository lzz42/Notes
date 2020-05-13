# DOS 命令

## 基本语法

- EG：

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

## 常用命令

- 查看某个变量是否存在或者查看已存在变量的路径
- where [CMD]

## 常用命令

- copy

```Text
将一份或多份文件复制到另一个位置。
COPY [/D] [/V] [/N] [/Y | /-Y] [/Z] [/L] [/A | /B ] source [/A | /B]
     [+ source [/A | /B] [+ ...]] [destination [/A | /B]]
  source       指定要复制的文件。
  /A           表示一个 ASCII 文本文件。
  /B           表示一个二进位文件。
  /D           允许解密要创建的目标文件
  destination  为新文件指定目录和/或文件名。
  /V           验证新文件写入是否正确。
  /N           复制带有非 8dot3 名称的文件时，尽可能使用短文件名。
  /Y           不使用确认是否要覆盖现有目标文件的提示。
  /-Y          使用确认是否要覆盖现有目标文件的提示。
  /Z           用可重新启动模式复制已联网的文件。
  /L           如果源是符号链接，请将链接复制到目标而不是源链接指向的实际文件。
```

- 1.单个文件复制
  - copy D:\1.txt E:\
  - copy D:\1.txt E:\2.txt
  - copy .\dir
- 2.批量复制
  - copy D:\dir E:\dir
  - copy D:\dir\*.txt E:\dir /y
- 3.合并文件
  - copy /b D:\1.txt D:\2.txt E:\11.txt
  - copy /b D:\1.txt D:\2.txt

- xcopy

```Text
复制文件和目录树。
XCOPY source [destination] [/A | /M] [/D[:date]] [/P] [/S [/E]] [/V] [/W]
                           [/C] [/I] [/Q] [/F] [/L] [/G] [/H] [/R] [/T] [/U]
                           [/K] [/N] [/O] [/X] [/Y] [/-Y] [/Z] [/B] [/J]
                           [/EXCLUDE:file1[+file2][+file3]...]
  source       指定要复制的文件。
  destination  指定新文件的位置和/或名称。
  /A           仅复制有存档属性集的文件，但不更改属性。
  /M           仅复制有存档属性集的文件，并关闭存档属性。
  /D:m-d-y     复制在指定日期或指定日期以后更改的文件。如果没有提供日期，只复制那些源时间比目标时间新的文件。
  /EXCLUDE:file1[+file2][+file3]...
               指定含有字符串的文件列表。每个字符串在文件中应位于单独的一行。如果任何字符串与复制文件的绝对路径的任何部分相符，则排除复制该文件。
               例如，指定如 \obj\ 或 .obj 的字符串会分别排除目录 obj 下面的所有文件或带有.obj 扩展名的所有文件。
  /P           创建每个目标文件之前提示你。
  /S           复制目录和子目录，不包括空目录。
  /E           复制目录和子目录，包括空目录。与 /S /E 相同。可以用来修改 /T。
  /V           验证每个新文件的大小。
  /W           提示你在复制前按键。
  /C           即使有错误，也继续复制。
  /I           如果目标不存在，且要复制多个文件，则假定目标必须是目录。
  /Q           复制时不显示文件名。
  /F           复制时显示完整的源文件名和目标文件名。
  /L           显示要复制的文件。
  /G           允许将加密文件复制到不支持加密的目标。
  /H           也复制隐藏文件和系统文件。
  /R           覆盖只读文件。
  /T           创建目录结构，但不复制文件。不包括空目录或子目录。/T /E 包括空目录和子目录。
  /U           只复制已经存在于目标中的文件。
  /K           复制属性。一般的 Xcopy 会重置只读属性。
  /N           用生成的短名称复制。
  /O           复制文件所有权和 ACL 信息。
  /X           复制文件审核设置(隐含 /O)。
  /Y           取消提示以确认要覆盖现有目标文件。
  /-Y          要提示以确认要覆盖现有目标文件。
  /Z           在可重新启动模式下复制网络文件。
  /B           复制符号链接本身与链接目标。
  /J           复制时不使用缓冲的 I/O。推荐复制大文件时使用。
```

- mkdir

```Text
创建目录。
MKDIR [drive:]path
MD [drive:]path
如果命令扩展被启用，MKDIR 会如下改变:
如果需要，MKDIR 会在路径中创建中级目录。例如: 假设 \a 不
存在，那么:
    mkdir \a\b\c\d
与:
    mkdir \a
    chdir \a
    mkdir b
    chdir b
    mkdir c
    chdir c
    mkdir d
相同。如果扩展被停用，则需要键入 mkdir \a\b\c\d。
```

https://github.com/zodiacon/WindowsInternals
https://docs.microsoft.com/zh-cn/sysinternals/downloads/