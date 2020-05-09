# Manifest介绍

## 参考资料

- https://docs.microsoft.com/zh-cn/windows/desktop/SbsCs/manifest-files-reference

## Manifest（清单）文件引用

- 在XML形式的清单文件和配置文件中配置并行程序集(Side-by-side assembly)
- 1.Assembly Manifest - 用于描述并行程序集的名称、版本、资源、依赖的程序集
- 2.Application Manifest - 用于描述应用程序在运行时应该捆绑的共享的并行程序集的名称和版本，以及应用程序可能会用到的私有并行程序集的元数据
- 3.Application Configuration Files - 用于重定向每个应用程序配置文件的程序集依赖的版本
- 4.Publisher Configuration Files - 用于重定向程序集依赖的版本，基于每个程序集

### 程序集清单 Assembly Manifest

- https://docs.microsoft.com/zh-cn/windows/desktop/SbsCs/assembly-manifests
- 用于描述：并行程序集的名称、版本；文件；程序集资源；依赖程序集的并行程序集。并行程序集的准确的安装、激活、执行需要程序集清单伴随；
- `清单文件位置`（3）：
  - 1.伴随共享程序集时，应作为`单独文件`安装在并行程序集缓存内，通常为WinSxs文件夹或者Windows目录；
  - 2.伴随私有程序集时，应被安装在应用程序的结构目录中，通常为与应用程序Exe文件同目录的独立的文件；
  - 3.作为一个DLL的资源，该程序集作为DLL的私有使用，程序集清单文件不能包含在Exe的资源中，exe文件可能会有应用程序清单文件作为资源；
- `文件名`
- 程序集清单文件必须的元素
  - 1.assembly - 根元素
    > manifestVersion - 必须属性
  - 2.assemblyIdentity - 必需的元素
    > 必需属性：type  name version
    > 可选属性：language processorArchitecture publicKeyToken
  - 3.dependency - 可选元素，内部第一个元素必须为dependentAssembly
  - 4.dependentAssembly - 可选元素，内部第一个元素必须为assemblyIdentity 
  - 5.file - 可选元素
    > 必需属性：name
    > 可选属性：hashalg hash
    - 子元素：comClass  typelib  comInterfaceProxyStub windowclass
  - 6.comInterfaceExternalProxyStub assembly的子元素
  - 7.windowClass assembly的子元素也可以作为File的子元素

```XML
<!-- 当前DLL为 Main.DLL ,该DLL依赖于 A.DLL,B.DLL,C.DLL -->
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<!-- 必须的根元素[assembly] -->
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
<!-- 第一个子节点 必须为[assemblyIdentity] 用于标识当前管理的DLL信息 -->
  <assemblyIdentity type="win32" name="Main" version="1.0.0.0" processorArchitecture="x86" publicKeyToken="0000000000000000"/>
    <!-- 描述依赖项 -->
    <dependency>
    <!-- 第一个子元素必须为dependentAssembly -->
      <dependentAssembly>
          <assemblyIdentity type="win32" name="A" version="1.0.0.0" processorArchitecture="x86" publicKeyToken="0000000000000000"/>
          <assemblyIdentity type="win32" name="B" version="1.0.0.0" processorArchitecture="x86" publicKeyToken="0000000000000000"/>
          <assemblyIdentity type="win32" name="C" version="1.0.0.0" processorArchitecture="x86" publicKeyToken="0000000000000000"/>
      </dependentAssembly>
    </dependency>
    <!-- 描述依赖文件 -->
    <file name="Lib\A.dll" >
      <typelib></typelib>
    </file>
    <file name="Lib\B.dll" ></file>
    <file name="Lib\C.dll" ></file>
    <file name="sampleu.dll" hash="3eab067f82504bf271ed38112a4ccdf46094eb5a" hashalg="SHA1">
        <comClass description="Font Property Page" clsid="{0BE35200-8F91-11CE-9DE3-00AA004BB851}"/>
        <comClass description="Color Property Page" clsid="{0BE35201-8F91-11CE-9DE3-00AA004BB851}"/>
        <comClass description="Picture Property Page" clsid="{0BE35202-8F91-11CE-9DE3-00AA004BB851}"/>
    </file>
    <file name="bar.dll" hash="ac72753e5bb20446d88a48c8f0aaae769a962338" hashalg="SHA1"/>
    <file name="foo.dll" hash="a7312a1f6cfb46433001e0540458de60adcd5ec5" hashalg="SHA1">
        <comClass description="Registrar Class" clsid="{44EC053A-400F-11D0-9DCD-00A0C90391D3}" progid="ATL.Registrar"/>
        <comInterfaceProxyStub iid="{B6EA2051-048A-11D1-82B9-00C04FB9942E}" name=" IAxWinAmbientDispatch " tlbid="{34EC053A-400F-11D0-9DCD-00A0C90391D3}"/>
        <typelib tlbid="{44EC0535-400F-11D0-9DCD-00A0C90391D3}" version="1.0" helpdir=""/>
        <windowClass versioned="no">ToolbarWindow32</windowClass>
    </file>
    <file name="sampledll.dll" hash="ba62960ceb15073d2598379307aad84f3a73dfcb" hashalg="SHA1"/>
    <windowClass>ComboBoxEx32</windowClass>
    <windowClass>sample_trackbar32</windowClass>
    <windowClass>sample_updown32</windowClass>
    <comInterfaceExternalProxyStub>    </comInterfaceExternalProxyStub>
</assembly>
```

### 应用程序清单 Application Manifest



### 应用程序配置文件 Application Configuration File

- https://docs.microsoft.com/en-us/previous-versions/dotnet/netframework-3.5/0kk0kk35(v%3dvs.90)