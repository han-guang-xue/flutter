# synchronized

## 1. 对象的组成 

>  monitorenter,  monitorexit(第一个是代码运行完释放锁, 第二个是抛异常释放锁)

**对象在堆内存上分配多少内存?**

> 64 位的JVM 要求对象的大小要求是八的整数位, 比如一个boolean占一个字节,但是类加载的时候会分配给八个字节

**Java的对象分为三块区域**

1. java对象实例数据 --- 不固定
2. 对象头 --- 固定 (1字节(bit) = 8byte) ,以下代码测试得出96bit
3. 数据对齐 (如果示例数据和对象头不够把的倍数,则会有数据填充,否则不包含这块)

加入jar包

```xml
<dependency>
    <groupId>org.openjdk.jol</groupId>
    <artifactId>jol-core</artifactId>
    <version>0.9</version>
</dependency>
```

使用以下代码输出示例类信息

```java
System.out.println(ClassLayout.parseInstance(a).toPrintable());
```

```java
package com.han.dome.study.day1;

public class A {
    private int flag = 2;
    private boolean flag1 = true;
}

输出结果
com.han.dome.study.day1.A object internals:
 OFFSET  SIZE      TYPE DESCRIPTION                               VALUE
      0     4           (object header)                           01 00 00 00 (00000001 00000000 00000000 00000000) (1)
      4     4           (object header)                           00 00 00 00 (00000000 00000000 00000000 00000000) (0)
      8     4           (object header)                           43 c1 00 f8 (01000011 11000001 00000000 11111000) (-134168253)
     12     4       int A.flag                                    2
     16     1   boolean A.flag1                                   true
     17     7           (loss due to the next object alignment)
Instance size: 24 bytes
Space losses: 0 bytes internal + 7 bytes external = 7 bytes total
```



```java
public class Test {

    static A a = new A();   

    public static void main(String[] args) {
        lockTest();
    }

    public static void lockTest() {
        /**
         * 给对象 a 上锁
         */
        synchronized (a) {
            System.out.println("XXXXXX");
        }
    }

}
```

## 2. 对象头由什么组成 (object header)

> 对象头构成, 有JVM指定的规范 http://openjdk.java.net/groups/hotspot/docs/HotSpotGlossary.html 
>
> Common structure at the beginning of every GC-managed heap object. (Every oop points to an object header.) Includes fundamental information about the heap object's layout, type, GC state, synchronization state, and identity hash code. Consists of two words. In arrays it is immediately followed by a length field. Note that both Java objects and VM-internal objects have a common object header format
>
> 译文:
> 每个GC管理的堆对象开头的通用结构。 （每个oop都指向对象标头。）包括有关堆对象的布局，类型，GC状态，同步状态和标识哈希码的基本信息。 由两个字长组成。 在数组中，紧随其后的是长度字段。 请注意，Java对象和VM内部对象都具有通用的对象标头格式

1. Mark Word: 存储对象的HashCode,锁信息或分代年龄或GC标记等信息

   ```json
   
   ```

   

2. Class Metadata Address: 类型指针指向对象的类元数据,JVM通过这个指针确定该对象是那个类的示例

> 如何证明

1. 当前使用的虚拟机是什么?

2. 什么是JVM? 什么是HotSpot(sun)?

   JVM 是一个规范/标准, HotSpot 是一个JVM的实现, 除了HotSport ,还有(J9, taobaovm-淘宝, mic-微软),这些都是遵循了JVM规范

   > 注: HotSpot 是用 C++ 开发的 项目openjdk 运行的程序, openjdk 源码下载 http://hg.openjdk.java.net/

## 3. 锁类型 

### 3.1偏向锁,轻量锁(自旋锁),重量锁

一个普通对象 synchronized 修饰, 会升级偏向锁, 如果出现轻度竞争,会出现轻量锁, 竞争很激烈时,会升级重量锁

| 锁状态      | 25 bit | 31bit                | 1bit   | 4bit     | 1bit (偏向锁位) | 2bit (锁标记位) |
| ----------- | ------ | -------------------- | ------ | -------- | --------------- | --------------- |
| 无态锁(new) | unused | hashcode(如果有调用) | unused | 分代年龄 | 0               | 0 \| 1          |

| 锁状态 | 54bit                | 2bit   | 1bit | 4bit   | 1bit (偏向锁位) | 2bit (锁标记位) |
| ------ | ------ | -------------------- | ------ | -------- | --------------- | --------------- |
| 偏向锁 | 当前线程指针 JavaThread | Epoch | unused | 分代年龄 | 1               |0 \| 1|


| 锁状态                | 62位                             | 2bit   |
| --------------------- | -------------------------------- | ------ |
| 轻量级锁(自旋锁,无锁) | 指向线程栈中的Lock Record 的指针 | 0 \| 0 |
| 重量级锁              | 指向互斥量(重量级锁)的指针       | 1 \| 0 |
| GC标记信息            | CMS过程中用到的标记信息          | 1 \| 1 |

#### identityHashCode 与hashCode

