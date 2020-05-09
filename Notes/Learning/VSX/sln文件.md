# sln文件

## sln文件结构

```TXT
Microsoft Visual Studio Solution File, Format Version 11.00
# Visual Studio 2010
Project("{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}") = "Lib_A", "..\..\Test\SolutionB\Lib_A\Lib_A.csproj", "{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}"
EndProject
Project("{2150E333-8FDC-42A3-9474-1A3956D46DE8}") = "Solution Items", "Solution Items", "{53D0EA4C-F0B0-4117-828E-F33A14889796}"
	ProjectSection(SolutionItems) = preProject
		client.LibN.xml = client.LibN.xml
	EndProjectSection
EndProject
Project("{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}") = "Lib", "Lib\Lib.csproj", "{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}"
	ProjectSection(ProjectDependencies) = postProject
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9} = {EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A} = {8F2407A8-96CF-422D-98D1-CE7EBAC6848A}
	EndProjectSection
EndProject
Project("{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}") = "NO", "LibN5\NO.csproj", "{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}"
	ProjectSection(ProjectDependencies) = postProject
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A} = {8F2407A8-96CF-422D-98D1-CE7EBAC6848A}
	EndProjectSection
EndProject
Global
	GlobalSection(SolutionConfigurationPlatforms) = preSolution
		Debug|Any CPU = Debug|Any CPU
		Debug|Mixed Platforms = Debug|Mixed Platforms
		Debug|x86 = Debug|x86
		Release|Any CPU = Release|Any CPU
		Release|Mixed Platforms = Release|Mixed Platforms
		Release|x86 = Release|x86
	EndGlobalSection
	GlobalSection(ProjectConfigurationPlatforms) = postSolution
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Debug|Any CPU.ActiveCfg = Debug|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Debug|Any CPU.Build.0 = Debug|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Debug|Mixed Platforms.ActiveCfg = Debug|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Debug|Mixed Platforms.Build.0 = Debug|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Debug|x86.ActiveCfg = Debug|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Release|Any CPU.ActiveCfg = Release|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Release|Any CPU.Build.0 = Release|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Release|Mixed Platforms.ActiveCfg = Release|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Release|Mixed Platforms.Build.0 = Release|Any CPU
		{8F2407A8-96CF-422D-98D1-CE7EBAC6848A}.Release|x86.ActiveCfg = Release|Any CPU
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Debug|Any CPU.ActiveCfg = Debug|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Debug|Mixed Platforms.ActiveCfg = Debug|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Debug|Mixed Platforms.Build.0 = Debug|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Debug|x86.ActiveCfg = Debug|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Debug|x86.Build.0 = Debug|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Release|Any CPU.ActiveCfg = Release|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Release|Mixed Platforms.ActiveCfg = Release|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Release|Mixed Platforms.Build.0 = Release|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Release|x86.ActiveCfg = Release|x86
		{E374DFAF-95DB-4783-AC2C-6DBAB2C65F51}.Release|x86.Build.0 = Release|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Debug|Any CPU.ActiveCfg = Debug|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Debug|Mixed Platforms.ActiveCfg = Debug|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Debug|Mixed Platforms.Build.0 = Debug|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Debug|x86.ActiveCfg = Debug|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Debug|x86.Build.0 = Debug|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Release|Any CPU.ActiveCfg = Release|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Release|Mixed Platforms.ActiveCfg = Release|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Release|Mixed Platforms.Build.0 = Release|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Release|x86.ActiveCfg = Release|x86
		{EDF6BEA2-1D2C-45D5-B88B-41CB30F57FD9}.Release|x86.Build.0 = Release|x86
	EndGlobalSection
	GlobalSection(SolutionProperties) = preSolution
		HideSolutionNode = FALSE
	EndGlobalSection
EndGlobal
```

### SLN文件结构介绍

## 通过编程方式操作SLN文件

### 编辑解决方案中工程之间的生成依赖顺序问题

- 介绍：
  - 若在某些情况下，在同一个解决方案内的工程之间的引用方式是通过工程生成的DLL进行引用而不是工程之间引用，这样若多个工程修改后，需要最先编译引用链的第一个工程，然后才能编译后续的工程，
  - 此时需要调整解决方案的生成依赖顺序，即工程编译顺序；
- 1.使用接口BuildDependency
- 2.在解决方案中找到接口对象BuildDependency

