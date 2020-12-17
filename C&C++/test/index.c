#include <stdio.h>
#include <string.h>

char * test() {
   
   char *p = "456";
   printf("%d \n", sizeof(p));
   return p;
}

int main(int argc, char const *argv[])
{
   printf("%s", test());
}


