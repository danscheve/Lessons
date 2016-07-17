#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverseString (char *string);
void reverseStringWords (char *string);
int main (void)
{
  char *testString = "This is a much bigger test today - it's extremely large";
  char *allocString = malloc(strlen(testString));
  strcpy(allocString, testString);
  printf ("main starting string:\n %s\n", allocString);
  reverseString(allocString);
  reverseStringWords(allocString);
  printf ("main ending string\n %s\n", allocString);
  free (allocString);
  return 0;
}

void reverseString (char *string)
{
  int count = 0, i, length;
  char *tmp = string;
  while (*tmp)
  {
    tmp++;
    count++;
  }
  tmp = string;
  char cstart, cend;
  for (i=0; i < count/2; ++i)
  {
    length = count -i -1;
    cend = string[length];
    cstart = string[i];
    tmp[i] = cend;
    tmp[length] = cstart;
  }
}

void reverseStringWords (char *string)
{
  char *sPtr = string, tmp;
  int i=0, strLen=0, wordIdx = 0, j;
  int hiIdx, xIdx;
  while (*sPtr)
  {
    ++strLen;
    ++sPtr;
  } //strLen now set

  sPtr = string;  //reset to beginning of string
  
  while (*sPtr)
  {
    sPtr++;
    if (*sPtr == 0x20) //found a space; i is count of characters 
                       //up to and including the space
		       //wordIdx is the offset of the current word
    {
      hiIdx = i; //constant for below loop
      xIdx = i;  //variable for below loop
      for (j=(wordIdx); j<(wordIdx + (hiIdx-wordIdx + 1)/2); ++j)
      {
	tmp = string[j];
	string[j] = string[xIdx];
	string[xIdx] = tmp;
	--xIdx;
      }
      wordIdx = i+2;
    }
    i++;
  }

  hiIdx = xIdx = i-1;
  for (j=(wordIdx); j<(wordIdx + (hiIdx-wordIdx + 1)/2); ++j)
  {
    tmp = string[j];
    string[j] = string[xIdx];
    string[xIdx] = tmp;
    xIdx--;
  }
}



