// ***
// *** You must modify this file
// ***
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  FILE * fp = fopen(filename, "r");
  Vector vp;
  int count = -1;
  // If fopen fails, return -1
  if (!fp)
   {
    return count;
   }

   while (!feof(fp))
   {
    fread(&vp, sizeof(Vector), 1, fp);
    count++;
   }
  fclose(fp);
  return count;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE * fp = fopen(filename, "r");
  int count = 0;
  //int value;

  if(!fp)
  {
    return false;
  }
  // read Vectors from the file.
  count = fread(vecArr, sizeof(Vector), size, fp);

    // if the number of integers is different from size (too
    // few or too many) return false
  if(count != size)
  {
    return false;
  }

  // if everything is fine, fclose and return true
  fclose(fp);
  return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  const Vector * vp1 = (const Vector *)p1;
  const Vector * vp2 = (const Vector *)p2;
  const Vector a = * vp1;
  const Vector b = * vp2;

  if (a.x < b.x)
   {
    return -1;
   }
   if (a.x > b.x)
   {
    return 1;
   }
   else if (a.x == b.x)
   {
     if (a.y < b.y)
     {
       return -1;
     }
     if (a.y > b.y)
     {
       return 1;
     }
      else if (a.y == b.y)
     {
       if (a.z < b.z)
       {
         return -1;
       }
       if (a.z > b.z)
       {
         return 1;
       }
     }
  }

  return 0;

}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE * fp = fopen(filename, "w");
  if (!fp)
  {
    return false;
  }

  // write the array to file using fwrite
  int numWrit; //rtv for fwrite- # written
  numWrit = fwrite(vecArr, sizeof(Vector), size, fp);
    // if not all are written, fclose and return false
  if (numWrit < size)
  {
    fclose(fp);
    return EXIT_FAILURE;
  }
  // fclose and return true
  fclose(fp);
  return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
