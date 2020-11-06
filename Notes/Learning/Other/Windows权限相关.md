# windows权限编程相关

## windows权限控制

- 权限控制只能以资源为对象，即以资源为主

## 权限与角色

## 代码安全等级

## 权限获取和设置

## 安全标识符 访问控制表 安全主体

- 安全标识符 SID security  identifier 唯一性不会重复的数值
  - 应用于系统内容所有用户、组、服务、计算机
- 访问控制列表 ACL access control list
  - 权限列表，用于定义特定用户对于某个资源的访问权限，在该列表中每个用户都对应一组访问控制项ACE Access Control Entry
- 安全主体 security principal
  - 用户、组、计算机、服务都是一个安全主体，每个安全主体有对应的账户名称和SID
  - 权限的派生过程就是为某个资源分配安全主体可以拥有怎样操作的过程

## 基本原则

- 拒绝优先于允许原则
  - 解决权限冲突问题
  - 处理多个权限纠纷问题
- 权限最小化原则
  - 保障资源安全
  - 保持用户最小权限，即必须为资源明确赋予某些操作权限
- 权限继承性原则
  - 自动化执行权限设置
- 累加原则
  - 权限设置更加灵活

## Windows NT用户组概况

- Administrator
  - 默认该组内用户对计算机或者域具有不受限制的完全访问权
- Power User
  - 高级用户组，可以执行除Administrator组保留任务外的其他任何操作系统任务，默认分配允许修改整个计算机设置，但不允许将自己添加到Administrator组中
- Users
  - 普通用户组，默认权限不允许成员修改操作系统设置以及用户资料
- Guests
  - 来宾组，权限比Users更低
- Everyone
  - 所有用户组，计算机上所有用户都属于该组
- System
  - 拥有比Administrator同样或更高权限，该组不允许任何用户加入，只有一个system用户

## 参考资料

- https://www.cnblogs.com/milantgh/p/3617855.html
- https://www.jianshu.com/p/8efaf3f93488
- https://www.cnblogs.com/foohack/p/6698672.html