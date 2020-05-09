# MS VSX doc

- VS2017 SDK

## 参考资料

- [X]:(http://dotneteers.net/blogs/tags/VSX/default.aspx)
- https://blog.csdn.net/liuruxin/article/details/18258749

## EnvDTE接口说明

> [EnvDTE]:(https://docs.microsoft.com/zh-cn/dotnet/api/?redirectedfrom=MSDN&view=visualstudiosdk-2017)

### 接口DTE

- DLL:EnvDTE.dll
- NP:EnvDTE
- VS顶级自动化对象模型
- 获取对象实例：GetService<typeof(DTE)>
  
### 接口IVsSolutionEvents

- Dll:Microsoft.VisualStudio.Shell.Interop.dll
- NP:Microsoft.VisualStudio.Shell.Interop
- 监听解决方案通知的接口，用于追踪解决方案或者解决方案的工程的打开，关闭，加载，卸载事件
- 解决方案和项的，打开，关闭，加载，卸载有本质的不同
- 使用 查询SVsSolution对象为IVsSolution接口，调用AdviseSolutionEvents方法，返回一个指向IVsSolutionEvents的指针；

```C#
    //服务提供者
    IServiceProvider provider;// = Instance of Implement to Package(一般为一个package示例)
    //获取IVsSolution接口示例
    IVsSolution solution = provider.GetService(typeof(SVsSolution));
    //
    solution.AdviseSolutionEvents(ptr_IVsSolution,out uint)
```

### 接口IVsHierarchy

- Dll:Microsoft.VisualStudio.Shell.Interop.dll
- NP:Microsoft.VisualStudio.Shell.Interop
- 提供VSPackages的层次管理的工程层次的实现
- 层次节点的通用接口，每个节点都包含根节点，有专用的属性与之关联。层次结构对象的每个节点用一个VSITEMID标识。标识对于本接口可见，而且是一个典型的指针，指向被层次派生类的私有数据
- VSITEMID 是一个dword类型的唯一标识
- 要获得Project，需要调用GetProperty(uint32,int,object)方法
- 即GetProperty(VSConstants.VSITEMID_ROOT,VSHPROPID_ExtObject,out object)

### 接口Soulutio

- DLL:EnvDTE.dll
- NP:EnvDTE
- 在IDE内提供所有的工程以及解决方案维度的属性

### 接口Project

- DLL:EnvDTE.dll
- NP:EnvDTE
- 通用工程对象
- 特定的工程对象在其他程序集内， VB和VC#在VSLangProj命名空间
- 类似于抽象类型，提供所有其他具体工程的通用信息

### 接口VSProject

- DLL:VSLangProj
- NP:VSLangProj.dll
- 包含VB或者VC#工程的特定信息，可以从Project.Object强转，若该Object是VSProject类型

### 接口Reference

- DLL:VSLangProj
- NP:VSLangProj.dll
- 标识工程中的一个引用，在工程中可以使用任何引用中包含的公共成员，可以是.Net工程，.Net 程序集，COM对象
