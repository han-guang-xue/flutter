#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    /**
     * p[0] p[1] p[2] 地址分别是
     * 0x404064 0x40406a 0x40406c
     * 可以看出使用指针数组存储字符串是非常节省内存的 
     * 如果使用二维数组(矩阵存储特别耗费内存资源)
     */
    char const *p1[] = {"hello","A","CFD",NULL};
    printf("%s \n", p1[3]);

    // 这里最长字符串长度是5,但是定义二位数组最长长度需要6,最后一位存 '\0'
    char const p2[][6] = {"hello","A","CFD"};
    printf("%s \n", p2[0]);

    // 使用第三方
    char a1[] = "han,", a2[] = "good!";
    printf("%s \n", strcat(a1,a2));
    return 0;
}
