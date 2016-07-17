#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
//given a element x, x.next points to its successor;
//                   x.prev points to its predecessor
//                   if x.prev is NIL, then we have the first element
//                   if x.next is NIL, then we have the last element
struct doubly_linked_list
{
    int key;
    struct doubly_linked_list *next;
    struct doubly_linked_list *prev;
};

struct doubly_linked_list *llHead=NULL; //if llHead is NIL, the list is empty

struct doubly_linked_list *createNode(int key)
{
    struct doubly_linked_list *ptr = 
      (struct doubly_linked_list*)malloc(sizeof(struct doubly_linked_list));
    if(ptr)
    {
      ptr->key = key;
      ptr->next = ptr->prev = NULL; //most recently created node goes
                                    //to front of list (it is the first element)
    }
    else
      printf("\nNode creation failed \n");
    printf("\nCreated new node at %p\n", ptr);
    return ptr;
}

void insert_in_list(struct doubly_linked_list *start, struct doubly_linked_list *insert)
{
  printf("insert entry start %p insert %p llHead: %p\n", start, insert, llHead);
  if (start && insert)
    printf("insert start %p insert %p insert->next %p \n", 
   start, insert, insert->next);

  if (!llHead) //llHead is initialized to NULL, it's only NULL if list is empty
  {
    llHead = insert;
    return;
  }
  //list is not empty, so the item inserted has a next ptr set to current llHead
  insert->next = llHead;
  //llHead now points to the item getting inserted
  llHead = llHead->prev = insert; 
  //By definition, the prev pointer is NULL (newly inserted item is in front of list
  insert->prev = NULL;
  if (start && insert)
    printf("insert exit start %p insert %p insert->next %p \n", 
      start, insert, insert->next);
}

void remove_from_list(struct doubly_linked_list *start, struct doubly_linked_list *remove)
{
  printf("\nremove_from_list entry entry start %p remove: %p llHead: %p\n",
      start, remove, llHead);
  if (remove->prev)
  {
    printf("remove->prev at %p\n",remove->prev);
    remove->prev->next = remove->next;
  }
  else
  {
    printf("remove->prev NIL? at %p\n",remove->prev);
    llHead = remove->next;
  }
  if (remove->next)
    remove->next->prev = remove->prev;
  printf("\nremove_from_list entry exit start %p remove: %p llHead: %p\n",
      start, remove, llHead);
}

struct doubly_linked_list* search_in_list(int val, struct doubly_linked_list *llToSearch)
{
  struct doubly_linked_list *search = llHead;
  printf("search_in_list\n");
  while (search && search->key != val)
    search = search->next;
  return (search);
}

void print_list(struct doubly_linked_list * llToPrint)
{
  printf("\nPrinting list start %p with key %d next:%p prev: %p\n",
      llToPrint, llToPrint->key, llToPrint->next, llToPrint->prev);
  struct doubly_linked_list *next = llToPrint->next;
  while(next)
  {
    printf(" next at %p with key %d next->next: %p next->prev: %p\n", 
	next, next->key, next->next, next->prev);
    next=next->next;
  }
}

int main(void)
{
  int in = 0;
  char option[100];

  struct doubly_linked_list *newNode = NULL;
  printf("\nThis demonstrates a doubly linked list with dynamic allocation \n");
  while(1)
  {
    printf("\nenter add <value> or search <value> or remove <value>: ");
    scanf("%s", option);
    printf("option: %s \n", option);
    if (strstr(option, "add") || strstr(option, "search") || strstr(option, "remove")) 
    {
      scanf("%d", &in);
      printf("option: %s %d\n", option, in);
      if (strstr(option, "search"))
      {
        struct doubly_linked_list *search = search_in_list(in, llHead);
	if (search)
	  printf ("found %d at %p\n", search->key, search);
	else
	  printf("%d not found\n", in);
      }
      else if(strstr(option, "add"))
      {
	newNode = createNode(in);
	insert_in_list(llHead, newNode); 
      }
      else if(strstr(option, "remove"))
      {
       struct doubly_linked_list *found =  search_in_list(in, llHead);
       if (found)
       {
	 printf("found %d in list at %p removing node with key: %d\n", in, found, found->key);
	 remove_from_list(llHead, found);
	 printf("back from remove llHead now at %p\n",llHead);
       }
       else
       {
	 printf("%d not found in list\n", in);
       }
      }
      if (llHead)
      {
	printf("printing list @ %p\n", llHead);
	print_list(llHead);
      }
      else printf ("Empty list\n");
    }
    else
    {
      printf ("Try again\n");
      //return 0;
    }
  }
  return 0;
}

