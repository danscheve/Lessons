#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FIFO_SIZE 3

typedef struct fifo
{
  int data[FIFO_SIZE];
  int head;
  int tail;
  int count;
} myFifo;
 
myFifo theFifo;
void initFifo(void)
{
  memset(&theFifo, 0, sizeof(theFifo));
}

int fifoIsFull()
{
  return (theFifo.count == FIFO_SIZE);
}

int fifoIsEmpty()
{
  return(theFifo.count == 0);
}

int push(int dataToPush)
{
  if (fifoIsFull())
    return -1;
  theFifo.data[theFifo.tail] = dataToPush;
  if (theFifo.tail == FIFO_SIZE-1)
  {
    printf("tail reset\n");
    theFifo.tail = 0;
  }
  else
    theFifo.tail++;
  theFifo.count++;
  return 1;
}

int pop ()
{
  if (fifoIsEmpty())
  {
    printf ("fifo empty - nothing to pop\n");
    return -1;
  }
  int ret = theFifo.data[theFifo.head];
  if (theFifo.head == (FIFO_SIZE-1))
  {
    printf("head reset\n");
    theFifo.head = 0;
  }
  else
    theFifo.head++;
  theFifo.count--;
  return ret;
}

void displayFifo()
{
  int i =0;
  for (i=0; i<FIFO_SIZE; ++i)
    printf ("item: %d key: %d\n", i, theFifo.data[i]);
}

int main (void)
{
  int  in, ret;
  char option[100];
  printf("\nThis demonstrates a FIFO queue with size %d\n", FIFO_SIZE);
  initFifo();
  while(1)
  {
    printf("\nenter push <value> or pop: ");
    scanf("%s", option);
    printf("option: %s \n", option);
    if (strstr(option, "push") || (strstr(option, "pop"))) 
    {
      if (strstr(option, "push"))
      {
        scanf("%d", &in);
        int pushed = push(in);
	if (pushed==-1) printf("no push fifo is full\n");
      }
      else
      {
        printf("\npopping\n");
        ret = pop();
	if (ret==-1)
	  printf("fifo is empty\n");
	else
          printf("popped: %d\n", ret);
      }
    }
    else
    {
      printf ("Try again\n");
      return 0;
    }
    displayFifo();
  }
  return 0;
}



