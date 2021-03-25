/*
    第一， fun（int a）， 你调用fun（b）时 ， 传的是b的值的副本，当函数里面改变参数a时，只是改变了b的副本，对b没影响 ；
    第二， fun（int &a）， 你调用fun(b)时， 传的是b的内存地址啊， 说白了就是b， 函数中改变参数a就是改变b。
    值传递：一个是b的copy，
    地址传递：一个是b的内存地址
 */
#include <stdio.h>

void Func(int &nVal1);
void Func1(int nVal1);

int main(int argc, char const *argv[])
{
    printf("%d\n", ~10);  //-11  // ~代表求补码, 补码的方式: 求反码 + 1
    printf("%0x\n", ~10); //fffffff5
    printf("%u\n", ~10);  //4294967285 //%u 代表以十进制形式输出无符号整数

    int a = 20;
    Func(a);
    printf("%d \n", a); //21

    int b = 20;
    Func1(b);
    printf("%d \n", b); //20

    char d = 128;        // char 的范围 -128~127
    printf("%0x \n", d); //ffffff80
    printf("%d \n", d);  //-128

    unsigned char e = 128;
    printf("%0x \n", e); //80
    printf("%d \n", e);  //128
    return 0;
}

void Func(int &nVal1)
{
    nVal1 += 1;
    printf("%d \n", nVal1);
}

void Func1(int nVal1)
{
    nVal1 += 1;
    printf("%d \n", nVal1);
}