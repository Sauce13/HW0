#include "quick_sort.h"
#include "GenericTraits.h"
#include <stdlib.h>

void swap(GenericTraits ***a, GenericTraits ***b)
{
  GenericTraits **temp = *a;
  *a = *b;
  *b = temp;
}
int partition(GenericTraits **array[], int low, int high)
{
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    if ((*array[j])->cmp(array[j], array[high]) > 0)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quick_sort_helper(GenericTraits **array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quick_sort_helper(array, low, pi - 1);
    quick_sort_helper(array, pi + 1, high);
  }
}

void quick_sort(GenericTraits **array[], int n)
{
  quick_sort_helper(array, 0, n - 1);
}
