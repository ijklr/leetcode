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
  return 0;
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
  return 0;
}

int test_sstore_basic() {
  printf("======test sc_sstore basic======\n");
  sc_sstore *store = sc_sstore_init();
  assert(store != NULL);

  // Test pushing elements
  for (int i = 0; i < 100; ++i) {
    int ret = sc_sstore_push(store, i * 10);
    assert(ret == 0); // should succeed
  }
  printf("Successfully pushed 100 elements\n");

  sc_sstore_free(store);
  printf("Store freed successfully\n");
  return 0;
}

int test_sstore_growth() {
  printf("======test sc_sstore growth======\n");
  sc_sstore *store = sc_sstore_init();
  assert(store != NULL);

  // Test pushing elements across multiple chunks
  // Initial capacity is 1024, so push 2048 to trigger growth
  for (int i = 0; i < 2048; ++i) {
    int ret = sc_sstore_push(store, i);
    assert(ret == 0); // should succeed
  }
  printf("Successfully pushed 2048 elements (triggered growth)\n");

  sc_sstore_free(store);
  return 0;
}

int test_sstore_null_handling() {
  printf("======test sc_sstore NULL handling======\n");

  // Test push with NULL store
  int ret = sc_sstore_push(NULL, 42);
  assert(ret == -1); // should fail
  printf("Push to NULL store correctly returns -1\n");

  // Test free with NULL
  sc_sstore_free(NULL); // should not crash
  printf("Free NULL store does not crash\n");

  return 0;
}

int test_null_pointer_handling() {
  printf("======test NULL pointer handling======\n");

  // Test sc_print with NULL
  sc_print(NULL, 5, "test");
  printf("sc_print with NULL array does not crash\n");

  int arr[] = {1, 2, 3};
  sc_print(arr, 3, NULL);
  printf("sc_print with NULL label does not crash\n");

  // Test sc_uniq with NULL
  int ret = sc_uniq(NULL, 5);
  assert(ret == 0);
  printf("sc_uniq with NULL array returns 0\n");

  // Test sc_find with NULL
  int found = sc_find(NULL, 0, 5, 42);
  assert(found == -1);
  printf("sc_find with NULL array returns -1\n");

  return 0;
}

int main() {
  test_uniq();
  test_find();
  test_sstore_basic();
  test_sstore_growth();
  test_sstore_null_handling();
  test_null_pointer_handling();
  printf("\n======================\n");
  printf("All tests passed!\n");
  printf("======================\n");
  return 0;
}

