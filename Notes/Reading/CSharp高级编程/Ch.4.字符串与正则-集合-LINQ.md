# C#高级编程

## 字符串

- string映射System.String类型，
- System.Text和System.Text.RegularExpressions
  - 1.创建字符串---可以考虑使用System.Text.StringBulider
  - 2.格式化表达式---使用接口IFormatProvider和IFormattable处理
  - 3.正则表达式---识别字符串、提取子字符串System
- System.String类
- 1.string类常用方法
  - Compare、CompareOriginal、Contact、CopyTo、Format、IndexOf、IndexOfAny、Insert、Join、LastIndexOf、
  - LastIndexOfAny、PadLeft、PadRight、Replace、Split、SubString、Trim、ToLower、ToUpper
- 2.创建字符串
  - 重复修改字符串，效率很低。
  - string为不可变的数据类型，一旦初始化该对象就不能再改变
  - StringBuilder类仅限对字符串进行替换、追加、删除、修改处理  
  - （需引用namespace：System.Text）
  - StringBuilder类属性：Length-字符串的实际长度；Capacity-字符串分配在内存的最大长度；
  - 初始化时指定内存初始容量，在内存中操作，若内存不够，则自动进行容量翻倍
  - StringBuilder成员：
  - 1.构造函数可以指定字符串或容量，也可以设置MaxCapacity最大容量
- 3.格式化字符串
  - .NET定义标准方式：IFormattable接口
  - 格式说明符{obj,len:FormatStr}    eg:{0,10:E}
  - 格式化过程：传递给格式化函数，对象，格式说明符
  - 1.首先检查该对象是否实现了IFormattable接口（使用is关键字测试或者强制转换测试）；
  - 2.若测试失败则执行该对象的ToString()方法；
- IFormattable接口
  - 只有一个方法string ToString(string,IFormatProvider);

## 正则表达式

- 