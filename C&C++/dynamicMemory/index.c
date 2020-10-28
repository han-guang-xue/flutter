/**
 * 大多数情况下处理的数据常常实在运行的时候才知道
 * 这些数据需要处理的所需内存空间取决于输入数据量的大小
 * malloc 分配的内存是连续的 
 *  void *__cdecl malloc(size_t _Size);
 * calloc 分配内存并初始化为0, 如果只是存值到数组,没有必要初始化
 *  void *calloc(size_t _NumOfElements, size_t _SizeOfElements)
 *  表示所需元素的数量和每个元素所需的字节数
 * realloc 修改分配的内存,用于对内存的扩大和缩小
 *   void *__cdecl realloc(void *_Memory,size_t _NewSize);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * strcopy(char const *tarstr) {
    char * newstr;
    newstr = malloc(strlen(tarstr) * 1);

    if(newstr != NULL) {
        strcpy(newstr, tarstr);
    }
    return newstr;
}

int main(int argc, char const *argv[])
{   
    char *str = "ajhdsjfhajjsdfjadhfjahdjfjadhf,ajshdfjhajsdkfjasdjfhajsdfh!!!!!~~~";
    printf("%s \n", strcopy(str));    
    printf("%s \n", str);    
    return 0;
}


