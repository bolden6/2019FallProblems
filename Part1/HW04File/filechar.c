<<<<<<< HEAD
// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, char * counts, int size)
{

  FILE * fp = fopen(filename, "r");
  int onechar;

  if (!fp)
  {
    return false;
  }
  while ((onechar = fgetc(fp)) != EOF)
    {// read until end of file
      if (onechar < 0 || onechar > size - 1)
        {
          continue;// ignore invalid chars
        }
      else
      {
        ++(counts[onechar]);// increment counts[onechar] by one
      }
    }

  fclose(fp);
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(char * counts, int size)
{
  for (int c = 0; c < size; c++)
    {
      if ((counts[c])) //only existing elements
        {
          if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
            {
              printf("%d, , %d\n", c, counts[c]);
            }
          else
          {
            printf("%d, %c, %d\n", c, c, counts[c]);
          }
        }
    }
}
#endif
=======
// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  //
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
}
#endif
>>>>>>> 8720506b64e0d6b009475bfadee1b31f0c9859e1
