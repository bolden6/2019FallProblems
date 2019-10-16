// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTWORD
int countWord(char * filename, char * word, char * line, int size)
{
  FILE * fp = fopen(filename, "r"); // filename: name of the input file
  int sum = 0;

  if (!fp)
   {
    return -1;
   }// if fopen fails, return -1.

   if (fp)
    {
     while (fgets(line, size, fp) != NULL)
      {
        char * found = line;
        while((found = strstr(found, word)))
        {
          found += strlen(word); // goes to the next line
          sum++; // adds one each time a new word is discovered
        }
      }
    }
  fclose(fp);
  return sum;
}
#endif
