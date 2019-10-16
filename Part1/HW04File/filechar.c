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
