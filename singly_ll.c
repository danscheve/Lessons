#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct singly_linked_list
{
  int data;
  struct singly_linked_list *next;
}sLL;

//global pointer to head of list
sLL *head = NULL;

sLL *search_list(sLL *l, int data);
sLL *predecessor_list(sLL *l, int x);

void insert_list(sLL **node, int key)
{
  sLL *new = malloc(sizeof(sLL));
  new->data = key;
  new->next = *node;
  *node = new;
}

//For removing a node from the list there are three possibilities:
//1) We can't find the node to delete (it doesn't exist)
//2) We find the node to delete at the front of the list (i.e. it has no predecesor)
//   In this case, we have to set the current head (front of list) to the current next
//   (i.e. the current 2nd in list)
//3) We find the node to delete elsewhere in the list (not in the front of the list).
//   In this case, we set the predecessor's next pointer to the node to delete's next pointer
//
//if the node to delete is found, we finally must free its memory.
//
void delete_list(sLL **l, int data)
{
  sLL *p = search_list(*l, data);
  sLL *pred;
  if (p)
  {
    pred = predecessor_list(*l, data);
    printf("delete_list1 pred: %p *l: %p p: %p\n", pred, *l, p);
    if (!pred)
    {
      printf("NO pred found - this means that %d is at the front of the list\n", data);
      printf("so set %p to %p\n", *l, p->next);
      *l = p->next;
    }
    else
    {
      printf("pred found at %p - so set pred->next (%p) to p->next (%p)\n", 
	  pred, pred->next, p->next);
      pred->next = p->next;
    }
    free (p);
  }
  else
    printf("can't find %d in list, so can't delete it\n", data);
}

#if 0
sLL *search_list(sLL *l, int data)
{
  if (l)
  {
    if (l->data == data)
      return(l);
    else
      return(search_list(l->next, data));// make it recursive
  }
  printf("%d not foud in list\n", data);
  return NULL;
}
#endif

//non-iterative search
sLL *search_list(sLL *l, int data)
{
  sLL *p = l;
  while(p)
  {
    if(p->data == data)
      return (p);
    p = p->next;
  }
  printf("%d not foud in list\n", data);
  return NULL;
}

sLL *predecessor_list(sLL *l, int x)
{
  if(l && l->next)
  {
    if ((l->next)->data == x)
    {
      return (l);
    }
    else
    {
      return predecessor_list(l->next, x);
    }
  }
  printf("looking for predecessor NULL list: l: %p; l->next: %p\n",
    l, l->next);
  return NULL;
}

void print_list();
void print_list()
{
  sLL *start = head;
  while(start)
  {
    printf ("item @ %p data: %d next: %p\n", start, start->data, start->next);
    start = start->next;
  }
}

int main(void)
{
  int in = 0;
  char option[100];
  sLL *found = NULL;
  while(1)
  {
    printf("\nenter add <value> or search <value> or remove <value>: ");
    scanf("%s", option);
    printf("option: %s \n", option);
    //The three user possible user list actions are add, search, and remove
    if (strstr(option, "add") || strstr(option, "search") || strstr(option, "remove"))
    {
      scanf("%d", &in);
      printf("option: %s %d\n", option, in);
      if (strstr(option, "search"))
      {
       sLL *search = search_list(head, in);
       if (search)
         printf ("found %d at %p\n", search->data, search);
       else
         printf("%d not found\n", in);
      }
      else if(strstr(option, "add"))
      {
	insert_list(&head, in);
      }
      else if(strstr(option, "remove"))
      {
        delete_list(&head, in);
        printf("back from remove; head now at %p\n",head);
      }
      else
      {
        printf("%d not found in list\n", in);
      }
      if (head)
      {
	printf("printing list @ %p\n", head);
	print_list();
      }
      else printf ("Empty list\n");
    }
    else
    {
      printf ("Try again\n");
      return 0; 
    }
  }
}
     


