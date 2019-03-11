# VSCT文件

> [VSCT XML架构参考]:(https://docs.microsoft.com/zh-cn/visualstudio/extensibility/vsct-xml-schema-reference)
- 作用：1.定义用户对象、所需资源以及代码绑定行为：2.提供了命令编译架构元素的表，基于XML表配置文件，其中定义了由VSPackage提供的的IDE的命令元素
- 命令元素包括：菜单项、菜单、工具栏、组合窗
- VSCT编译器可以在vsct文件上运行预编译程序，由于是典型的C++预编译程序，所以你可以使用C++文件中的同样的符号来定义自己的包含项和宏命令(macros)
- 可选元素
- 有些VSCT元素是可选的。如果一个Parent参数没有指定，将会暗指Group_Undefined:0。
- 若Icon参数没有指定，则默认为guidOfficeIcon:msotcidNoIcon
- 所有的GUID和ID值都必须使用符号化的名称。这些名称可以定义在头文件中或者vsct文件的Symbols区域内。这些符号名称必须是本都额包含<Include> 元素。
- 根元素：CommandTable，指定namespace和xml架构
- 对象标识：guid+数字
- 头文件：*.h 允许从外部加载对象标识
- stdidcmd.h:包含VS公开的所有命令ID，菜单项以cmdid开头，标准编辑器命令以ECMD_开头
- vsshlids.h:包括VS外壳听的菜单命令ID
- msobtnid.h:包括MS office中用到的命令ID
- 可以在Symbols节点为以上GUID和命令ID设定标识

## CommadnTable元素

- vsct根元素
- 结构

```XML
<CommandTable xmlns="http://schemas.microsoft.com/VisualStudio/2005-10-18/CommandTable" xmlns:xs="http://www.w3.org/2001/XMLSchema" >  
  <Extern>... </Extern>  
  <Include>... </Include>  
  <Define>... </Define>  
  <Commands>... </Commands>  
  <CommandPlacements>... </CommandPlacements>  
  <VisibilityConstraints>... </VisibilityConstraints>  
  <KeyBindings>... </KeyBindings>  
  <UsedCommands... </UsedCommands>  
  <Symbols>... </Symbols>  
</CommandTable>
```

- 特性:xmlns - 必须的 language- 可选
- Extern 编译器预处理指令，编译时需要合并的外部头文件，该头文件路径必须再Include指定或者VSCT编译器的指定路径，文件可以是其他vsct文件或者C++头文件
- Include 包含在编译的文件路径
- Define 定义更新名称和值的符号
- Commands 定了一所有的VSPackage命令的父元素
- CommandPlacements 定义命令放在命令栏的位置
- VisibilityConstraints 决定了命令和工具栏的静态可见属性
- KeyBindings 指定组合快捷键
- UsedCommands 允许VSPackage实现自己版本的功能并且被其他VSPackage原生支持
- Symbols 包含编译器的所有的符号数据，GUID ID

### Extern

- 定义格式必须为

```C++
 #define [符号] [值]
 //值也可能是其他符号
```

- 特性：
> href 必须  头文件路径
> Condition 可选
> Language 可选

### Include

- 指定了要插入当前文件的位于支持路径下的文件，其中所有的元素和定义类型都将成为编译结果的一部分
- VS2010头文件位置：C:\Program Files (x86)\Microsoft Visual Studio 2010 SDK\VisualStudioIntegration\Common\Inc
- VS2017头文件位置：C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VSSDK\VisualStudioIntegration\Common\Inc

```xml
<Include href="stdidcmd.h" />  
```

- 特性:
> href 必须 头文件路径
> Condition 可选

## Define

- 定义具有名称和值的符号

```xml
<Define name="Mode" value="Standard" />
```

## Commands

- 工具栏上命令的集合：菜单、组、按钮、组合、位图
- 每个子元素由命令ID标识：GUID和数字标识对

```xml
<Commands package="GuidMyPackage" >  
  <Menus>... </Menus>  
  <Groups>... </Groups>  
  <Buttons>... </Buttons>  
  <Combos>... </Combos>  
  <Bitmaps>... </Bitmaps>  
</Commands>  
```

- 特性
> package 标识提供命令的VSPackage的GUID

### Menus 

> 定义所有菜单和工具栏的VSPackage实现

``` xml
<Menus>  
  <Menu>... </Menu>  
  <Menu>... </Menu>  
</Menus>  
```

- Menu
> 定义一个菜单项，有6种菜单：Context，Menu，MenuControler，ToolBar,ToolWindowToolBar

``` xml
<Menu guid="guidMyCommandSet" id="MyCommand" priority="0x100" type="button">  
  <Parent>... </Parent>  
  <CommandFlag>... </CommandFlag>  
  <Strings>... </Strings>  
</Menu>  
```

> 特性
>> GUID 必须，ID 必须
>> priority 可选，指定菜单相对位置的数字值
>> ToolbarPriorityInBand 可选 指定工具栏停靠时工具栏条上相对位置
>> type 可选 指定元素类型，默认值为Menu，
>>> Context 窗口右键菜单；

- Parent 父节点 用于指定菜单位置
- 对于VS中的显示位置的设置
- guid：应该从include中的头文件中进行查找
- ID：也应该从include中的头文件中进行查找，该值指定具体位置
- 对于VS一般从 vsshlids.h头文件中进行查找

```xml
<Parent guid="guidSHLMainMenu" id="IDG_VS_MM_BUILDDEBUGRUN" />
```

  |GUID|ID|位置|应用类型|
  |----|----|----|---|
  |guidSHLMainMenu|IDG_VS_MM_BUILDDEBUGRUN|主菜单|Menu|
  |guidSHLMainMenu|IDG_VS_TOOLS_OPTIONS|工具菜单下拉列表|Group/Menu|
  |guidSHLMainMenu|IDG_VS_CTXT_SOLUTION_BUILD|解决方案右键菜单|Menu|
  |guidSHLMainMenu|IDG_VS_CTXT_PROJECT_ADD|工程右键菜单|Menu|
  |guidSHLMainMenu|IDM_VS_CTXT_CODEWIN|代码菜单|Group|
  |guidSHLMainMenu|IDM_VS_CTXT_REFERENCEROOT|引用|Group|
  |guidSHLMainMenu|IDM_VS_CTXT_REFERENCE|引用下的自节点引用|Group|
  |guidSHLMainMenu|IDM_VS_CTXT_PROJNODE|工程节点|Group|
  |guidSHLMainMenu|IDM_VS_CTXT_SOLNNODE|解决方案节点|Group|

### Groups

> 包含VSPackage命令组入口

``` xml
<Groups>  
  <Group>... </Group>  
  <Group>... </Group>  
</Groups>  
```

- Group
> 定义VSPackage命令的组

``` xml
<Group guid="guidMyCommandSet" id="MyGroup" priority="0x101">  
  <Parent>... </Parent>  
</Group>  
```

### Buttons

> 表示单个Button元素的组

``` xml
<Buttons>  
  <Button>... </Button>  
  <Button>... </Button>  
</Buttons>  
```

- Button
> 定义按钮相关内容：位置（父节点）、图标、命令、文本内容

``` xml
<Button guid="guidMyCommandSet" id="MyCommand" priority="0x102" type="button">  
  <Parent>... </Parent>  
  <Icon>... </Icon>  
  <CommandFlag>... </CommandFlag>  
  <Strings>... </Strings>  
</Button>  
```

- CommandFlag 命令标记用于控制命令的行为

### 控制菜单和名字位置

- 1.定义GUID和ID
  - 所有的元素都必须在Symbols下定义GUID和ID方可使用包括：
  - 1.Button Menu Group Bitmap 
- 2.定义Button位置
  - Button=》Group=》Group。。。=》Menu=>VS IDE中的GUID和ID定义位置
  - 命令组重用
  - 在CommandPlacements组下新建节点CommandPlacement GUID和ID为要重用的位置的Gruop项，不能直接设置button只能设置group
  - Parent下定义重用出现的位置
  - 在CommandPlacements可以添加多个相同的GUID和ID的CommandPlacement元素
- IDE中定义位置：Menu Group只能定义Menu元素，Menus中才能定义Group元素
- 即：Menus的parent元素定义应该是MenusGroup类型的，Group的Parent元素应该是Menus类型的 具体应该看IDE说明
- vsshlids.h
