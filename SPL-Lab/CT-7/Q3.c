#include <stdio.h>

void print_indv_char(char* s)
{
  if (*s!='\0')
  {
     printf("%c",*s);
     s++;
     print_indv_char(s);
  }
}

void print_indv_char_rev(char* s)
{
  if (*s!='\0')
  {
     print_indv_char_rev(s+1);
     printf("%c",*s);
  }
}

int main()
{
  char str[100]="Hello";
  print_indv_char(str);
  printf("\n");
  print_indv_char_rev(str);
  return 0;
}
