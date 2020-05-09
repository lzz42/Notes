# VSX基本概念

## 什么是Visual Studio Package

- 构建Visual Studio的基本单元，可以通过Package扩展VS IDE：服务，界面元素，编辑器，设计器，项目；
- 每个Package必须被PLK签名
- 实现了IVsPackage接口的类型

## VS调试

- 选择启动类型未类库
- 调试选项中-启动外部程序，选择VS程序：C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\devenv.exe
- 附加启动参数：/rootsuffix Exp
- 若调试启动的VS新实例为：实验实例，则进入正确的插件调试模式；

## 服务

- Package之间或者与Package相关对象的契约
- 区分：全局服务-global service，本地服务-local service

### 使用服务

- 服务是隐藏的，即必须通过名字进行调用，即查找服务提供文档，
- 使用服务必须知道的信息：服务的名字，接口的名字
- [可用服务列表](https://docs.microsoft.com/zh-cn/visualstudio/extensibility/internals/list-of-available-services)

### 加载Package和访问服务

- 按需加载：仅加载被调用的Package
- Siting VSPackage:提供全局服务的service provider
- 访问全局服务：
  - 1.使用sit对象，通过GetService访问全局服务；
  - 2.得到VSPackage实例，访问；
  - 3.通过静态方法：Package.GetGlobalService

### 注册服务

- Package定义类添加特性：ProvideServiceAttribute

### Interoperability程序集和Managed Package Framework

- Interoperability程序集：使用.net类型包装了com类型，
- 使用VSX中com对象方法：1.使用非托管代码；2.使用Introp程序集；
- MPF：在com intreop程序集上建立的框架
- VSX中的Interop程序集：
- VS SDK中的Microsoft.VisualStudio*系列
- MPF中的Shell系列

### 命令

- [CommandEventsClass](https://docs.microsoft.com/zh-cn/dotnet/api/envdte.commandeventsclass?view=visualstudiosdk-2017)

#### 监听命令的执行

- 1.查询命令列表：EnvDTE.DTE.Commands

```C#
foreach(Command cmd in DTE.Commands)
{
    //TODO:Print cmd information
}
```

- 2.使用接口CommandEvents监听命令
- 接口CommandEvents：可以使用实例EnvDTE.DTE.Events.CommandEvents
- 订阅接口的BeforeExecute事件或者AfterExecute事件可以在命令执行前或命令执行后，捕捉到事件发生；

#### 插件运行过程中动态修改菜单项显示内容

- 1.在Package初始化加载命令是 使用OleMenuCommand包装命令CommandID

```C#
OleMenuCommand ocmd = new OleMenuCommand(UpdateRuntimeEnvironmentMenuItemClick, updateRuntimeEnvironmentCommandID);
ocmd.BeforeQueryStatus += new EventHandler(ocmd_BeforeQueryStatus);
mcs.AddCommand(ocmd);
```

- 2.订阅OleMenuCommand实例的BeforeQueryStatus事件:
- 3.在订阅的事件参数中：通过sender强转为OleMenuCommand实例，通过该实例即可修改菜单项内容

```C#
void ocmd_BeforeQueryStatus(object sender, EventArgs e)
{
    var myCommand = sender as OleMenuCommand;
    if (null != myCommand)
    {
        if (mListenCmdEvents)
        {
            myCommand.Text = "停止监听事件";
        }
        else
        {
            myCommand.Text = "开始监听事件";
        }
    }
}
```

- 4.还需要VSCT文件中针对要修改的Button项，否则会出错，添加参数：<CommandFlag>TextChanges</CommandFlag>
- [CommandFlag元素说明](https://docs.microsoft.com/zh-cn/visualstudio/extensibility/command-flag-element)

```XML
<Button guid="guidXaptoolsCmdSet" id="cmdidUpdateRuntimeEnv" priority="0x108" type="Button">
<Parent guid="guidXaptoolsGroup" id="idXaptoolsOptionsGroup" />
<Icon guid="guidImageReload" id="pngReload" />
<CommandFlag>TextChanges</CommandFlag>
<Strings>
    <CommandName>cmdidUpdateRuntimeEnvironment</CommandName>
    <ButtonText>开始监听事件</ButtonText>
</Strings>
</Button>
```

#### 命令执行

- 通过代码的方式执行命令
- 1.使用IOleCommandTarget，通过可用服务列表中获取；
  - 访问全局服务：
  - 1.使用sit对象，通过GetService访问全局服务；
  - 2.得到VSPackage实例，访问；
  - 3.通过静态方法：Package.GetGlobalService
- 2.调用IOleCommandTarget中的Exec方法；

#### 命令对象说明

- COM接口：Command - 基础命令对象，仅有GUID，ID，通过接口获得
- 托管对象：CommandID - 托管命令对象，通过GUID和ID构建
- 托管对象：MenuCommand - 命令菜单项，可以更改部分命令外观属性
- 托管对象：OleMenuCommand - 命令菜单项，可以更改命令外观属性

#### 引用管理器扩展性

- [参考资料](https://msdn.microsoft.com/zh-cn/library/hh873125(v=vs.110).aspx)

#### 事件监听

1.获取事件监听实例对象:IVsSolution

```C#
IVsSolution solution = provider.GetService(typeof(SVsSolution)) as IVsSolution;
```

2.定义实现事件接口的类：

```C#
public class VsSolutionEventListener: IVsSolutionEvents, IVsSolutionEvents4
```

3.添加事件监听到实例中：

```C#
solution.AdviseSolutionEvents(this, out pdwCookie);
```

4.从接口IVsHierarchy获取EnvDTE.Project实例的方法：

```C#
private static EnvDTE.Project GetProjFromIVsHierarchy(IVsHierarchy hierarchy)
{
    if (hierarchy == null)
        throw new ArgumentNullException("hierarchy");
    object obj;
    var res= hierarchy.GetProperty(VSConstants.VSITEMID_ROOT, (int)__VSHPROPID.VSHPROPID_ExtObject, out obj);
    if(res== VSConstants.S_OK)
    {
        return obj as EnvDTE.Project;
    }
    return null;
}
```

5.监听方法返回值遵循SDK参数规定：

```C#
Microsoft.VisualStudio.VSConstants.S_OK
```

#### 获取当前选择项的所在的工程

- 1.使用全局服务IVsMonitorSelection，调用方法GetCurrentSelection

```C#
public static void GetCurrentSelectProj(out EnvDTE.Project proj)
{
    proj = null;
    var monitor = OperationCenter.GetService<IVsMonitorSelection>() as IVsMonitorSelection;
    if (monitor != null)
    {
        IVsHierarchy hierarchy = null;
        IntPtr ppHier, ppSC;
        uint pitemid;
        IVsMultiItemSelect ppMIS;
        var res = monitor.GetCurrentSelection(out ppHier, out pitemid, out ppMIS, out ppSC);
        if (res == VSConstants.S_OK)
        {
            if (ppHier != null)
            {
                hierarchy = (IVsHierarchy)Marshal.GetUniqueObjectForIUnknown(ppHier);
                var proj2 = GetProjFromIVsHierarchy(hierarchy);
                proj = proj2;
            }
            //if (pitemid == Microsoft.VisualStudio.VSConstants.VSITEMID_SELECTION)
            //{
            //    //Get mutiple ites by ppMIS
            //}
        }
    }
}
```

#### 加载Package

- 参考资料：[查看](https://docs.microsoft.com/zh-cn/visualstudio/extensibility/loading-vspackages?view=vs-2017)

## 编程指南

### 新增设置输出面板

- 添加输出源

```C#
public static void AddLoggerOutputSource(string name)
{
    if (MDTE == null)
        return;
    var dte = MDTE;
    EnvDTE.OutputWindow ow = (dte as EnvDTE80.DTE2).ToolWindows.OutputWindow;
    try
    {
        ow.Parent.AutoHides = false;
        ow.Parent.Activate();
        bool hasSameName = false;
        foreach (EnvDTE.OutputWindowPane item in ow.OutputWindowPanes)
        {
            if (item.Name.ToLower().Contains(name))
            {
                hasSameName = true;
                break;
            }
        }
        if (!hasSameName)
        {
            ow.OutputWindowPanes.Add(name);
        }
    }
    catch (Exception ex)
    {
        System.Diagnostics.Trace.TraceError(ex.Message);
    }
}
```

- 设置输出源显示

```C#
public static void ShowLoggerPane()
{
    if (MDTE == null)
        return;
    var dte = MDTE;
    EnvDTE.OutputWindow ow = (dte as EnvDTE80.DTE2).ToolWindows.OutputWindow;
    try
    {
        ow.Parent.AutoHides = false;
        ow.Parent.Activate();
        foreach (EnvDTE.OutputWindowPane item in ow.OutputWindowPanes)
        {
            if (item.Name.ToLower().Contains("name"))
            {
                item.Activate();
                break;
            }
        }
    }
    catch (Exception ex)
    {
        System.Diagnostics.Trace.TraceError(ex.Message);
    }
}
```
