# Node js

## Node.js介绍

- 基于Chrome JavaScript运行时的平台
- 事件驱动I/O服务端JavaScript环境，基于Google V8引擎

## NodeJS组成

- 1.引入`require`模块：通过require指令载入Node.js模块；
- 2.创建服务器；
- 3.接收请求与响应请求；
- 过程：
  - 1.编辑JS文件；
  - 2.运行JS文件：node [js文件]

## NPM

- npm版本升级：`npm install npm -g`
- 安装模块：`npm install [模块名称]`
  - 1.本地安装：`npm install [模块名称]`
  - 2.全局安装：`npm install [模块名称] -g`
- 查看全局安装模块：`npm list`
  - 1.查看本地安装模块:`npm list`
  - 2.查看全局安装模块：`npm list -g`
- 查看包的属性：
  - 通过包的Package.json文件，该文件内记录包相关信息
| 属性         | 描述       |
| ------------ | ---------- |
| name         | 包名称     |
| version      | 版本号     |
| description  | 描述       |
| homepage     | 官网地址   |
| aothor       | 作者       |
| contributors | 构建贡献者 |
| dependencies | 依赖项     |
| respository  | 代码位置   |
| main         | 主程序入口 |
| keywords     | 关键字     |
- 卸载模块：`npm uninstall [包名称]`
- 更新模块：`npm update [PackageName]`
- 搜索模块：`npm search [PackageName]`
- 创建模块：`npm init`
  - 注册用户：`npm adduser`
  - 发布模块：`npm publish`
- 包版本号说明
  - X.Y.Z
  - 依赖某范围版本：1.2.x，[官方文档](https://docs.npmjs.com/specifying-dependencies-and-devdependencies-in-a-package-json-file)
- 使用淘宝镜像 - 由于网络原因，某些包无法下载问题
  - `npm install -g cnpm --registry=https://registry.npm.taobao.org`,[文档](http://npm.taobao.org/)
- 若安装报错，可以通过npm命令清理缓存后重新下载：`npm cache clean`

## Node.jS使用

### 回调函数

- 异步编程依托与回调函数

### 事件循环

- 事件驱动模型
  - 使用步骤：
  - 1.引入events`var events = require("eventes);"`
  - 2.创建EventEmitter对象：`var emitter = events.EventEmitter();`；
  - 3.绑定事件以及处理程序：`emitter.on('eventName',eventHandler);`
  - 4.合适的时机触发事件：`emitter.emit('eventName');`
- EventEmitter对象
  - 1.添加监听器：`addListener(event,listener)`
  - 2.为指定
