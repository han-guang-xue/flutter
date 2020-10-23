# redis
## springboot整合 redis
> springboot 2.x 之后, jedis 替换为lettuce

+ jedis: 采用的直连,多个线程下操作不安全, 需要使用 jedis pool 连接池 BIO
+ lettuce: Lettuce的连接是基于Netty的，连接实例（StatefulRedisConnection）可以在多个线程间并发访问，应为StatefulRedisConnection是线程安全的，所以一个连接实例（StatefulRedisConnection）就可以满足多线程环境下的并发访问，当然这个也是可伸缩的设计，一个连接实例不够的情况也可以按需增加连接实例。
 lettuce主要利用netty实现与redis的同步和异步通信。

> redis 序列话需要默认使用的是jdk的(需要改用string 的序列化操作)

> redis 配置文件

```bash
daemonize yes #是否以守护进程启用
```

