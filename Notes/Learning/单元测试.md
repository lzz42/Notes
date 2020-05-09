# UnitTest

- 参考资料：
- [博客园文章](http://www.cnblogs.com/yubaolee/p/DotNetCoreUnitTest.html)

## 使用MSTest.TestFramework

- 安装使用MSTest.TestFramework
- 条件：.net4.5以上
- 安装完Nuget包后，新建测试类型
- 在测试类型添加特性**[TestClass]**
- 在测试类型的测试方法添加特性**[TestMethod]**

```C#
[TestClass]
public class TestMain
{
    [TestMethod]
    public void TestITarget()
    {
    }
}
```

- 测试方法内：使用Assert断言验证测试方法结果

### 使用Moq模拟测试

- 参考资料：
- [moq4 GitHub源代码](https://github.com/moq/moq4)
- [博客园文章](https://www.cnblogs.com/haogj/archive/2011/07/22/2113496.html)
- [博客园文章](https://www.cnblogs.com/cgzl/p/9294431.html)

- 1.添加Moq引用；
- 2.初始化要模拟的接口对象：
  - a.可指定Mock行为：Strict：严格，未指定操作时抛出异常；Loose：宽泛的，未指定操作时返回默认值；Default：默认为Loose
  - b.可以指定多个接口：

```C#
mo.As<T2>();
```

- 3.指定接口参数和返回值；
  - a.可以使用It指定参数规则
  - b.可以定义返回值规则
  - c.可以根据不同参数指定抛出异常
  - d.可以触发事件
- 4.调用；
- 5.断言结果；

```C#
var mo = new Mock<T>(); 
// 此处可以指定Mock行为：即未指定方法时如何操作抛出异常还是返回默认值
//var mo = new Mock<T>(MockBehavior.Strict);
//指定方法参数和返回值
mo.Setup(i=>i.SomeMethod([paras])).Returns([para]);
//调用方法
va r= mo.Object.SomeMethod([paras]);
//断言 结果
Assert。。。
```

### 常见问题

- 1.在VS中使用MSTest，在引入MSTest Nuget包后，写完测试方法后，不能正常进行单元测试运行与调试，输出窗口输出：测试项目****未引用任何 .NET NuGet 适配器 的问题
  - 解决：在测试项目中引入MSTest.TestAdapter,即可。
  - 原因：英文版 [微软官网说明](https://docs.microsoft.com/zh-cn/visualstudio/test/test-explorer-faq?view=vs-2017)
- 2.00
