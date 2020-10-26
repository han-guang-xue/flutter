#include <stdio.h>
#define M (d*d) 
int main(int argc, char const *argv[])
{
    /* code */
    printf("good %d\n", ~2);
    #if 0
    printf("good %d\n", ~3);
    printf("good %d\n", ~4);
    #endif // 0
    printf("good %d\n", ~5);
    return 0;
}
