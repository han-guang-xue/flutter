/**
 * 结构体的内存分配, 边界对齐
 *   以4的整数倍存储, 如果一个char类型占一个字节和三个空字节,顺序存储
 *   比如stu  结构体使用8个字节存储
 *   但是stu1 结构需要12个字节存储
 */

typedef struct
{
    char a;
    int c;
    char b;
} stu1;

typedef struct student
{
    char a;
    char b;
    int c;
} stu;

#include <stdio.h>

int main(int argc, char const *argv[])
{
    stu stu1;
    stu1.a = 'A', stu1.b = 'C', stu1.c = 100;
    stu *p = &stu1;
    printf("%d \n", stu1.c);
    printf("%d \n", p->c);
    return 0;
}



/**
 * 位段 
 * 
 * 注: 无符号（unsigned）和有符号（signed）两种类型（float和double总是带符号的），
 * char在默认情况下总是无符号的。在除char以外的数据类型中，如果需声明无符号类型的话就需要在类型前加上unsigned。
 * 无符号版本和有符号版本的区别就是无符号类型能保存2倍于有符号类型的正整数数据，
 * 比如16位系统中一个short能存储的数据的范围为-32768~32767，
 * 而unsigned能存储的数据范围则是0~65535。
 * 
 */
typedef struct 
{
    unsigned a : 1;
    unsigned b : 4;
    unsigned c : 10;
};

