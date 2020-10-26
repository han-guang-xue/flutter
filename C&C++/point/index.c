#include <stdio.h>

#include "swap.c"

//声明使用
extern void swap(int *a,int *b);

int main(int argc, char const *argv[])
{


    int a = 4, b = 6;

    swap(&a, &b);

    int *p1 = &a, *p2 = &b;

    printf("%d", *p1 + *p2); 
    
    return 0;
}