```C#
public static bool FindBuildDependencyByProjID(string projID, out BuildDependency build)
{
    var result = false;
    build = null;
    if (OperationCenter.MDTE != null)
    {
        var bd = OperationCenter.MDTE.Solution.SolutionBuild.BuildDependencies;
        foreach (BuildDependency bdy in bd)
        {
            if (bdy.Project.FullName.Equals(projID, StringComparison.OrdinalIgnoreCase))
            {
                build = bdy;
                result = true;
                break;
            }
        }
    }
    return result;
}
```

- 3.编辑BuildDependency新增工程依赖

```C#
/// <summary>
/// 根据工程FullName添加生成依赖的工程集合FullName
/// </summary>
/// <param name="projID"></param>
/// <param name="projUniqueNames"></param>
public static void AddSlnBuildDependency(string projID, string[] projUniqueNames)
{
    if (OperationCenter.MDTE == null || projUniqueNames == null || projUniqueNames.Length <= 0)
        return;
    BuildDependency build;
    if (FindBuildDependencyByProjID(projID, out build))
    {
        for (int i = 0; i < projUniqueNames.Length; i++)
        {
            try
            {
                if (!IsExists(build, projUniqueNames[i]))
                {
                    build.AddProject(projUniqueNames[i]);
                    OperationCenter.NInfo("添加生成依赖:{0}到:{1}.", projUniqueNames[i], build.Project.Name);
                }
                else
                {
                    OperationCenter.NInfo("已存在的生成依赖项:{0},于:{1}.", projUniqueNames[i], build.Project.Name);
                }
            }
            catch (Exception ex)
            {
                OperationCenter.NError(ex, "添加工程依赖异常:{0} {1}.", build.Project.Name, projUniqueNames[i]);
            }
        }
        SolutionSave();
    }
}
```

- 4.添加前应检测 该工程的依赖项中是否已存在对要添加的工程的依赖，否则在SLN文件中会出现重复的工程依赖项

```c#
/// <summary>
/// 判断构建依赖项中是否已存在对指定工程的依赖
/// </summary>
/// <param name="build"></param>
/// <param name="uniqueName">工程的UniqueName</param>
/// <returns></returns>
public static bool IsExists(BuildDependency build, string uniqueName)
{
    if (build != null && build.Collection != null && !string.IsNullOrEmpty(uniqueName))
    {
        foreach (BuildDependency item in build.Collection)
        {
            if (item != null && item.Project != null)
            {
                if (string.Equals(item.Project.UniqueName, uniqueName, StringComparison.OrdinalIgnoreCase))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
```

- 5.此时查看解决方案的依赖项顺序 就会按照之前写入的工程依赖项，自动生成；

### 通过编程方式向已有解决方案中添加其他解决方案

> 在已打开的解决方案中添加现有的其他SLN到当前的解决方案；

- 1.VS自身添加现有项时，选择要添加的SLN 会自动添加SLN内所有的工程到当前解决方案中;
> VS命令：
> 名称：File.AddExistingProject，描述：文件.添加现有项目，
> GUID：{5EFC7975-14BC-11CF-9B2B-00AA00573819}，ID：773；

- 2.使用Microsoft.Build.BuildEngine.SolutionWrapperProject解析SLN文件，找出所有的Project，然后添加Project，需要从原SLN中获取工程的GUID;
- 3.使用内部类Microsoft.Build.Construction.SolutionParser解析SLN文件，找到管理的所有的Project，然后使用Env.DTE.Solution的AddFromFile方法加载工程；

> 首先定义内部类使用方法

