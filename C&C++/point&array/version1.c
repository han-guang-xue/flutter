#include <stdio.h>
/**
 * 实现两个数组的拷贝 
 */
#define SIZE 50
int x[SIZE], y[SIZE];
int i; 
int *p1, *p2;
void init() {
    int i;
    for(i = 0; i < SIZE; i++) {
        x[i] = i*2;
    }
}
void version1() {
    for (i = 0; i < SIZE; i++)
    {
        y[i] = x[i];
    }
}

void version2() {
    for (i = 0, p1 = x, p2 = y; i < SIZE; i++)
    {
        *p2 ++ = *p1++;
    }
    
}

// 使用寄存器,消除指针的复制
void version3() {

    register int *p1, *p2;

    for (i = 0, p1 = x, p2 = y; i < SIZE; i++)
    {
        *p2 ++ = *p1++;
    }
    
}
// 消除计数器
void version4() {

    register int *p1, *p2;

    for (p1 = x, p2 = y; p1< &x[SIZE];)
    {
        *p2 ++ = *p1++;
    }
    
}

int main(int argc, char const *argv[])
{
    init();
    printf("初始化数据: ");
    int i = 0;
    for(; i < SIZE; i++) {
        printf("%d ,", + x[i]);
    }

    version4(); 

    printf("\n转化后数据: ");
     for(i= 0; i < SIZE; i++) {
        printf("%d ,", + y[i]);
    }   
    return 0;
}

