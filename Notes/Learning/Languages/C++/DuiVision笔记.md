# DuiVision笔记

## 介绍

- 开源代码：https://github.com/blueantst/DuiVision

## 笔记

- 1.获取配置文件中值
  - `xml\resource.xml`文件中的key-value,`<res type="cfg" name="loglevel" value="1" />`

```C++
CString strValue =  DuiSystem::Instance()->GetConfig(_T("Key"));
```

- 2.MFC程序入口点
  - 通过全局类变量来实现
  - 最初入口函数->全局变量初始化->全局变量的实例函数:`BOOL [类名]::InitInstance()`
- 
