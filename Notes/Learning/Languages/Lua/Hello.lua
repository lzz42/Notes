print("Hello World!")

print("--- Type Test ---")
print(type(('string')))
print(type(("string")))
print(type(123.321))
print(type(true))
print(type(nil))
print(type(xx))
print(type({}))
print(type(type({})))

print("--- Boolean Test ---")
xx=nil
if xx==nil then
    print("xx is nil")
else 
    if type(xx) == "nil" then
        print("type(xx) is \"nil\"")
    else
        print("type(xx) is not \"nil\"")
    end
end
if nil then
    print("nil is true")
else
    print("nil is false")
end
if 0 then
    print("0 is true")
else
    print("0 is false")
end
if 1 then
    print("1 is true")
else
    print("1 is false")
end
if 1024 then
    print("1024 is true")
else
    print("1024 is false")
end

print("--- number Test ---")
print(type(1024))
print(type(1024.0))
print(type(1024.1024))
print(type(10e+2))
print(type(0.30e12))
print(type(3.1415-03))
print((1024))
print((1024.0))
print((1024.1024))
print((10e+2))
print((0.0031415e3))
print((314.15e-2))

print("--- string Test ---")
str1="PI=3.141592653A"
str2='PI=3.141592653B'
str3=[[
    this is Block String
PI=3.141592653
PI=5857926
]]
print(str1)
print(str2)
print(str3)
a="3.14"
b=3.14
-- 字符串+ 尝试将字符串转为number
print(a+b)
-- 字符串连接使用【..】
print(a..b)
-- 使用#计算字符串长度
print(#a)
print(#(a..b))
print(#a..b)

print("--- table Test ---")
t={}
print(t)
local tn={"Alice",'Blice','Dlice'}
print(tn)
t['name']='Candy'
t[9527]=3.1415
t[9527]=3.1415
print(t['name'])
print(t[9527])
print(t[9528])
print(type(t[9527]))
print(type(t['name']))
print(type(t['nameAlice'])..'Alice')
for k,v in pairs(t) do
    print(k,v)
end
print("-----")
for i,v in ipairs(t) do
    print(i,v)
end
print("---Alice---")
for i,v in ipairs(tn) do
    print(i,v)
end

function factorial1(n)
    if n == nil then
        return "n is nil"
    end
    if type(n) ~= type(1) then
        return "n is not the type of number"
    end
    if n<=0 then
        return 1
    else
        return n * factorial1(n-1)
    end
end
print("Factoriall(5) is: "..factorial1(5))
print("Factoriall(5) is: "..factorial1(xa))
print("Factoriall(5) is: "..factorial1('dff'))

print("--- variable Test ---")
a = 55
local b = 66
function joke()
    c = 77
    local d =88
end
joke()
print(a,b,c,d)
do
    local a = 1055
    b = 1066
    print(a,b)
end
print(a,b)
a,b,c=11055,11066,11077
print(a,b,c)
a,b,c = c,a,b
print(a,b,c)

print("--- cycle Test ---")

function pp(n)
    return n+n
end

for v = 10, 15, pp(2) do
    print("Prime Number:"..v)
end

a=10

while(a>0)
do
    print("Reduce A : "..a)
    a=a-1
end

repeat
    print("Increace A : "..a)
    a=a+1
until (a>10)

print("--- function Test ---")

function Values(obj)
    local i = 0
    return function()
        i=i+1
        return obj[i]
    end
end

for i in Values({101,202,303,404}) do
    print("Values :"..i)
end


local function myFunc(n)
    print("my local function")
    local a,b,c=1024,2048,4096
    return a,b,c
end

print(myFunc(56))

function add( ... )
local s = 0
    for i,v in ipairs({...}) do
        if type(v)==type(0) then
            s=s+v
        end
    end
    print("Arg Count : " .. select("#", ...))
    print("Arg 5 is : " .. select(5, ...))
    return s
end

print("Add : "..add(1,2,3,4,"dff",{33},false))

function add(title, ... )
    print(title .. "Arg Count : " .. select("#", ...))
    print("Arg 2 is : " .. select(2, ...))
end

add("LuaLua",1,1024,2.56,555)

print("--- type convert Test ---")
local bV=false
local nV =3.14
print("Boolean to string :"..tostring(bV))
print("number to string :"..tostring(nV))
local sv ="16"
local sv2="0xA"
print("string to number 10 :"..tonumber(sv))
print("string to number 10 :"..tonumber(sv,16))
print("string to number 10 :"..tonumber(sv2))

print("--- operator Test ---")
a = 7
b = 2
print("a = " ..a.." b = "..b)
print("a + b =" ..a+b)
print("a - b =" ..a-b)
print("a * b =" ..a*b)
print("a / b =" ..a/b)
print("a ^ b =" ..a^b)
print("  - a =" ..-a)
print("a == b " ..tostring(a==b))
print("a ~= b " ..tostring(a~=b))
print("a >= b " ..tostring(a>=b))
print("a <= b " ..tostring(a<=b))
print("a > b " ..tostring(a>b))
print("a < b " ..tostring(a<b))
a = true
b = false
print("a = " ..tostring(a).." b = "..tostring(b))
print("a & b = "..tostring(a and b))
print("a | b = "..tostring(a or b))
print("not a = "..tostring(not  a))

print("--- string opration ---")
s = "abc_DEF_123,4a56,78a9,'\"["
print("Origin string is 【"..s.."】")
print("Upper : "..string.upper( s ))
print("Lower : "..string.lower( s ))
print("Replace : "..string.gsub(s,"a" ,"x"))
print("Find : "..string.find(s,"D"))
print("Reverse : "..string.reverse(s))
print("Format :"..string.format( "this number is %d",998 ))
print("Char to string :"..string.char(99,100,101,106))
print("Char to number :"..string.byte('A'))
print("Char to number index :"..string.byte('ABC',2))
print("Length :"..string.len(s))
print("Rep :"..string.rep(s,2))

print("--- string format ---")
print("%c "..string.format( "%c",83))
print("%d %i %u "..string.format( "%d %i %u",-8.3,-8.4,-8.5))
print("%f %e %E "..string.format( "%f %e %E",8.003,8.004,8.005))
print("%f %g %G "..string.format( "%f %g %G",8.003,8.004,8.005))
print("%d %o %x %X "..string.format( "%d %o %x %X",78,78,78,78))
print("%s %5s %2.1s %q "..string.format( "%s %5s %2.3s %q ","ABCD","ABCD","ABCD","AB\tCD"))

print("--- string pattern match ---")
print("string.find() string.gmatch() string.gsub() string.match()")
local match =[[
    . 与任何字符匹配
    %a 与任何字母匹配
    %c 与任何控制字符匹配
]]
print()

-- 启用lua 交互模式
-- lua -i 或者 lua

-- 基本语法
-- 单行注释 --
-- 多行注释
--[[
这里是多行
注释
定义标识符:以字母、下划线、开头可以含有数字（下划线+大写字母 为lua的保留字）
不能使用@ # %
lua区分大小写编程

lua的保留字

and         break       do      else
elseif      end         false   for
function    if          in      local
nil         not         or      repeat
return      then        true    util
while       goto

默认情况下 变量都是全局的，全局变量不需要声明 赋值后即创建
访问为赋值的全局变量结果为：nil
删除全局变量--->将变量赋值为nill,EG:n=nil

lua数据类型
lua为动态语言，变量不需要定义类型，只需赋值
lua的基本类型
nil         无效值
boolean     布尔型：true/false
number      双精度浮点实数
string      字符串，双引号或者单引号表示
function    由C或者lua编写的函数
userdata    任意存储在变量中的C数据结构
thread      执行的独立线程
table       关联数组，索引可以是数字、字符串、表，创建{}

字符串

连接字符串：..
测量字符串长度：#

表 table
索引默认从1开始

函数 function

function [FunctionName]([ParamName1]，[ParamName1]，[ParamName1])
    [函数体...]
end

可以定义匿名函数
function([ParamName1],[ParamName2])
    [函数体...]
end

函数可以存放人变量
xx = func_Add

变量

变量作用域：全局变量、局部变量、表中的域
除非使用[loacl]进行定义限定，否则变量都是全局变量，不论变量定义在何处（语句块 函数内）
局部变量的作用域：从声明开始到所在语句块结束
变量的默认值都是 nil
多个变量同时赋值
a,b,c = 100,200,300
lua赋值会先进行右侧计数然后赋值
x,y=y,x
赋值数量不一致时 策略：
a. 变量个数 > 值的个数             按变量个数补足nil
b. 变量个数 < 值的个数             多余的值会被忽略

索引

针对table
可以使用[]进行索引
t[i] 
t.i  当索引为字符串时
索引的本质：t[i] == gettable_event(t,i) 

循环
while循环
while[condition]
do
    [循环体]
end

数值for循环
for var=v1,v2,v3 do
    [循环体]
end

数值for循环

for var=[start],[end],[step] do
    [循环体]
end

泛型for
a = {"one", "two", "three"}
for i, v in ipairs(a) do
    print(i, v)
end 

repeat
   statements
until( condition )

允许循环嵌套

lua函数

默认情况下定义都是全局函数
通过限定词 local 可以将函数限定为局部函数

local function myFunc(n)

end

--]]
