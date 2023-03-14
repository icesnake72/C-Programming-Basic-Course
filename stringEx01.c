#include <stdio.h>

int main() 
{
  char str1[] = "Hello";
  char *str2 = "Hello";
  // char *str3 = NULL;

  printf("%s\n", str1);
  printf("%s\n", str2);
  printf("%p\n", str2);
  
  str2 = "I am a software developer";
  printf("%s\n", str2);  

  return 0;
}
