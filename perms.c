#include <stdio.h>
#include <string.h>
void perms(char *test)
{
  char cpyStr[1000];
  if (strlen(test))
  {
    for (int i=0; i<strlen(test); ++i)
    {
      strncpy(cpyStr, test, sizeof(cpyStr));
      cpyStr[i+1] = '\0';
      printf("substr %d %s\n", i, cpyStr);
    }
  }
  else
    printf("must be null: %s\n", test);
}
int main()
{
  char temp[1000];
  printf ("enter a string:\n");
  scanf("%s",temp);
  printf ("entered: %s\n", temp);
  perms(temp);
  return 0;
}
