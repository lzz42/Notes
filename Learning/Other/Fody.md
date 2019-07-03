# Fody

## 介绍

- Fody:用于将C#程序引用的多个动态库压缩到原引用的Exe或DLL中，而不影响使用，即绿色版；

## Costura.Fody构建内置程序集的程序或者类库

### 使用Costura.Fody

- 1.VS工程添加Nuget包：Costura.Fody -v 4.0.0(对于Coret:dotnet add DotNetCore package Costura.Fody -v 4.0.0)
- 2.工程资源中引用FodyWeavers.xml,将该文件设置为：生成操作-内容，不复制本地；
- 3.编辑FodyWeavers.xml 添加节点：`<Costura />`
- 4.将引用的DLL设置为复制到本地；
- 5.生成工程即可，将DLL作为压缩的资源文件嵌入Exe中；

```DOS
PM> Install-Package Fody
PM> Install-Package Costura.Fody
```

### FodyWeavers.xml说明

- 根节点 - Weavers
  - 子节点 - Costura
    - CreateTemporaryAssemblies - 默认false，是否在嵌入文件加载入内存前，将其复制到磁盘，帮助用于期待重物理文件加载的的程序集
    - IncludeDebugSymbols - 默认true，控制引用的程序集的pdb文件是否嵌入
    - DisableCleanup - 默认false，嵌入程序集不再作为构建的一部分
    - DisableCompression - 默认false，是否不压缩
    - LoadAtModuleInit - 默认True，Costura会作为模块初始化的一部分进行加载，设置为False则可以禁止该行为，通过`CosturaUtility.Initialize()`在代码中主动调用初始化
    - IgnoreSatelliteAssemblies - 默认false，Costura默认将程序集作为外围资源并且预置到输出路径下
    - ExcludeAssemblies - 程序集名称的集合，用于排除到嵌入所有复制到本地的引用，不含`.exe OR .dll`,不能包含在`IncludeAssemblies`,可以使用通配符`*`且只能在结尾；可以作为节点（作为节点时，用换行分隔多个程序集名）或属性（作为属性时用`|`分隔多个程序集名）
    - IncludeAssemblies - 包含的作为嵌入程序集的名称集合，规则同`ExcludeAssemblies`,
      - 注：1.只能包括工程中引用的程序集；2.指定引用程序集后，未指定的程序集将不会嵌入主程序或主类库（代替原默认模式）；
    - Unmanaged32Assemblies & Unmanaged64Assemblies - 混合模式的程序集不能与托管程序集使用相关方式加载，因此需要帮助Costura区分混合模式，在什么模式（x86,x64）加载他们，规则同`ExcludeAssemblies`
    - PreloadOrder -  Native Libraries 要包含本地类库 需要在工程中添加名为`costura32` or`costura64`（具体哪个取决于类库）的文件夹作为嵌入的资源，使用`PreloadOrder`指定预加载的程序集，规则同`ExcludeAssemblies`
    - CosturaUtility -  一个类，用于手动代码初始化Costura，主要应用于模块初始化不生效的情况，程序集和Mono `CosturaUtility.Initialize()`

```XML
<!-- 文件名:FodyWeavers.xml -->
<Weavers xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:noNamespaceSchemaLocation="FodyWeavers.xsd">
  <Costura DisableCompression="true" CreateTemporaryAssemblies="true" IncludeDebugSymbols="true" DisableCleanup="true" LoadAtModuleInit="false" >
    <ExcludeAssemblies>
        排除的程序集1
        排除的程序集2
    </ExcludeAssemblies>
    <IncludeAssemblies>
        包含的程序集1
        包含的程序集2
    </IncludeAssemblies>
    <IgnoreSatelliteAssemblies>
        忽略的程序集1
        忽略的程序集2
    </IgnoreSatelliteAssemblies>
    <Unmanaged32Assemblies>
        32位的程序集1
        32位的程序集2
    </Unmanaged32Assemblies>
    <Unmanaged64Assemblies>
        64位的程序集1
        64位的程序集2
    </Unmanaged64Assemblies>
    <PreloadOrder>
        预加载的程序集1
        预加载的程序集2
    </PreloadOrder>
  </Costura>
</Weavers>
```

## 使用Fody进行AOP - 属性 方法拦截

### 介绍

- 什么是AOP？
  - Aspect Oriented Programming ： 面向切片编程

## 参考资料

- https://github.com/Fody/Costura
- http://einaregilsson.com/module-initializers-in-csharp/
- https://www.nuget.org/packages/InjectModuleInitializer/
- dotnet add package InjectModuleInitializer --version 2.0.3