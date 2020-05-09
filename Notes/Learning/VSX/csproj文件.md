# CSProj文件

## CSProj文件结构

```XML
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <Import Project="$(MSBuildExtensionsPath)\$(MSBuildToolsVersion)\Microsoft.Common.props" Condition="Exists('$(MSBuildExtensionsPath)\$(MSBuildToolsVersion)\Microsoft.Common.props')" />
  <PropertyGroup>
    <Configuration Condition=" '$(Configuration)' == '' ">Debug</Configuration>
    <Platform Condition=" '$(Platform)' == '' ">AnyCPU</Platform>
    <ProjectGuid>{7C56757A-127E-2F62-989E-DA78B5F8E268}</ProjectGuid>
    <OutputType>WinExe</OutputType>
    <RootNamespace>Test</RootNamespace>
    <AssemblyName>Test</AssemblyName>
    <TargetFrameworkVersion>v4.0</TargetFrameworkVersion>
    <FileAlignment>512</FileAlignment>
    <Deterministic>false</Deterministic>
    <PublishUrl>publish\</PublishUrl>
    <Install>true</Install>
    <InstallFrom>Disk</InstallFrom>
    <UpdateEnabled>false</UpdateEnabled>
    <UpdateMode>Foreground</UpdateMode>
    <UpdateInterval>7</UpdateInterval>
    <UpdateIntervalUnits>Days</UpdateIntervalUnits>
    <UpdatePeriodically>false</UpdatePeriodically>
    <UpdateRequired>false</UpdateRequired>
    <MapFileExtensions>true</MapFileExtensions>
    <ApplicationRevision>0</ApplicationRevision>
    <ApplicationVersion>1.0.0.%2a</ApplicationVersion>
    <IsWebBootstrapper>false</IsWebBootstrapper>
    <UseApplicationTrust>false</UseApplicationTrust>
    <BootstrapperEnabled>true</BootstrapperEnabled>
    <TargetFrameworkProfile />
  </PropertyGroup>
  <PropertyGroup Condition=" '$(Configuration)|$(Platform)' == 'Debug|AnyCPU' ">
    <PlatformTarget>x86</PlatformTarget>
    <DebugSymbols>true</DebugSymbols>
    <DebugType>full</DebugType>
    <Optimize>false</Optimize>
    <OutputPath>..\Outut\</OutputPath>
    <DefineConstants>DEBUG;TRACE</DefineConstants>
    <ErrorReport>prompt</ErrorReport>
    <WarningLevel>4</WarningLevel>
    <Prefer32Bit>false</Prefer32Bit>
  </PropertyGroup>
  <PropertyGroup Condition=" '$(Configuration)|$(Platform)' == 'Release|AnyCPU' ">
    <PlatformTarget>x86</PlatformTarget>
    <DebugType>pdbonly</DebugType>
    <Optimize>true</Optimize>
    <OutputPath>..\Outut\</OutputPath>
    <DefineConstants>TRACE</DefineConstants>
    <ErrorReport>prompt</ErrorReport>
    <WarningLevel>4</WarningLevel>
    <Prefer32Bit>false</Prefer32Bit>
  </PropertyGroup>
  <PropertyGroup>
    <TargetZone>LocalIntranet</TargetZone>
  </PropertyGroup>
  <PropertyGroup>
    <GenerateManifests>false</GenerateManifests>
  </PropertyGroup>
  <PropertyGroup>
    <ApplicationManifest>Properties\app.manifest</ApplicationManifest>
  </PropertyGroup>
  <ItemGroup>
    <Reference Include="System" />
    <Reference Include="System.Core" />
    <Reference Include="System.Xml.Linq" />
    <Reference Include="Microsoft.CSharp" />
    <Reference Include="System.Data" />
    <Reference Include="System.Deployment" />
    <Reference Include="System.Drawing" />
    <Reference Include="System.Windows.Forms" />
    <Reference Include="System.Xml" />
    <Reference Include="core, Version=1.0.0.0, Culture=neutral, processorArchitecture=x86">
      <SpecificVersion>False</SpecificVersion>
      <HintPath>Dlls\core.dll</HintPath>
    </Reference>
  </ItemGroup>
  <ItemGroup>
    <Compile Include="Common\AssemblyHelper.cs" />
    <Compile Include="MainForm.cs">
      <SubType>Form</SubType>
    </Compile>
    <Compile Include="MainForm.Designer.cs">
      <DependentUpon>MainForm.cs</DependentUpon>
    </Compile>
    <Compile Include="Common\LogTraceHelper.cs" />
    <Compile Include="Program.cs" />
    <EmbeddedResource Include="MainForm.resx">
      <DependentUpon>MainForm.cs</DependentUpon>
    </EmbeddedResource>
    <EmbeddedResource Include="Properties\Resources.resx">
      <Generator>ResXFileCodeGenerator</Generator>
      <LastGenOutput>Resources.Designer.cs</LastGenOutput>
      <SubType>Designer</SubType>
    </EmbeddedResource>
    <Compile Include="Properties\Resources.Designer.cs">
      <AutoGen>True</AutoGen>
      <DependentUpon>Resources.resx</DependentUpon>
      <DesignTime>True</DesignTime>
    </Compile>
    <None Include="app.config" />
    <None Include="Dlls\devices\CD\DC.ini" />
    <None Include="Properties\Settings.settings">
      <Generator>SettingsSingleFileGenerator</Generator>
      <LastGenOutput>Settings.Designer.cs</LastGenOutput>
    </None>
    <Compile Include="Properties\Settings.Designer.cs">
      <AutoGen>True</AutoGen>
      <DependentUpon>Settings.settings</DependentUpon>
      <DesignTimeSharedInput>True</DesignTimeSharedInput>
    </Compile>
  </ItemGroup>
  <ItemGroup>
    <BootstrapperPackage Include="Microsoft.Net.Framework.3.5.SP1">
      <Visible>False</Visible>
      <ProductName>.NET Framework 3.5 SP1</ProductName>
      <Install>false</Install>
    </BootstrapperPackage>
  </ItemGroup>
  <ItemGroup>
    <None Include="Dlls\Devices\CD\std.dll" />
    <None Include="Dlls\Devices\MU\Api32.dll" />
    <None Include="Dlls\Newtonsoft.Json.dll" />
  </ItemGroup>
  <Import Project="$(MSBuildToolsPath)\Microsoft.CSharp.targets" />
  <PropertyGroup>
    <PreBuildEvent>
    </PreBuildEvent>
  </PropertyGroup>
  <PropertyGroup>
    <PostBuildEvent>xcopy "$(ProjectDir)Dlls" "$(ProjectDir)$(OutDir)" /s/y/f</PostBuildEvent>
  </PropertyGroup>
</Project>
```

