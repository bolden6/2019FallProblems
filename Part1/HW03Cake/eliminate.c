#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }

  for (int i = 0; i < n; i++)
  {
     arr[i] = true;
  }
  //local decs
  int eliminated = 0; // num of elements eliminated
  int position = 0; // current position in the array

  while (eliminated < n)
   {
      int count = 0; // counter 1 at a time to the next k
      while (count < k)
      {
        if (arr[position])
        {
         count++;
        }
        if (count == k)
         {
           (arr[position]) = false;// eliminate arr[index] for recounts
            printf("%d\n", position); // prints the current index
            eliminated++;
         }
      position = (position + 1) % n;// advance to the next position
    }
  }

  free (arr);
}
#endif
