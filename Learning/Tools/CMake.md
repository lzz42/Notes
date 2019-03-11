# CMake工具

## CMake介绍

- 允许开发者编写一种平台无关的 CMakeList.txt 文件来定制整个编译流程，然后再根据目标用户的平台进一步生成所需的本地化 Makefile 和工程文件
- Linux下使用CMake生成MakeFile并编译流程：
  - 1.编写CMakefile.txt文件
  - 2.执行cmake [PATH]或者ccmake [PATH] 命令生成MakeFile
  - 3.使用make命令进行编译
  
***

## CMake语法

- 组成：命令 注释 空格
- 注释：以# 开始后台跟空格

```CMake
# 这里是注释
```

- 0

## 编译C/C++

- Cygwin [下载](https://cygwin.com/install.html)
- MinGw [下载](http://www.mingw.org/)