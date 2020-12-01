#include <stdio.h>

typedef struct
{
    char *a;
    char b;
    int c;
} stu;
int main(int argc, char const *argv[])
{
   stu stu1;
   char *a = "abc";
   stu1.a = a;
    printf("%s", stu1.a);
}


