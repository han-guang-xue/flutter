### Java 中有 8 种基本数据类型 byte,int,short,long,float,double,char,boolean;其中：

byte 占 1 个字节 8 位，取值范围为-2^7~2^7-1

int 占 4 个字节 32 位，取值范围为-2^31~2^31-1

short 占 2 个字节 16 位，取值范围为-2^15~2^15-1

long 占 8 个字节 64 位，取值范围为-2^63 ～ 2^63-1

float 占 4 个字节 32 位，取值范围为 3.402823e+38 ~ 1.401298e-45

double 占 8 个字节 64 位，取值范围为 1.797693e+308~ 4.9000000e-324

char 占 2 个字节 16 位，取值范围为 0 ～ 65535

test 

boolean 即 true 或 false, 不同虚拟机, 对 boolean 和 boolean 数组的存储长度都不同, eg: 在 Oracle 的 Java 虚拟机实现中，Java 编程语言中的 boolean 数组被编码为 Java 虚拟机 byte 数组，每个布尔元素使用 8 位。
