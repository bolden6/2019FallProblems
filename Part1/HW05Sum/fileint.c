// ***
// *** You MUST modify this file.
// ***
#include <stdio.h>
#include <stdbool.h>
#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  //local declarations
  FILE * fp; // file pointer
  *sum = 0;
  int value;
  fp = fopen(filename, "r");
  // if fopen fails, return false. Do NOT fclose X
  if (!fp)
   {
    return false;
   }
  while ((fscanf(fp, "%d", &value) == 1))
     {
      *sum += value;
     }
    fclose(fp);
  return true;
}
#endif
#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  FILE * fw = fopen(filename, "w"); // file to open in write
  if(fw)
  {
    fprintf(fw, "%d\n", sum);
  }
  fclose(fw);
  //
  return true;
}
#endif
