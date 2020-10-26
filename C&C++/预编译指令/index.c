// #define、#undef、#ifdef、#ifndef、#if、#elif、#else、#endif、defined。
// #define            定义一个预处理宏
// #undef            取消宏的定义
// #if                   编译预处理中的条件命令，相当于C语法中的if语句
// #ifdef              判断某个宏是否被定义，若已定义，执行随后的语句
// #ifndef            与#ifdef相反，判断某个宏是否未被定义
// #elif                若#if, #ifdef, #ifndef或前面的#elif条件不满足，则执行#elif之后的语句，相当于C语法中的else-if
// #else              与#if, #ifdef, #ifndef对应, 若这些条件不满足，则执行#else之后的语句，相当于C语法中的else
// #endif             #if, #ifdef, #ifndef这些条件命令的结束标志.
// #defined         　与#if, #elif配合使用，判断某个宏是否被定义

#include <stdio.h>
#define PI  3.14
#define UD 445
int main(int argc, char const *argv[])
{

    // #undef PI    //取消宏定义

    #ifdef PI
    // #undef PI    //取消宏定义
    printf("PI 是预定义过的 \n");

    #endif // PI

    #ifndef PI
    printf("PI 是未预定义的 \n");
    #endif // !PI

    /**
     * #if #elif 其中只有一个执行,其他就不执行,
     * 
     */
    //以下是一套
    #if !defined(PI)
    printf("输出PI PI= %g\n", PI);  
    #elif defined(UD)
    printf("输出UD UD= %g\n", UD);
    #else
    printf("else \n"); 
    #endif
    printf("endif \n"); 
    return 0;
}
