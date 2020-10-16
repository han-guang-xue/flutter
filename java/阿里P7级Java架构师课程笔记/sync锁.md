# synchronized

## 对象的组成

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

## 对象头由什么组成 (object header)

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

   > 注: HotSpot 是用 C++ 开发的 项目openjdk 运行的程序

