# Lab2

**PB18111697 王章瀚**

本次实验(Lab2)的所有文件都位于仓库根目录下的./lab2中. 

- [评分前请阅读](#%e8%af%84%e5%88%86%e5%89%8d%e8%af%b7%e9%98%85%e8%af%bb)
- [使用 strace 工具追踪系统调用](#%e4%bd%bf%e7%94%a8-strace-%e5%b7%a5%e5%85%b7%e8%bf%bd%e8%b8%aa%e7%b3%bb%e7%bb%9f%e8%b0%83%e7%94%a8)
  - [代码中没出现的系统调用1：fstat](#%e4%bb%a3%e7%a0%81%e4%b8%ad%e6%b2%a1%e5%87%ba%e7%8e%b0%e7%9a%84%e7%b3%bb%e7%bb%9f%e8%b0%83%e7%94%a81fstat)
  - [代码中没出现的系统调用2：mmap](#%e4%bb%a3%e7%a0%81%e4%b8%ad%e6%b2%a1%e5%87%ba%e7%8e%b0%e7%9a%84%e7%b3%bb%e7%bb%9f%e8%b0%83%e7%94%a82mmap)
  - [代码中没出现的系统调用3: mprotect](#%e4%bb%a3%e7%a0%81%e4%b8%ad%e6%b2%a1%e5%87%ba%e7%8e%b0%e7%9a%84%e7%b3%bb%e7%bb%9f%e8%b0%83%e7%94%a83-mprotect)
- [Shell实现的整体框架](#shell%e5%ae%9e%e7%8e%b0%e7%9a%84%e6%95%b4%e4%bd%93%e6%a1%86%e6%9e%b6)
- [示例输入及选做项目说明](#%e7%a4%ba%e4%be%8b%e8%be%93%e5%85%a5%e5%8f%8a%e9%80%89%e5%81%9a%e9%a1%b9%e7%9b%ae%e8%af%b4%e6%98%8e)
  - [管道支持](#%e7%ae%a1%e9%81%93%e6%94%af%e6%8c%81)
  - [重定向支持](#%e9%87%8d%e5%ae%9a%e5%90%91%e6%94%af%e6%8c%81)
  - [管道和重定向的混合使用](#%e7%ae%a1%e9%81%93%e5%92%8c%e9%87%8d%e5%ae%9a%e5%90%91%e7%9a%84%e6%b7%b7%e5%90%88%e4%bd%bf%e7%94%a8)
  - [处理Ctrl-C的按键](#%e5%a4%84%e7%90%86ctrl-c%e7%9a%84%e6%8c%89%e9%94%ae)
  - [支持 Bash 风格的 TCP 重定向（选做）](#%e6%94%af%e6%8c%81-bash-%e9%a3%8e%e6%a0%bc%e7%9a%84-tcp-%e9%87%8d%e5%ae%9a%e5%90%91%e9%80%89%e5%81%9a)
  - [支持基于文件描述符的文件重定向、文件重定向组合（选做）](#%e6%94%af%e6%8c%81%e5%9f%ba%e4%ba%8e%e6%96%87%e4%bb%b6%e6%8f%8f%e8%bf%b0%e7%ac%a6%e7%9a%84%e6%96%87%e4%bb%b6%e9%87%8d%e5%ae%9a%e5%90%91%e6%96%87%e4%bb%b6%e9%87%8d%e5%ae%9a%e5%90%91%e7%bb%84%e5%90%88%e9%80%89%e5%81%9a)

## 评分前请阅读

1. 本程序中shell.c调用了command.h和command.c里的相关内容，需链接，但可以直接使用Makefile进行编译。
2. 实验要求中的使用strace工具追踪系统调用的相关回答在[这里](#%e4%bd%bf%e7%94%a8-strace-%e5%b7%a5%e5%85%b7%e8%bf%bd%e8%b8%aa%e7%b3%bb%e7%bb%9f%e8%b0%83%e7%94%a8). 选取了`fstat`, `mmap`, `mprotect`这三个函数.
3. 为了方便助教评分, 且防止误判, 对完成了的实验(包括两项选做内容)给出了一些[输入样例](#%e7%a4%ba%e4%be%8b%e8%be%93%e5%85%a5%e5%8f%8a%e9%80%89%e5%81%9a%e9%a1%b9%e7%9b%ae%e8%af%b4%e6%98%8e).
4. 请注意关于重定向等地方如果后接文件名，必须要空格隔开等. (详细规则在[这里](#inputrule)有介绍)
5. 如果一次复制多行输入进来，可能会造成输出混乱. 因为这里使用的是fgets, 并不能做到当输入到回车换行时就执行当条命令; 也不能做到先回显回车换行前的命令，等执行下一条命令前再继续回显下一条命令. 具体例子在[这里](#echoproblem)说明了.

## 使用 strace 工具追踪系统调用

### 代码中没出现的系统调用1：fstat

这个系统调用实现了由文件描述词取得文件状态. 

#### 函数定义
```c
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int fstat(int fd, struct stat *buf);
```

#### 参数
- fd: 规定要检查的打开文件的文件描述符
- buf: 为`struct stat`结构体类型的变量

#### 返回值
- 0: 执行成功
- -1: 执行失败

#### 作用

`struct stat`结构体中包含了包括文件设备所在ID, 文件大小, 文件最近修改时间等各种文件信息, 因此可以从buf去获取文件的状态. 

### 代码中没出现的系统调用2：mmap

mmap将一个文件或者其它对象映射进内存. 文件被映射到多个页上, 如果文件的大小不是所有页的大小之和, 最后一个页不被使用的空间将会清零. mmap在用户空间映射调用系统中作用很大. 

#### 函数定义

函数头文件为`<sys/mman.h>`, 其原型是：
```c
void* mmap(void* start,size_t length,int prot,int flags,int fd,off_t offset);
```

#### 参数说明
- start：映射区的开始地址, 设置为0时表示由系统决定映射区的起始地址. 
- length：映射区的长度. //长度单位是 以字节为单位, 不足一内存页按一内存页处理
- prot：期望的内存保护标志, 不能与文件的打开模式冲突. 
- flags：指定映射对象的类型, 映射选项和映射页是否可以共享. 
- fd：有效的文件描述词. 一般是由open()函数返回, 其值也可以设置为-1, 此时需要指定
flags参数中的MAP_ANON,表明进行的是匿名映射. 
- off_toffset：被映射对象内容的起点. 

#### 返回值
成功执行时, mmap()返回被映射区的指针. 失败时, mmap()返回MAP_FAILED[其值为(void *)-1]. 

#### 函数作用

可以使得进程之间通过映射一个普通文件实现共享内存. 普通文件被映射到进程地址空间后, 进程可以像访问普通内存一样对文件进行访问, 不必再调用read(), write（）等操作.  

#### 参考资料
[百度百科：mmap （一种内存映射文件的方法）](https://baike.baidu.com/item/mmap/1322217?fr=aladdin)

### 代码中没出现的系统调用3: mprotect

#### 函数原型

```c
#include <unistd.h>
#include <sys/mmap.h>
int mprotect(const void *start, size_t len, int prot);
```

#### 参数说明

- start：修改的起始位置
- len：修改的大小
- prot：指定要修改成的值, 可取值如下：
  - PROT_READ: 表示内存段内的内容可写；
  - PROT_WRITE：表示内存段内的内容可读；
  - PROT_EXEC：表示内存段中的内容可执行；
  - PROT_NONE：表示内存段中的内容根本没法访问. 

#### 返回说明

- 执行成功: 返回0
- 执行失败: 返回-1, 并设置`errno`变量. 

#### 函数作用

如果调用进程内存访问行为侵犯了这些设置的保护属性，内核会为该进程产生 SIGSEGV （Segmentation fault，段错误）信号，并且终止该进程。

#### 参考资料
[Linux中mprotect()函数的用法](https://blog.csdn.net/roland_sun/article/details/33728955)

## Shell实现的整体框架

为了方便调试，在提示符`#`前加入和工作路径地址.

`command.h`及`command.c`中包含了对一条命令的处理, 其中`deal_cmd`函数接受一条命令的字符串, 即可返回一个`command`结构体的指针, 这个结构体中包含了拆分好了命令, 提取出的重定向信心等, 从而方便各种指令的运行. 

在管道的实现部分, 采用循环语句对所有`|`都生成了一个管道, 从而完成多重管道的命令. 

此外, 实现的选做项目有：
1. 支持 Bash 风格的 TCP 重定向（选做）
2. 支持基于文件描述符的文件重定向、文件重定向组合（选做）

尚存缺陷是对用户复制进来的多行输入无法一行一行地处理, 导致输出可能有混乱. 

如果用户输入不存在的指令, 可能会直接略过. 

## 示例输入及选做项目说明

以下给出一些示例输入, 以方便助教查看, 且能使输入遵循本代码的原则. 

选做项目有：
1. 支持 Bash 风格的 TCP 重定向（选做）
2. 支持基于文件描述符的文件重定向、文件重定向组合（选做）

### 管道支持

```bash
env | wc
```
```bash
ls | wc | wc
```

### 重定向支持

注意：本代码中的所有重定向应满足这样的<a id="inputrule">输入规则</a>：
1. 本代码中实现的重定向操作符模式有(其中x, y表示代表文件描述符的数字, filename为文件名)
   * `x>> filename`, `x>>y`, `>> filename`
   * `x>&y`
   * `x> filename`, `x>y`, `> filename`
   * `x<<< filename`
   * `x<< filename`
   * `x<&y`
   * `x< filename`, `x<y`, `< filename`
2. 如果是类似 `x>&y` 的格式(x和y为两个数字, 代表文件描述符), 则这几个字符之间不应出现任何空格
3. 如果是类似 `x> filename` 或 `> filename` 的格式, `x`和`>`之间不应有空格, 而`>`和文件名之间必须有空格. 

```bash
ls > out.txt
```
```bash
ls >> out.txt
```
```bash
ls 1>> out.txt
```
```bash
echo hello >> hello.txt
```
```bash
cat < out.txt
```
```bash
cat 0< out.txt
```

### 管道和重定向的混合使用

```bash
cat < hello.txt | wc >> out.txt
```

### 处理Ctrl-C的按键

其中^C表示输入按键Ctrl-C, 直接复制无效. 

```bash
ls /bin^C
sleep 999
^C
```

嵌套shell中

```bash
./sh
sleep 999
^C
^C
exit
exit
```

### 支持 Bash 风格的 TCP 重定向（选做）

#### `cmd > /dev/tcp/<host>/<port>`

先在一个终端输入以下命令

```bash
nc -l 1234
```

再在本shell输入

```bash
echo hello > /dev/tcp/127.0.0.1/1234
```

此时即可在第一个终端中得到输入`hello`

#### `cmd < /dev/tcp/<host>/<port>`

先在一个终端输入以下命令

```bash
nc -l 1234
```

再在本shell输入

```bash
cat < /dev/tcp/127.0.0.1/1234
```

此后在第一个终端输入, 都可以传送到shell中, 直到使用了Ctrl-C.


### 支持基于文件描述符的文件重定向、文件重定向组合（选做）

#### 基于文件描述符的文件重定向

首先假设一下C文件编译出了可执行文件`test`

```c
#include <unistd.h>
#include <string.h>

int main() {
    char str[100] = {0};
    read(20, str, 99);
    write(10, str, strlen(str));
    return 0;
}
```

这里的可执行文件`test`已上传到相同目录下, 可以直接调用.

然后执行
```bash
./test 30< hello.txt 20<&30 40> out.txt 10>&40
```
则`hello.txt`的内容被输出到`out.txt`中.


#### 其他重定向(`<<`, `<<<`)

##### <<

```bash
cat << EOF
this
output
EOF
```

> <a id="echoproblem">注(前述回显问题)</a>：这里如果直接复制进去, 会产生类似下面的结果, 但影响不大,且并非本课重点, 就没再修改了. 

```bash
this
output
EOF
> > > this
output
```

##### <<<

```bash
cat <<< hello
```