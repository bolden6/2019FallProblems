// ***
// *** You must modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // argv[1]: name of input file (binary)
  // argv[2]: name of output file (binary)

  // check whether there are three arguments.
  // If not, return EXIT_FAILURE. DO NOT print anything
  if (argc != 3)
    {
      return EXIT_FAILURE;
    }

  int numVec = countVector(argv[1]); // use argv[1] as the input to countVector, save the result

  // if the number of vector is 0 or negative, return EXIT_FAILURE
  if (numVec <= 0)
   {
     return EXIT_FAILURE;
   }

  // otherwise, allocate memory for an array of vectors
  Vector *vecArr = malloc(sizeof (Vector) * numVec);
  if(!vecArr)
  {
    free(vecArr);
    return EXIT_FAILURE;
  }

  // read the vectors from the file whose name is argv[1]. save the
  // results in the allocated array
  // if reading fails, release memory and return EXIT_FAILURE
  bool rtv = readVector(argv[1], vecArr, numVec);
  if (rtv == false)
   {
     free(vecArr);
    return EXIT_FAILURE;
   }

#ifdef DEBUG
  printVector(vecArr, numVec);

#endif


<<<<<<< HEAD
  // call qsort to sort the vectors, use argv[3] to determine which
  // attribute to sort
  qsort(vecArr, numVec, sizeof(Vector), compareVector);

=======
>>>>>>> 8720506b64e0d6b009475bfadee1b31f0c9859e1

#ifdef DEBUG
  printf("\n");
  printVector(vecArr, numVec);
#endif

  // write the sorted array to the file whose name is argv[2]
  writeVector(argv[2], vecArr, numVec);
  rtv = writeVector(argv[2], vecArr, numVec);

  // if writing fails, release memory and return EXIT_FAILURE
  if (rtv == false)
  {
    free(vecArr);
    return EXIT_FAILURE;
  }


  // releave memory, return EXIT_SUCCESS
  free(vecArr);
  return EXIT_SUCCESS;
}
#endif
