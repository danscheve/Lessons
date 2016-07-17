//insertion-sort
//
#include <stdio.h>
int main ()
{
  int arrayToSort[] = 
  {
    9,4,17,15,25,1,2,3,-100,5000
  };
  int i, j, len = (sizeof(arrayToSort) / sizeof (int)), key;
  printf("input:\n");
  for (i=0; i< len; ++i)
    printf ("element: %d; val: %d \n", i, arrayToSort[i]);

  for (j=1; j< len; ++j)
  {
    i = j-1;
    key = arrayToSort[j];
    while ((i >= 0) && (arrayToSort[i] > key))
    {
      arrayToSort[i+1] = arrayToSort[i];
      i--;
    }
    arrayToSort[i+1] = key;
  }
  printf("output:\n");
  for (i=0; i< len; ++i)
    printf ("element: %d; val: %d \n", i, arrayToSort[i]);
}

