/**
 * 联合中的所有成员引用的是内存中相同的位置,
 * 当你想在不同的时刻把不同的东西存储于同一个位置,可以使用该结构 
 * 
 * 结构体的各个成员会占用不同的内存，互相之间没有影响；
 * 而共用体的所有成员占用同一段内存，修改一个成员会影响其余所有成员。
 */
typedef union
{
    float f;
    int a;
} f1;

#include <stdio.h>

int main(int argc, char const *argv[])
{
    f1 f;
    f.f = 2.23;
    f.a = 100;

    printf("%g", f.f);
    return 0;
}
