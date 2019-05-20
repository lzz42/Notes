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
- `清单文件安装位置`（3）：
  - 1.伴随共享程序集时，应作为单独文件安装在并行程序集缓存内，通常为WinSxs文件夹或者Windows目录；
  - 2.伴随私有程序集时，应被安装在应用程序的结构目录中，通常为与应用程序Exe文件同目录的独立的文件；
  - 3.作为一个DLL的资源，该程序集作为DLL的私有使用，程序集清单文件不能包含在Exe的资源中，exe文件可能会有应用程序清单文件作为资源；
- `文件名`
  - 
- 程序集清单文件必须的元素
  - 1.assembly - 根元素
    > manifestVersion - 必须属性 
  - 2.assemblyIdentity -
    > type  name version

### 应用程序清单 Application Manifest

- 