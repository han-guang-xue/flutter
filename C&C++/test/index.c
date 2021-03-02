/*
 * @Author: your name
 * @Date: 2020-11-11 11:27:12
 * @LastEditTime: 2021-01-29 17:58:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \flutter\C&C++\test\index.c
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
   int a[10];
   int i = 0;
   while (i < 5)
   {
      a[i] = 10 + i;
      i++;
   }

   for (i = 0; i < 10; i++)
   {
      printf("%d ", a[i]);
   }
}
