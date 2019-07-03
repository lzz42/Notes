# Basic Knowledge

## About npm

- 更换npm代理：
  - 1.使用淘宝代理：`npm config set registry https://registry.npm.taobao.org --global`,`npm config set disturl https://npm.taobao.org/dist --global`,
    - 查看本地镜像资源：`npm config get registry`
  - 2.使用cnpm 代替npm：`npm install cnpm -g -registry=https://registry.npm.taobao.org`

## 配置开发环境

- 安装Node.js、npm

## 关于Electron

- 本质上是一个Node.JS的应用程序,基于Node.JS
- 应用入口：package.json文件
- 基本Electron目录结构：app/package.json,main.js,index.html
- 创建新工程：`npm [AppName]`
- 安装Electron，推荐使用app依赖的模式：`npm install --save-dev electron`

## 打包发布

- 安装： electron-packager，`npm install electron-packager --save-dev`

## 参考资料

- [打包发布](https://segmentfault.com/a/1190000013924153)