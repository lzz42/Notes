# Go语言学习

## 基本知识：

- 环境安装 安装包下载:
- [地址1](https://golang.org/)
- [地址2](https://golang.google.cn/)

## 语言基础组成

- 包声明：

```GO
    package main
```

- 包引入：

```GO
    import "fmt"
```

- 函数

```GO
    func 函数名(){
        //函数体
    }
```

- 变量

```GO
    const PI=3.14 //定义常量
```

- 语句&表达式
- 注释

```GO
    //单行注释
    /*多行注释
    */
```

## Go程序运行

- Dos指令： go run *.go
- 每个Go程序都有一个main包，且有且仅有一个main函数
- main函数是每一个可执行程序所必须包含的，一般启动后第一个执行，若存在init()函数则先执行init函数
- 标识符（常量/变量/类型/函数名/结构字段）为首字母大写，则该标识符对象可以呗外部包使用，即导出；若小写则对包外不可见

## 程序结构说明

- Go标记
- 行分隔符：一行代表一语句结束，多个语句在同一行则必须用;分隔
- 标识符（命名程序实体）：第一个字符必须是字母或者下划线不能是数字
- 关键字：25个关键字（保留字），36个预定义标识符

|关键字|名称|描述|
|------|---|---|
|package,import
|func,interface,struct
|const,var,map,chan,range
|for,continue,break,goto
|if,else,switch,select,case,default
|go,return
|defer,fallthrough

## 数据类型

|类型名称|描述|值|
|--------|---|--|
|布尔型|bool|true/false|
|数字类型|int/float32/float64|--|
|字符串类型|单字节连接，Utf-8编码的Unicode|--|
|派生类型|指针/数组/结构体/Channel类型/函数/切片/接口/map|--|

- 数字类型
    > 整型`uint8，uint16,uint32,uint64,int8,int16,int32,int64`
    > 浮点型`float32,float64,complex64(64位实数和虚数)，conplex128(64位实数和虚数)`
    > 其他数字类型`byte==uint8,rune==int32,uint,int,uintptr无符号整型，用于存放指针`

## 语言变量

- 声明变量：一般使用：var 变量名 变量类型

```GO
    var bSet bool
    var bSet = true //省略类型
    bSet := true //省略var，只能用在函数体内
    //多变量
    var vn1,vn2,vn3 type1,type2,type3
    var vn1,vn2,vn3 = value1,value2,value3
    vn1,vn2,vn3 := value1,value2,value3
```

- 值类型和引用类型
  - 值类型：int，float，bool，string，属于值类型，变量直指向内存值，对变量赋值是对内存值进行拷贝，值类型变量存储在栈中
  - 引用类型：存储值所在的内存地址或者内存地址第一个字所在位置
- 常量
  - 程序运行时不会被修改的值，布尔型，数字型，字符串
  - 常量表达式:函数必须是内置函数
  - iota:被编译器修改的常量在每一个const关键字出现时，被重置为0，然后再下一个const出现之前，每出现一次iota，其所代表的数字会自动增加1。
  - iota 可以被用作枚举值，第一个 iota 等于 0，每当 iota 在新的一行被使用时，它的值都会自动加 1

## 运算符

- 算术运算符 `+,-,*,/,%,++,--`
- 关系运算符 `==,!=,<=,>=,<,>`
- 逻辑运算符 `&&(and),||(or),!(not)`
- 位运算符 `&(与),|(或),^(异或),<<,>>`
- 赋值运算符 `=,+=,-=,*=,/=,%=,<<=,>>=,&=,|=,^=`
- 其他运算符 `&---返回变量存储地址，*---指针变量`

## 条件语句

- if,if...else

```GO
if num := 1; num > 0 {
//
}else if num==0 {
//
}
```

- switch...case ：case结束不需要加break

```GO
switch x.(type){
    case int:
    //...
    case float:
    //...
    case string:
    //...
    default:
    //...
}
```

- select...case :随机选择一个case执行，若没有符合条件的则阻塞

```GO
select {
    case statement1:
    //...
    case statement2:
    /...
    default:
    /...
}
```

## 循环语句

- for

```GO
var i = 0
for true{
    //无线循环
    if i>1<<32
    break   //中断循环
    if i%2==0
    continue
    fmt.Printf(i,"\n")
    if i%5==0{
        goto A
    }
    else{
        continue
    }
    A: fmt.Printf("goto label A")
}
```

## 函数

- 函数定义

```GO
func func_name([parameter list])[return types]{
    //func body
}
func Add(int a,int b) int{
 return a+b
}
```

- 函数参数：值传递，引用传递，go默认参数为值传递
- 函数用法：函数作为值使用；闭包：动态编程中的匿名函数；方法：包含接受者的函数；

## 变量作用域

- 局部变量：函数内 `作用域为函数体，参数，返回值`
- 全局变量：函数外 `作用域整个包以及包外，同名变量名时优先使用局部变量`
- 形式参数：函数定义 `作用域函数体`
- 初始化局部变量和默认值：

    |类型|默认值|
    |----|-----|
    |int|0|
    |float32|0|
    |pointer|nil|

### 数组

- 相同类型，长度固定的数据项序列，索引从0开始
- 声明：`var name [size] vartype,eg: var ns [3] int`
- 初始化：

```GO
var ns  = [3]int{11,22,33} 
var na = [...]string{'a','b','c'}
```

- 访问元素：通过索引访问`var c = na[0]`

#### 多维数组

- 定义：`var name [size0][size1]...[sizen] type`
- 初始化：

```GO
var nas = [2][3]int{
    {1,2,3},
    {4,5,6}
}
```

- 访问：`var c =nas[0][0] //1`

#### 函数参数传递数组

- 形参设置数组大小：`func name(pa [size]type){}`
- 形参未指定数组大小：`func name(pa []type){}`

### 指针

- 变量是一种占位符，用于引用计算机内的内存地址，取地址符:`&`，返回变量的内存地址
- 定义：指针变量指向了一个值的内存地址
- 声明：`var name *type,eg:var iptr *int`
- 使用（指针类型前面加*获取指针指向的内容）:`1.定义指针变量；2.为指针变量赋值；3.访问指针变量指向地址的值；`
