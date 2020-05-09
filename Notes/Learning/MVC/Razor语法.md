# Razor语法

- 服务器标记语言，允许向网页中插入代码的标记语法

## C# Razor

- 代码封装在@{...}中
- 行内表达式（变量和函数）以@开头，变量用var声明，变量名必须以字母字符开头，不能包含空格和保留字符
- 代码语句以分号结束
- 字符串由引号
- 大小敏感
- C#扩展名为cshtml

## VB 的主要 Razor 语法规则

- Razor 代码块被包围在 @Code ... End Code 中
- 行内表达式（变量和函数）以 @ 开头
- 以 Dim 关键词来声明变量
- 字符串由引号包围
- VB 对大小写不敏感
- VB 文件的扩展名是 .vbhtml

## 工作原理

- 1.razor网页
- 2.服务器读取razor网页后，需要将HTML发送给浏览器，
- 3.服务端发送html前，运行razor代码，动态生成html内容
- 4.服务端将生成的html发送给浏览器

## 对象

- 对象：具有可以执行方法，可以执行方法，具有属性，
- 内建对象：Date
- 自定义对象：

```Razor
<p>@DateTime.Now.Day::@DateTime.Now.Hours::@DateTime.Now.Minute::@DateTime.Now.Second</p>
```

## 逻辑判断

- 条件判断：if else

## 用户交互

- 读取用户输入：使用Request[]函数，IsPost判断用户请求类型：get或者post

## 变量

- 变量类型：int - 整型，float - 浮点型，decimal - 小数，bool - 布尔型，string - 字符串，
- 数据类型转换：
  - 