每个对象的hashCode 生成的方法是可以被重写的,  identityHashCode 在HashCode 没有重写之前是一样的,重写之后就不一样,   identityHashCode 可以用于引用对象的地址

### 3.2锁升级

**偏向锁**

如果当前资源在大多数情况下只有某一个线程使用, 则该资源就指向使用它的线程ID  JavaThread*, 该情况下没有必要设置竞争机制, 将当前线程的指针写入 markword 中

**轻量级锁**

有两个线程,抢占一个资源, 其中某一个会优先占去到资源, 则该线程会将自己的lock record 指针记录 指向被当前资源线程, 而另外一个线程以自旋的方式等待当前线程执行完毕;

**重量级锁** (非用户状态)

当自旋锁的线程多的时候,对CPU资源的消耗大,所以会向CPU申请锁, CPU会将这些进程放在一个队列中挨个执行, liunx CPU 采用的是CFS(完全公平策略机制)调度算法

### 3.4 偏向锁和轻量级锁(自旋锁)的选择和开启

00 -> 轻量级锁

轻量级锁开启延时默认4s

```shell
-xx:BiasedLockingStartupDelay=0
```

因为JVM虚拟机有一些默认的启动线程,里面有Sync修饰的代码块,这时候JVM知道线程会竞争资源, 于是会默认开启偏向锁, 如果默认开启自旋锁,就会造成偏向锁不断的进行锁的撤销和升级的过程.效率较低

### 3.5 大纲

![image-20201021140734596](D:\MINTOOL\dostop\mine\flutter\java\阿里P7级Java架构师课程笔记\sync锁.assets\image-20201021140734596.png)

## 4. 锁重入

> synchronized 是可重入锁, 重入次数必须记录,需要解锁,不同的锁记录的地方不一样

| 锁类型   | 记录地址 | 记录方式            |
| -------- | -------- | ------------------- |
| 偏向锁   | 线程栈   | LR + 1 (每重入一次) |
| 轻量级锁 |          |                     |
| 重量级锁 |          |                     |

> lock record 第一次记录重入次数,  会将markword 拷贝到 DisplayedMarkWord中, 第二次记录重入次数会新增一个 空的 LR;





## 5. 用户态和内核态





















# 学习资料

1.1 *GNU* make手册:

中文: http://blogimg.chinaunix.net/blog/upfile/070907021605.pdf

英文: http://www.gnu.org/software/make/manual/

1.2 C/C++语言教材:

<<C程序设计语言>>: http://book.douban.com/subject/1139336/

<<*C* *Primer* Plus>>: http://book.douban.com/subject/1240002/

<<C++ *Primer* Plus, 6th Edition>>: http://book.douban.com/subject/10789789/

<<C++ Primer>>: http://book.douban.com/subject/25708312/

1.3 JVM相关:

<<深入Java虚拟机(原书第2版)>>: http://book.douban.com/subject/1138768/

<<深入理解Java虚拟机>>: http://book.douban.com/subject/24722612/

<<HotSpot实战>>: http://book.douban.com/subject/25847620/

<<Java性能优化权威指南>>: http://book.douban.com/subject/25828043/

<<*Java* *Language* and *Virtual* *Machine* Specifications>>1.1 *GNU* make手册:

中文: http://blogimg.chinaunix.net/blog/upfile/070907021605.pdf

英文: http://www.gnu.org/software/make/manual/

1.2 C/C++语言教材:

<<C程序设计语言>>: http://book.douban.com/subject/1139336/

<<*C* *Primer* Plus>>: http://book.douban.com/subject/1240002/

<<C++ *Primer* Plus, 6th Edition>>: http://book.douban.com/subject/10789789/

<<C++ Primer>>: http://book.douban.com/subject/25708312/

1.3 JVM相关:

<<深入Java虚拟机(原书第2版)>>: http://book.douban.com/subject/1138768/

<<深入理解Java虚拟机>>: http://book.douban.com/subject/24722612/

<<HotSpot实战>>: http://book.douban.com/subject/25847620/

<<Java性能优化权威指南>>: http://book.douban.com/subject/25828043/

<<*Java* *Language* and *Virtual* *Machine* Specifications>

http://docs.oracle.com/javase/specs/index.html

中文: http://www.iteye.com/topic/1117824

英文: http://docs.oracle.com/javase/specs/jvms/se7/jvms7.pdf

1.4 体系结构:

<<深入理解计算机系统>>: http://book.douban.com/subject/5333562/

1.5 Windows内核:

<<深入解析Windows操作系统>>: http://book.douban.com/subject/25844377/

<<Windows内核原理与实现>>: http://book.douban.com/subject/4719159/》

http://docs.oracle.com/javase/specs/index.html

中文: http://www.iteye.com/topic/1117824

英文: http://docs.oracle.com/javase/specs/jvms/se7/jvms7.pdf

1.4 体系结构:

<<深入理解计算机系统>>: http://book.douban.com/subject/5333562/

1.5 Windows内核:

<<深入解析Windows操作系统>>: http://book.douban.com/subject/25844377/

<<Windows内核原理与实现>>: http://book.douban.com/subject/4719159/