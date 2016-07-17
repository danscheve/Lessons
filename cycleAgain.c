#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
  int size, i, idxVal, valAtIdx;
  printf ("cycle check - enter an array size\n");
  scanf("%d",&size);

  int visitedArray[size];
  memset(visitedArray, 0, sizeof(visitedArray));
  
  printf ("entered: %d\n", size);
  int array[size];
  int max = sizeof (array) / sizeof(int);
  //printf ("so this array has %d elements\n", max);
  printf ("enter some values for this array\n");
  for (int i=0; i < size; ++i)
    scanf ("%d", &array[i]);
  printf("The array:\n");
  for (i=0; i < size; ++i)
  {
    printf ("%d ",array[i]);
  }
  printf("\n");
  //get the value from each element, then use that vaue to 'visit' another
  //element of the array
  // e.g. if value is 6, visit '6th' element
  //   just count with 'wrap':
  //   so it the num is positive, use number % size as the index
  //   if negative, same but use abs value
  //
  for (i=0; i < size; ++i)
  {
    int valAtIdx = abs(array[i]);
    //printf ("idx: %d val: %d\n", i, valAtIdx);
    printf ("idx: %d val: %d\n", i, valAtIdx % max);
    int viIdx = valAtIdx % max;
    ++visitedArray[viIdx];
  }
  printf("\n");
  int allSeen = 1;
  for (i=0; i < size; ++i)
  { if (visitedArray[i] != 1)
      allSeen = 0;
    printf ("end idx: %d val: %d\n", i, visitedArray[i]);
  }
  printf("\nallSeen: %d\n",allSeen);
}
