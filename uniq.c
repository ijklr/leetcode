#include "uniq.h"
#include <stdlib.h> // qsort()

int compare_int(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int uniq(int *arr, int sz) {
  qsort(arr, sz, sizeof(int), compare_int);
  return sz;
}
