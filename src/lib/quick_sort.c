#include "quick_sort.h"
#include "GenericTraits.h"
#include <stdlib.h>

int comparator(const void *p, const void *q)
{
  GenericTraits *a = *(GenericTraits **)p;
  GenericTraits *b = *(GenericTraits **)q;

  printf("In comparator: a->new=%p, a->dump=%p, a->cmp=%p, a->drop=%p\n",
         a->new, a->dump, a->cmp, a->drop);
  printf("In comparator: b->new=%p, b->dump=%p, b->cmp=%p, b->drop=%p\n",
         b->new, b->dump, b->cmp, b->drop);

  return a->cmp(a, b);
}

void quick_sort(GenericTraits **array[], int n)
{
  qsort(array, n, sizeof(GenericTraits *), comparator);
}