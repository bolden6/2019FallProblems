// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  //Local declarations
  FILE * fp = fopen(filename, "r");
  int count = 0; // number of integers
  int value;
  // count the number of integers in the file
  if(!fp)
  {
    return -1;
  }
  while (fscanf(fp, "%d", &value) == 1)
  {
    count++;
  }

  fclose(fp);
  return count;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return
  FILE * fp = fopen(filename, "r");

  // read integers from the file.
  int value;
  int count = 0;
  // if fopen fails, return false. Do NOT fclose X
  if (!fp)
   {
    return false;
   }
   while ((fscanf(fp, "%d", &value) == 1))
     {
       if(count < size)
       {
          intArr[count] = value;
          count++;
       }
       else
       {
         return false;
       }
     }
   if(count != size)
   {
     return false;
   }
   fclose(fp);
   return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  int a = *(const int *)p1;
  int b = *(const int *)p2;

  if (a < b)
   {
    return -1;
  }
  if (a == b)
   {
    return 0;
  }
  return 1;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  FILE * fp = fopen(filename, "w");
  int i = 0;
  if (!fp)
   {
    return false;
   }
   while( i < size)
   {
     fprintf(fp, "%d\n", intArr[i]);
     i++;
   }

  fclose(fp);
  return true;
}
#endif