### csproj文件介绍

- 参考资料：
  - 1.[理解 C# 项目 csproj 文件格式的本质和编译流程](https://blog.csdn.net/WPwalter/article/details/80371271)
  - 2.[微软Targets介绍](https://docs.microsoft.com/en-us/visualstudio/msbuild/msbuild-targets?view=vs-2017)
- xml文件
- 基本结构：
  - XML声明：指定xml版本和文件编码
  - 根节点：Project
  - PropertyGroup节点：存放属性信息
    - 编译使用的框架：旧版使用TargetFrameworkVersion 属性，新版使用TargetFrameworks属性
    - Conditon:属性生效的条件
    - PostBuildEvent:生成后事件 DOS脚本
  - ItemGroup:指定集合的地方
    - Reference：引用某个程序集
    - PackageReference：引用某个Nuget包
    - ProjectReference：引用某个项目
    - Compile:常规的C#编译
    - None：无，仅用于VS显示项
    - Folder：标识空文件夹
  - Import：
    - 导入属性文件props文件：使用props文件中规定的属性值，可以用来进行统一的版本控制

```XML
<Import Project="{.prop文件路径}" Condition="{为true时导入}"></Import>
```

    - 导入编译执行脚本targets文件：编译过程是用Targets文件执行，定义MSBuild的编译任务、编译过程和编译内容
- 特殊节点：
  - 影响自动生成版本号：即使用[assembly: AssemblyVersion("1.0.*")] 自动标记版本号，

``` xml
<Deterministic>false</Deterministic>
```

### VS和编译器对csproj文件处理过程

- 1.编译器根据csproj文件对工程进行编译（msbuild基于.net framework和roslyn基于.net core）；
  - 编译时会检查csproj文件中的导入的.props文件和.targets文件，以及
- 1.VS打开csproj文件：
  - a.解析所有的import节点，确认要引入的.props和.targets文件是否能正确引入；
  - b.根据PropertyGroup中设置的属性值在属性面板中显示状态
  - c.根据ItemGroup中的项显示引用列表、文件列表

### MSBuild与csproj文件

- MSBuild（Microsoft Build Engine）是Miscrosoft和Visual Studio的构建应用程序的平台，提供XML架构的的工程文件来控制如何构建平台过程和构建软件，VS使用MSBuild但是MSBuild不依赖VS的安装。通过在工程文件或者sln文件中调用MSBuild，可以在不安装VS时进行编排和构建工程。主要包含三部分内容：执行引擎、构造工程、任务；
- 执行引擎：定义构造工程的规范、解释构造工程、执行构造动作-引擎；
- 构造工程：描述构造任务，这里可以指未csproj文件（C#工程的项目内容管理和生成行为管理文件）-脚本；
- 任务：执行引擎的执行的动作定义-扩展能力；
- [参考资料](https://www.cnblogs.com/shanyou/p/3452938.html)
- csproj文件，为一个xml形式的文件

### 构造工程 - 脚本文件

## 通过编程方式操作csproj文件

### 编辑工程的调试项属性

- 1.找到接口VSLangProj.ProjectConfigurationProperties；
- 2.使用工程的EnvDTE.Project.ConfigurationManager.ActiveConfiguration.Properties
- 3.[参考文件](https://msdn.microsoft.com/en-us/6323383a-43ee-4a60-be4e-9d7f0b53b168)

```C#
public static void SetProjectDebugProp(EnvDTE.Project proj, string startProgrm,Enum.StartActionType startActiconType = Enum.StartActionType.Program, string startArgs = null, string startWorkingDirectory = null)
{
    if (proj != null && proj.Object is VSLangProj.VSProject)
    {
        var log = OperationCenter.MLogger;
        EnvDTE.Configuration activeConf = proj.ConfigurationManager.ActiveConfiguration;
        EnvDTE.Property startProp = activeConf.Properties.Item("StartProgram");
        EnvDTE.Property startActionProp = activeConf.ConfigurationManager.ActiveConfiguration.Item("StartAction");
        EnvDTE.Property startArguments = activeConf.Properties.Item("StartArguments");
        EnvDTE.Property startWorkingDirProp = activeConf.Properties.Item("StartWorkingDirectory");
        log.Info("开始设置工程:[{0}]调试配置项", proj.Name);
        string oldValue = startProp.Value;
        startProp.Value = startProgrm;
        log.Info("[{0}]:OldValue:[{1}],NewValue:[{2}]",startProp.Name, oldValue, startProp.Value.ToString());
        int oldValue2 = startActionProp.Value;
        startActionProp.Value = (int)startActiconType;
        log.Info("[{0}]:OldValue:[{1}],NewValue:[{2}]",startActionProp.Name, oldValue2.ToString(), startActionProp.Value.ToString());
        if (startArgs != null)
        {
            oldValue = startArguments.Value;
            startArguments.Value = startArgs;
            log.Info("[{0}]:OldValue:[{1}],NewValue:[{2}]", startArguments.Name,oldValue, startArguments.Value.ToString());
        }
        if (startWorkingDirectory != null)
        {
            oldValue = startArguments.Value;
            startWorkingDirProp.Value = startWorkingDirectory;
            log.Info("[{0}]:OldValue:[{1}],NewValue:[{2}]", startWorkingDirProp.Name, oldValue, startWorkingDirProp.Value.ToString());
        }
        proj.Save();
        log.Info("设置工程:[{0}]调试配置项完成.", proj.Name);
    }
}
```


