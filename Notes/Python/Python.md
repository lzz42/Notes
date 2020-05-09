# Python

## 函数与方法的区别 Function Method

- 参考：
  - https://segmentfault.com/a/1190000009157792
- Definition
  - Function： A series of statements which returns some value toa caller. It can also be passed zero or more arguments which may beused in the execution of the body.
  - Method：A function which is defined inside a class body. Ifcalled as an attribute of an instance of that class, the methodwill get the instance object as its first argument (which isusually called self).
- 区别：
  - Function：不需要类型，属于FunctionObject
  - Method：需要在类型内，属于PyMethodObject

## Bound Method and Unbound Method

- 区别：
  - BoundMethod：需要实例绑定，即，a.f()
  - UnboundMethod:不需要实例绑定，即：A.f(a)
  - 但都需要一个实例才能调用，两种方法本质上等价
- 定义：
  - 在类内定义方法都要显式传入self参数，self表示实例化的对象