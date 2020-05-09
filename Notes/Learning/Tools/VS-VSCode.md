# 关于Visual Studio and VSCode

## Visual Studio

## 常见问题

- 1.关于代码引用提示信息不显示问题，不显示类、属性、方法引用计数、测试信息等？
  > 解决：工具->选项->文本编辑器->所有语言->CodeLens,点开后选择“启用CodeLens”;
- 2.MSTest单元测试运行前异常，非代码异常？
  > 检测单元测试工程是否安装“MSTest.TestAdapter”包，若没有安装则安装该包；

## 常用快捷键

- 代码编辑：
  - 1.代码展开\折叠：Ctrl+M+M
  - 2.代码上下移动行：Alt+(上键)，Alt+(下键)
  - 3.注释：Ctrl+/,取消注释：Shift+Ctrl+/
  - 4.提示完成或者纠正错误或者全部修改:Alt+Enter
  - 5.查找方法属性：`Alt+\`
  - 附加到进程：Ctrl+Alt+P
  - 启动调试：F5
  - 直接启动不调试:Ctrl+F5
  - 生成解决方案:Ctrl+Shift+B
  - 取消生成:Ctrl+Break
  - 转到定义：F12
  - 查找帮助：F1
  - 查找所有引用：Shift+F12
- csproj文件禁用版本确定性错误：
  - 编辑csproj文件 去掉属性  `<Deterministic>true</Deterministic>`
  - 或改为`<Deterministic>false</Deterministic>`

## VSCode

### 通用

- 快捷键：
- 打开终端：Ctrl+`
- 拆分分组：Ctrl+\
- 选择拆分的分组：Ctrl+[数字]
- 切换编辑器：Ctrl+PageDown/PageUp
- 进入/退出禅模式：Shift+Alt+Enter
- 选择语言模式：Ctrl+k,M
- 打开命名面板：Ctrl+Shift+P

### C++

- [](https://blog.csdn.net/c_duoduo/article/details/51615381)
- [](https://blog.csdn.net/LK274857347/article/details/83068498)
- [](https://www.cnblogs.com/qcssmd/p/5302052.html)
- http://prdownloads.sourceforge.net/mingw/gcc-core-6.3.0-1-mingw32-bin.tar.xz?download
- http://tdm-gcc.tdragon.net/download
