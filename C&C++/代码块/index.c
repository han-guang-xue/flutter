#include <stdio.h>
int b (int c) {
    printf("外部代码块 %d \n", c);
};
int main(int argc, char const *argv[])
{
    {
        printf("代码块哦 \n");
    }
    b(4);
    return 0;
}

