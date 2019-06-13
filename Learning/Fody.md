# Fody

## 使用

- 1.VS工程添加Nuget包：Costura.Fody -v 4.0.0(对于Coret:dotnet add DotNetCore package Costura.Fody -v 4.0.0)
- 2.工程资源中引用FodyWeavers.xml,将该文件设置为：生成操作-内容，不复制本地；
- 3.编辑FodyWeavers.xml 添加节点：  <Costura /> 
- 4.将引用的DLL设置为复制到本地；
- 5.生成工程即可，将DLL作为压缩的资源文件嵌入Exe中；

## 参考资料

- https://github.com/Fody/Costura
- http://einaregilsson.com/module-initializers-in-csharp/
- https://www.nuget.org/packages/InjectModuleInitializer/
- dotnet add package InjectModuleInitializer --version 2.0.3