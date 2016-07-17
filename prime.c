#include <stdio.h>
int isPrime (int n)
{
  int x;
  for (x=2; x*x <=n; x++)
  { printf("x: %d npctx: %d\n", x, n % x);
    if (n % x == 0)
      return 0;
  }
  return 1;
}
int main (void)
{
  int in;
//  printf("enter a number:");
//  scanf("%d",&in);
  for (in=0; in <10; ++in)
    if (isPrime(in))
      printf ("%d is prime ", in);
  //printf("%d is prime: %d\n", in, isPrime(in));
}