```C#
/// <summary>
/// 通过反射的方式使用Microsoft.Build中的内部类Microsoft.Build.Construction.SolutionParser
/// 对sln进行解析
/// </summary>
internal sealed class Solution
{
    //internal class SolutionParser
    //Name: Microsoft.Build.Construction.SolutionParser
    //Assembly: Microsoft.Build, Version=4.0.0.0
    static readonly Type s_SolutionParser;
    static readonly PropertyInfo s_SolutionParser_solutionReader;
    static readonly MethodInfo s_SolutionParser_parseSolution;
    static readonly PropertyInfo s_SolutionParser_projects;
    static Solution()
    {
        s_SolutionParser = Type.GetType("Microsoft.Build.Construction.SolutionParser, Microsoft.Build, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", false, false);
        if (s_SolutionParser != null)
        {
            s_SolutionParser_solutionReader = s_SolutionParser.GetProperty("SolutionReader", BindingFlags.NonPublic | BindingFlags.Instance);
            s_SolutionParser_projects = s_SolutionParser.GetProperty("Projects", BindingFlags.NonPublic | BindingFlags.Instance);
            s_SolutionParser_parseSolution = s_SolutionParser.GetMethod("ParseSolution", BindingFlags.NonPublic | BindingFlags.Instance);
        }
    }
    public List<SolutionProject> Projects { get; private set; }
    public Solution(string solutionFileName)
    {
        if (s_SolutionParser == null)
        {
            throw new InvalidOperationException("Can not find type 'Microsoft.Build.Construction.SolutionParser' are you missing a assembly reference to 'Microsoft.Build.dll'?");
        }
        var solutionParser = s_SolutionParser.GetConstructors(BindingFlags.Instance | BindingFlags.NonPublic).First().Invoke(null);
        using (var streamReader = new StreamReader(solutionFileName))
        {
            s_SolutionParser_solutionReader.SetValue(solutionParser, streamReader, null);
            s_SolutionParser_parseSolution.Invoke(solutionParser, null);
        }
        var projects = new List<SolutionProject>();
        var array = (Array)s_SolutionParser_projects.GetValue(solutionParser, null);
        for (int i = 0; i < array.Length; i++)
        {
            projects.Add(new SolutionProject(array.GetValue(i)));
        }
        this.Projects = projects;
    }
}

/// <summary>
/// SLN中解析出的Project类
/// </summary>
[DebuggerDisplay("{ProjectName}, {RelativePath}, {ProjectGuid}, {ProjectType}")]
internal sealed class SolutionProject
{
    static readonly Type s_ProjectInSolution;
    static readonly PropertyInfo s_ProjectInSolution_ProjectName;
    static readonly PropertyInfo s_ProjectInSolution_RelativePath;
    static readonly PropertyInfo s_ProjectInSolution_ProjectGuid;
    static readonly PropertyInfo s_ProjectInSolution_ProjectType;
    static readonly PropertyInfo s_ProjectInSolution_Dependencies;
    static SolutionProject()
    {
        s_ProjectInSolution = Type.GetType("Microsoft.Build.Construction.ProjectInSolution, Microsoft.Build, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", false, false);
        if (s_ProjectInSolution != null)
        {
            s_ProjectInSolution_ProjectName = s_ProjectInSolution.GetProperty("ProjectName", BindingFlags.NonPublic | BindingFlags.Instance);
            s_ProjectInSolution_RelativePath = s_ProjectInSolution.GetProperty("RelativePath", BindingFlags.NonPublic | BindingFlags.Instance);
            s_ProjectInSolution_ProjectGuid = s_ProjectInSolution.GetProperty("ProjectGuid", BindingFlags.NonPublic | BindingFlags.Instance);
            s_ProjectInSolution_ProjectType = s_ProjectInSolution.GetProperty("ProjectType", BindingFlags.NonPublic | BindingFlags.Instance);
            s_ProjectInSolution_Dependencies = s_ProjectInSolution.GetProperty("Dependencies", BindingFlags.NonPublic | BindingFlags.Instance);
        }
    }
    public string ProjectName { get; private set; }
    public string RelativePath { get; private set; }
    public string ProjectGuid { get; private set; }
    public string ProjectType { get; private set; }
    public ArrayList Dependencies { get; set; }
    public SolutionProject(object solutionProject)
    {
        this.ProjectName = s_ProjectInSolution_ProjectName.GetValue(solutionProject, null) as string;
        this.RelativePath = s_ProjectInSolution_RelativePath.GetValue(solutionProject, null) as string;
        this.ProjectGuid = s_ProjectInSolution_ProjectGuid.GetValue(solutionProject, null) as string;
        this.ProjectType = s_ProjectInSolution_ProjectType.GetValue(solutionProject, null).ToString();
        this.Dependencies = s_ProjectInSolution_Dependencies.GetValue(solutionProject, null) as ArrayList;
    }
}
```

> 解析出Project后使用加载Project

```C#
/// <summary>
/// 加载Project到当前解决方案
/// </summary>
/// <param name="proj"></param>
/// <returns></returns>
public static bool LoadProj(Microsoft.Build.Evaluation.Project proj)
{
    if (proj != null && OperationCenter.MDTE != null)
    {
        try
        {
            OperationCenter.MDTE.Solution.AddFromFile(proj.FullPath, false);
            return true;
        }
        catch (Exception ex)
        {
            OperationCenter.NError(ex, "加载工程:{0}异常.", proj.FullPath);
        }
    }
    return false;
}
```
