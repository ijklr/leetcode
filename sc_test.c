#include "sc.h"
#include <assert.h>
#include <stdio.h>

void print(int arr[], int sz) {
  for (int i = 0; i < sz; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int test_uniq() {
  printf("======test uniq======\n");
  int arr[] = {1921384, -100, 5, 3, 2, 2, 10, -100, -100, -100};
  int sz = sizeof(arr) / sizeof(int);
  printf("before uniq: \n");
  print(arr, sz);
  int ret = sc_uniq(arr, sz);
  printf("after uniq: \n");
  print(arr, ret);
  assert(ret == 6);
}

int test_find() {
  printf("======test uniq======\n");
  int arr[] = {1384, 888, 5, 3, 2, 2, 10, -100, -100, -100};
  print(arr, 10);
  int n = sc_uniq(arr, 10);
  print(arr, n);
  int found = sc_find(arr, 0, n, 888);
  assert(found != -1);
  printf("found=%d\n", found);
  int not_found = sc_find(arr, 0, n, 123);
  assert(not_found == -1);
  printf("not_found=%d\n", not_found);
}

int main() {
  test_uniq();
  test_find();
}

