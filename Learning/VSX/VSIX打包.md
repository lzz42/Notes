# VSIX打包

## 手动将扩展打包

- 微软官网[链接](https://msdn.microsoft.com/zh-cn/library/ff407026.aspx)
- 创建一个 Visual Studio 扩展，其类型受 VSIX 架构支持。
- 创建一个 XML 文件，将其命名为 extension.vsixmanifest。
- 根据 VSIX 架构填写 extension.vsixmanifest 文件。 有关示例清单，请参阅 PackageManifest 元素（根元素，VSX- 构）。
- 再创建一个 XML 文件，将其命名为 [Content_Types].xml。
- 按 结构的 Content_types].xml 文件 中的指定填写 [Content_Types].xml 文件。
- 将这两个 XML 文件与要部署的扩展一起放在某个目录。
- 如果是项目模板或项模板，则将包含该模板的 .zip 文件放在 XML 文件所在的文件夹中。 不要将 XML 文件放在 .zip - 中。
- 在其他所有情况下，将 XML 文件放在生成输出所在的目录中。
- 在 Windows 资源管理器中，右键单击包含扩展内容和这两个 XML 文件的文件夹，单击“发送到”，然后单击“压缩(zipped)- 夹”。
- 将生成的 .zip 文件重命名为 Filename.vsix，其中 Filename 是用于安装包的可再发行文件的名称。

```xml
<Vsix Version="1.0.0" xmlns="http://schemas.microsoft.com/developer/vsx-schema/2010">
   <Identifier ID="Package ID">
      <AllUsers>... </AllUsers>
      <Author>... </Author>
      <Description>... </Description>
      <GettingStartedGuide>... </GettingStartedGuide>
      <Icon>... </Icon>
      <InstalledByMSI>... </InstalledByMSI>
      <License>... </License>
      <Locale>... </Locale>
      <MoreInfoUrl>... </MoreInfoUrl>
      <Name>... </Name>
      <PreviewImage>... </PreviewImage>
      <SupportedFrameworkRuntimeEdition>... </SupportedFrameworkRuntimeEdition>
      <SupportedProducts>... </SupportedProducts>
      <SystemComponent>... </SystemComponent>
      <Version>... </Version>
    </Identifier>
    <Reference ID="Namespace.ToReference" minversion="1.0" maxversion="2.1">
      <Name>...</Name>
      <MoreInfoUrl>...</MoreInfoUrl>
      <VSIXPath>...</VSIXPath>
    </Reference>
    <Content>
      <Assembly>...</Assembly>
      <CustomExtension>...</CustomExtension>
      <ItemTemplate>...</ItemTemplate>
      <MEFComponent>...<MEFComponent>
      <ProjectTemplate>...</ProjectTemplate>
      <ToolboxControl>...</ToolboxControl>
      <VSPackage>...</VSPackage>
    </Content>
</Vsix>
```

### 如何将个别文件打包到VSIX中

1.修改工程中的vsixmannifest文件：
在Content节点下新增CustomExtension节点，并设置Type，内容设置为要添加的文件的相对路径；

```XML
<Content>
    <!-- ... -->
    <CustomExtension Type="nuget">dlls\nuget.exe</CustomExtension>
  </Content>
```

2.VS2010好像有专门的可视化工具可以对vsixmannifest文件进行修改；