int  a = 5;
#include <stdio.h>

int main(int argc, char const *argv[])
{
    extern a; //声明变量, 就是其他地方定义了,这边需要用,声明一下
    printf("%d", a);

    return 0;
}


