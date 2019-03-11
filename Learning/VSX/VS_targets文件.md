# Targets文件

## 说明 预定义targets文件说明

- MSBuild包括几个targets文件，这些文件包括：items，properties，targets，tasks等通用的脚本
- 用途：用于定义工程的构建过程
- 例如：C#工程会导入Microsoft.CSharp.targets,该targets文件会导入Microsoft.Common.targets，
- C#工程会自己定义工程的项和属性，但是C#工程的标准构建规则是通过targets文件导入的
- $(MSBuildToolsPath)值指定了那些通用targets文件的路径，若ToolVersion是4.0，文件位置在<WindowsInstallationPath>\Microsoft.NET\Framework\V4.0.30319\
- 通用targets文件
  > Microsoft.Common.targets:定义C#和VB工程的标准构建过程，被Microsoft.CSharp.targets和Microsoft.VisualBasic.targets文件导入，通过**<Import Project="Microsoft.Common.targets" />**声明导入；
  > Microsoft.CSharp.targets:定义C#工程的标准构建过程，导入声明：<Import Project="$(MSBuildToolsPath)\Microsoft.CSharp.targets" \>
  > Microsoft.VisualBasic.targets:定义VB工程的标准构建过程，导入声明：<Import Project="$(MSBuildToolsPath)\Microsoft.VisualBasic.targets" \>
- Directory.Build.targets
  > 用户定义文件，提供工程的自定义项，由Common自动导入，可以设置属性ImportDirectoryBuildTargets 为false禁止导入；

## 在Project文件中声明Targets

- Target通过特定的顺序将多个任务组织到一起，将工程构建过程包含仅更小的单元中

### Targets定义

- 使用Target 元素，target可以被重新定义，使用时，仅使用最后定义的targets
- Eg:使用Compile项类型调用Csc任务；

```XML
<Target Name="Construct">  
    <Csc Sources="@(Compile)" />  
</Target>  
```

### Target构建顺序

- InitialTargets>[CommandTargets]>DefaultTargets>[FirstTarget]>TargetDepends
  > 1.若定义InitialTargets则首先运行InitialTargets；
  > 2.若使用命令行指定Targets则运行该指定Targets而不运行DefaultTargets;
  > 3.若未使用命令行指定Target,且定义了DefaultTargets，则运行DefaultTargets
  > 4.若即未使用命令行指定Targets又未定义DefaultTargets，则运行遇到的第一个Targets
  > 5.对于每个Targets将会对Condition属性进行计算，若计算值为false，则不会运行该Target也不会对后续构建产生影响
  > 6.对于一个要运行的Targets前，会首先运行DependsOnTargets属性指定的依赖Targets列表
  > 7.对于一个要运行的Targets前，会首先运行BeforeTargets属性指定的依赖Targets列表
  > 7.对于一个要运行的Targets前，会首先比较Inputs属性和Outputs属性，若根据输出文件是否相比于输入文件过期，则执行该Target，否则跳过该Target；
  > 8.运行完或者跳过Targets后，开始运行AfterTargets；

- 指定Targets运行顺序方法，可以使用以下特性指定Targets运行顺序
- InitialTargets:在Project节点下 定义的属性会第一运行，即使有在命令行和DefaultTargets下定义的Targets,该值可以使用分号分割的有序的多个Targets

```XML
<Project InitialTargets="Warm;Eject" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
```

- DefaultTargets:若未在命令行上显示指定Targets则先运行InitialTargets，然后运行DefaultTargets，命令行中可以使用/target:[target01];[target02]指定target替代默认的Default目标

```XML
<Project DefaultTargets="Warm;Eject" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
```

- DependsOnTargets:在Target节点上可以定义依赖的targets,先运行依赖Targets然后运行宿主Targets
- BeforeTargets and AfterTargets:在MSBuild4.0中可以在Targets中定义 BeforeTargets AfterTargets
- Eg:Main target中运行顺序：Da Db Ba Bb Aa Ab Main

```XML
<Target Name="Main" DependsOnTargets="Da;Db" BeforeTargets="Ba;Bb" AfterTargets="Aa;Ab" >  
    <Csc Sources="@(Compile)" />  
</Target>
```

## Targets文件结构说明

## 参考文件

- [MSBuild .targets files](https://docs.microsoft.com/zh-cn/visualstudio/msbuild/msbuild-dot-targets-files?view=vs-2017)

- [MSBuild 目标](https://docs.microsoft.com/zh-cn/visualstudio/msbuild/msbuild-targets?view=vs-2017)