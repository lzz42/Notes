# 常用工具

## Process Explorer

- [下载](http://www.sysinternals.com)

### 常用快捷键

- 视图
  - 查看或者切换到查看DLL:Ctrl+D
  - 查看系统资源句柄：Ctrl+H
  - 显示或者关闭下方详细信息窗口：Ctrl+L
  - 立即刷新：F5
  - 暂停或者继续刷新：Space
  - 系统信息：Ctrl+I
- 中断和延迟过程调用DCPs
  - 查看中断和DCPs总数：Context Switch列
  - 一次刷新间隔内中断和DCPs总数：Context Switch Delta

## Process Monitor

- [下载](http://www.sysinternals.com)

### 介绍

- 启动需要本地管理员组成员权限
- 主要监控3类操作：文件系统，注册表，进程信息
  - 文件系统监控：监控所有文件系统的活动包括：本地存储和远程文件
  - 注册表:使用缩写监控注册表活动
  - 进程:监控子系统进程以及线程的创建和退出以及DLL和设备驱动加载操作
  - 网络:使用ETW跟踪记录TCP和UDP活动
  - 分析:扫描所有线程记录内核和用户的CPU消耗以及上下文切换执行（不包含系统进程）