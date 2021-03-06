# 应用程序配置文件App.config.md

## 参考

- https://docs.microsoft.com/en-us/dotnet/framework/configure-apps/file-schema/
- https://docs.microsoft.com/en-us/dotnet/framework/configure-apps/file-schema/
- [启用或禁用自动绑定重定向](https://docs.microsoft.com/zh-cn/dotnet/framework/configure-apps/how-to-enable-and-disable-automatic-binding-redirection)

## 结构介绍

## 子元素以及功能

### configuration

- 作用：指定配置文件的根元素
- 使用者：CLR 和.net应用程序
- 子元素：
  - assemblyBinding：指定程序集绑定策略；
  - Starup Settings Schema:用于指定应用程序要运行的CLR版本；
  - Runtime Settings Schema:CLR使用该设置来配置面向.net框架的应用程序
  - Remoting Settings Schema:用于设置现存应用程序中的向后兼容的遗留技术，新开发中不推荐，分布式应用程序应使用WCF；
  - Network Settings Schema：指定.net框架应用程序如何连接到互联网
  - Cryptography Settings Schema:用于如何友好的映射算法名称和加密算法实现的类；
  - Configuration Sections Schema:用于定义配置文件中的常见设置；
  - Trace and Debug Settings Schema:指定收集、存储、路由消息的跟踪监听器和跟踪开关的级别；
  - Compiler and Language Provider Settings Schema:
  - Application Settings Schema
  - App Settings Schema:
  - Web Settings Schema:
  - Windows Forms Configuration Schema:
  - WCF Configuration Schema:
  - WCF Directive Syntax
  - WIF Configuration Schema
  - ASP.net Configuration Schema:
  - WebService Settings Schema:
  - 

### assemblyBinding

- 作用：用于指定程序集绑定策略
- 属性：xmlns - 必须属性，指定程序集绑定的XML名称空间，一般使用`urn:schemas-microsoft-com:asm.v1`
- 父元素：configuration
- 子元素：linkedConfiguration
- EG：

```XML
<configuration>
  <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
    <linkedConfiguration href="file://c:\Program Files\Contoso\sharedConfig.xml" />
  </assemblyBinding>
</configuration>
```

### linkedConfiguration

- 作用：指定其他要包含的配置文件，仅限于加载器绑定策略
- 形式:`<linkedConfiguration href="URL of linked configuration file" />` 其中href仅支持file://和UNC文件
- 父元素：`<assemblyBinding>`
- 子元素：无
- 备注：
  - 1.当该元素服务于组件程序集时；若一个或多个应用程序使用一个具有配置文件以及放置在易探知的位置时，使用该程序集的应用程序的配置文件可以使用该元素包含该程序集的配置文件，而不用直接包含配置信息。当组件程序集进行维护时，更新该公共的配置文件即可为所有使用该程序集的应用程序提供更新的配置信息。
  - 2.该元素不支持具有Windows并行（side-by-side）清单文件的应用程序。
  - 3.使用link元素的规则：
    - a.该引用的配置文件的设置仅影响加载器的绑定策略而且仅被加载器使用，包含的配置文件可以有除绑定策略外的其他的设置，但这些设置不会对引用者有影响。
    - b.href属性仅支持file://和UNC文件；
    - c.对于单个配置文件无链接元素数量限制；
    - d.所有的配置文件将会合并为一个配置文件，类似C/C++的Include；
    - e.链接元素仅用于应用程序配置文件，`Machine.config`中无效；
    - f.会自动检测和终止循环引用；
- 示例：

```XML
<configuration>
  <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
    <linkedConfiguration href="file://c:\Program Files\Contoso\sharedConfig.xml"/>
    <linkedConfiguration href="file:sharedConfig.xml"/>
  </assemblyBinding>
</configuration>
```

- 问题：
  - 1.如何引用相对路径文件?
  > A:使用`file:[文件名].xml`,`file:..\[Dir]\[文件名].xml`
  - 2.某些情况下会出现对于同一个XML文件有时候会出现配置文件格式不对的情况
  > A:检查应用程序是否采用了清单文件，清单文件可能会与该配置冲突（待研究）
  - 3.处理应用程序错误？
  > sxstrace跟踪调试应用程序进行分析
  > 1.利用管理员身份运行CMD;2.输入sxstrace.exe Trace -logfile:C:\trace.log(路径自定义)，开始跟踪;3.运行应用程序，回车，完成跟踪生成报告;4.输出分析日志：输入sxstrace.exe Parse -logfile:C:\trace.log -outfile:C:\trace.txt；5.打开trace.txt文件，查看日志信息