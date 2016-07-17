
#include <stdio.h>
#include <string.h>
#define LIFOSIZE 3
struct lifo
{
  int data[LIFOSIZE];
  int top;
};

void initLifo(struct lifo *theStack)
{
  theStack->top = -1;
  memset (theStack->data, 0, sizeof(theStack->data));
}

int lifoIsFull(struct lifo *theStack)
{
  return(theStack->top == LIFOSIZE-1);
}

int lifoIsEmpty(struct lifo *theStack)
{
  return(theStack->top == -1);
}

int push(struct lifo *theStack, int data)
{
  if (lifoIsFull(theStack))
  {
    printf("can't push - lifo is full\n");
    return -1;
  }
  theStack->top++;
  theStack->data[theStack->top] = data;
  return 1;
}

int pop (struct lifo *theStack)
{
  if (lifoIsEmpty(theStack))
  {
    printf("lifo is empty - nothing to pop\n");
    return -1;
  }
  int ret = theStack->data[theStack->top];
  theStack->top--;
  return ret;
}

void displayLifo(struct lifo *lifoToPrint)
{
  int i = 0;
  printf("\ndisplayLifo entry; top: %d\n", lifoToPrint->top);
  while(i < LIFOSIZE)
  {
    printf("i: %d val: %d  \n", i, lifoToPrint->data[i]);
    i++;
  }
}

int main ()
{
  int  in, ret;
  char option[100];
  struct lifo myLifo;
  printf("\nThis demonstrates a LIFO queue with size %d\n", LIFOSIZE);
  initLifo(&myLifo);
  while(1)
  {
    printf("\nenter push <value> or pop: ");
    scanf("%s", option);
    printf("option: %s \n", option);
    if (strstr(option, "push") || (strstr(option, "pop"))) 
    {
      if (strstr(option, "push"))
      {
        //printf("\nenter data to push: %d", in);
        scanf("%d", &in);
        int ret = push(&myLifo,in);
	if(ret != -1) printf("pushed %d\n", in);
	else printf ("push failed\n");

      }
      else
      {
        printf("\npopping\n");
        ret = pop(&myLifo);
        if(ret != -1) printf("popped: %d\n", ret);
	else return 0;
      }
    }
    else
    {
      printf ("Try again\n");
      return 0;
    }
    displayLifo(&myLifo);
  }
  return 0;
}

