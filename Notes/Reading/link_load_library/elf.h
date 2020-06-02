

#define Elf32_Addr unsigned int
#define Elf32_Half unsigned short
#define Elf32_Off unsigned int
#define Elf32_Sword int
#define Elf32_Word unsigned int

#define Elf64_Addr long long
#define Elf64_Half unsigned short
#define Elf64_Off long long
#define Elf64_Sword int
#define Elf64_Word unsigned int

// 32位ELF文件头结构
typedef struct
{
    // Magic
    unsigned char e_ident[16];
    // elf文件类型
    Elf32_Half e_type;
    // elf文件CPU平台属性
    Elf32_Half e_machine;
    // elf版本号
    Elf32_Word e_version;
    // 入口地址 elf程序入口虚拟地址 entry point adress:0x0
    Elf32_Addr e_entry;
    // start of program headers:0 (bytes into file)
    Elf32_Off e_phoff;
    // 段表在文件中的偏移 start of section headers:xx(bytes into file)
    Elf32_Off e_shoff;
    // elf标识，用于标识elf文件平台相关属性
    Elf32_Word e_flags;
    // elf文件头本身大小 size of this headers
    Elf32_Half e_ehsize;
    // size of program headers
    Elf32_Half e_phentsize;
    // number of program headers
    Elf32_Half e_phnum;
    // 段表描述符大小 一般是sizeof(Elf32_Shdr) size of section headers 40(bytes)
    Elf32_Half e_shentsize;
    // 段表描述符数量 elf中拥有段数量 number of secton headers
    Elf32_Half e_shnum;
    // 段表字符串表所在的段在段表中的下标
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;

// 64位ELF文件头结构
typedef struct
{
    unsigned char e_ident[16];
    Elf64_Half e_type;
    Elf64_Half e_machine;
    Elf64_Word e_version;
    Elf64_Addr e_entry;
    Elf64_Off e_phoff;
    Elf64_Off e_shoff;
    Elf64_Word e_flags;
    Elf64_Half e_ehsize;
    Elf64_Half e_phentsize;
    Elf64_Half e_phnum;
    Elf64_Half e_shentsize;
    Elf64_Half e_shnum;
    Elf64_Half e_shstrndx;
} Elf64_Ehdr;

// 32位段表结构
typedef struct
{
    // section name 段名称 值：在字符串表.shstrtab中的偏移
    Elf32_Word sh_name;
    // 段类型
    Elf32_Word sh_type;
    // 段标识位
    Elf32_Word sh_flags;
    // 段虚拟地址
    Elf32_Addr sh_addr;
    // 段偏移，段在文件中的偏移
    Elf32_Off sh_offset;
    // 段长度
    Elf32_Word sh_size;
    // 段链接信息
    Elf32_Word sh_link;
    // 段链接信息
    Elf32_Word sh_info;
    // 段地址对齐 地址对齐数量的指数（2的指数）
    Elf32_Word sh_addralign;
    // 项长度，仅当某些需要固定大小项的段
    Elf32_Word sh_entsize;
} Elf32_Shdr;

// 段类型
enum Sh_Type{
    // 无效段
    SHT_NULL=0,
    // 程序段 代码段 数据段
    SHT_PROGBITS=1,
    // 段内容为符号
    SHT_SYMTAB=2,
    // 段内容为字符串
    SHT_STRTAB=3,
    // 重定位表
    SHT_RELA=4,
    // 哈希表
    SHT_HASH=5,
    // 动态链接信息
    SHT_DYNAMIC=6,
    // 提示信息
    SHT_NOTE=7,
    // 没有内容 .bss
    SHT_NOBITS=8,
    // 重定位信息
    SHT_REL=9,
    // 预留
    SHT_SHLIB=10,
    // 动态链接符号表
    SHT_DYNSYM=11,
};

enum Sh_Flag{
    // 在进程空间可写
    SHF_WRITE = 1,
    // 需要分配空间
    SHF_ALLOC = 1,
    // 可以执行
    SHF_EXECINSTR = 1,
};