#include <stdio.h>

int main(int argc, char const *argv[])
{
    typedef char *ptr_to_char;
    ptr_to_char a;
    printf("%x \n", a);

    int num[2];
    num[0] = 10; num[1] = 20;
    printf("%d, %d \n", num[0],num[1]);

    typedef int num1[2];
    num1 b;
    b[0] = 10, b[1] = 20;
    printf("%d, %d", b[0],b[1]);
    return 0;
}
