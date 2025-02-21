// ***
// *** You must modify this file
// ***
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE * fp = fopen(filename, "r");

  if (!fp)
    {
      return false;
    }

  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  if (fseek(fp, 0, SEEK_END) != 0)
    {
      fclose(fp);
      return false;
    }

  // use ftell to determine the size of the file
  int filesize = ftell(fp);

  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  if (fseek(fp, 0, SEEK_SET) != 0)
    {
      fclose(fp);
      return false;
    }

  // the number of integers is the file's size divided by
  // size of int
  * size = filesize / sizeof(int);

  // allocate memory for the array
  * arr = malloc(filesize);

  // if malloc fails, fclose and return false
  if (! (* arr))
    {
      fclose(fp);
      return false;
    }

  // use fread to read the number of integers in the file
  int count = -1;
  while (!feof(fp))
    {
      fread(* arr + (++count), sizeof(int), 1, fp);
    }

  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
  if (count != * size)
    {
      fclose(fp);
      return false;
    }

  // if fread succeeds
  // close the file
  fclose(fp);

  // update the argument for the array address
  // done above

  // update the size of the array
  // done above

  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE * fp = fopen(filename, "wb");

  // if fopen fails, return false
  if (!fp)
    {
      return false;
    }

  // use fwrite to write the entire array to a file
  int rv = fwrite(arr, sizeof(int), size, fp);

  // check whether all elements of the array have been written
  // if not all elements have been written, return false
  if (rv != size)
    {
      fclose(fp);
      return false;
    }

  // fclose
  fclose(fp);

  // if all elements have been written, return true
  return true;
}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading.
  printInput("Merge in", arr, l, m, r);
#endif

  // if one or both of the arrays are empty, do nothing
  if (!(l < r))
    {
      return;
    }

  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write
  int lenLeft = m - l + 1;
  int * arrLeft = malloc(lenLeft * sizeof(int));
  for (int idx = 0; idx < lenLeft; idx++)
    {
      arrLeft[idx] = arr[l + idx];
    }

  int lenRight = r - m;
  int * arrRight = malloc(lenRight * sizeof(int));
  for (int idx = 0; idx < lenRight; idx++)
    {
      arrRight[idx] = arr[m + 1 + idx];
    }

  // merge the two parts (each part is already sorted) of the array
  // into one sorted array
  int i = 0;
  int j = 0;
  int k = l;

  while (i < lenLeft && j < lenRight)
    {
      if (arrLeft[i] <= arrRight[j])
        {
          arr[k++] = arrLeft[i++];
        }
      else
        {
          arr[k++] = arrRight[j++];
        }
    }

  // add leftovers
  while (i < lenLeft)
    {
      arr[k++] = arrLeft[i++];
    }
  while (j < lenRight)
    {
      arr[k++] = arrRight[j++];
    }

  free (arrLeft);
  free (arrRight);

  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading.
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r)
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading.
  printInput("mergeSort", arr, l, r, -1);
#endif

  // if the array has no or one element, do nothing
  if ((r - l) < 1)
    {
      return;
    }

  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
  int m = l + (r - l) / 2;

  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);

  merge(arr, l, m, r);
}
#endif
