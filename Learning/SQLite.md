# SQLite

## 参考资料

- [下载地址](https://www.sqlite.org/download.html)
- [在线演示](http://www.compileonline.com/execute_sql_online.php)

## 安装

- windows下需要：对应的dll文件和tools文件（sqlite3.def,sqlite3.dll,sqlite3.exe）

## SQLite命令

- SQL命令
  - 1.DDL数据定义命令：create，alter，drop
  - 2.DML数据操作命令：insert，update，delete
  - 3.DQL数据查询命令：select
- SQLite命令
  - 1.从dos进入sqlite命令行：.sqlite;
  - 2.退出：.quit;
  - 3.查看数据库：.databases;
  - 4.查看表：.tables;
  - 5.查看指定表结构：.schema [table name];
  - 6.创建或者打开指定名称数据库：.sqlite3 [db file name];
  - 7.导入数据文件：.read [data file name];
- SQLite中特殊表sqlite_master

## SQLite语法

- 大小写敏感
- 注释使用`--`