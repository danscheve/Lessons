Readme for source created for study purposes for 2016 interviews.
Using Intro to Algorithms, it became clear that:
  Have to deal with 0 vs 1 indexing for c.
  Have to deal with error conditions not covered.  In particular, regarding stacks, queues 
  and lists, we have to manage the conditions when
  - an item is to be added but the structure is full.
  - an item is to be removed but the structure is empty.
  Of course the various possible error conditions get more complicated with more sophisticated
  structures.  For example, a "real" queue would contain pointers to data (or data structures)
  which would be used by real device drivers (like ethernet or wireless).


Filename		Notes
doubly_ll.c		Demonstrates a doubly linked list with dynamic allocation.
			Started with linked list chapter (10.2 in Introduction to Algorithms 
			p. 236).
singly_ll.c		Also with dynamic allocation. Have to find a predecessor to delete
			a node.
			Expanded for error conditions and command line input and display.
prime.c			The commented out parts can be used for user input.
insertion_sort.c	Another exercise based on description in Introduction to Algorithms.
perms.c			Just walks through the possible permutations of a single string.
queue.c			Queues are FIFO; Stacks are LIFO - demonstrate both.
cycleAgain.c		Inspired by a google sample interview question.  Use the elements of
                        an array as indexes into the array.  True if each array element is
			visited once and only once.
stack.c			LIFo with static memory allocation.  Size set to 3 to easily 
			demonstrate exceeding the size.
reverse.c		Inspired by an Amazon interview.  First reverse the entire string, then
			reverse the reversed string for each word.
			Note how much easier this is using the 'reverse' python feature.
reverse.py		Same functionality as reverse.c.
Makefile		Builds all of the above except for python.l


