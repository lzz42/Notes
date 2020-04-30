# pip 安装和使用

## 参考资料

- <https://www.cnblogs.com/believepd/p/10499844.html>
- pip扩展仓库:https://www.lfd.uci.edu/~gohlke/pythonlibs/

## 更新pip源到国内镜像

- 国内镜像源地址
  - 豆瓣 <https://pypi.doubanio.com/simple/>
  - 阿里云    <https://mirrors.aliyun.com/pypi/simple/>
  - 清华大学：
    - <https://pypi.tuna.tsinghua.edu.cn/simple/>
  - <https://mirrors.tuna.tsinghua.edu.cn/pypi/web/simple/>
- 临时使用：`pip install [some-package] -i [Mirrir Address]`
- 设置为默认：
  - `pip install pip -U`
  - ·`pip config set global.index-url  [Mirrir Address]`

## pip命令

- 查看pip版本:`pip --version`
- 普通安装：`pip install <package-name>`
- 指定版本安装(使用==，>=,<=,>,<指定版本号)：
  - `pip install [package-name]>[version]`
  - `pip install [package-name]>[version1],<[version2]`
- 卸载已安装库：`pip uninstall <package-name>`
- 列出已安装库：`pip list`
- 将已安装的库列表保存到文件中：`pip freeze > <file-name>.txt`
- 根据依赖文件批量安装库：`pip install -r <file-name>.txt`
- 使用wheel文件离线安装库：`pip install pillow-***.whl`
- 查看可升级的包：`pip list -o`
- pip升级指定包：
  - `pip install -U <package-name>`
  - `pip install <package-name> --upgrade`
- 升级pip：
  - `python -m pip install --upgrade pip`
  - `pip install -U pip`
- 显示包所在目录：
  - `pip show -f <package-name>`
- 搜索包：
  - `pip search <key-words>`
- 下载包而不安装
  - `pip install <package-name> -d <dir>`
  - `pip install -d <dir> -r <requirements>.txt`
- 打包:
  - `pip wheel <package-name>`

## 其他

- pip安装包的路径："Python的Lib>site-packages"