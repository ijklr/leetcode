#include <stdio.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {

  // brute force
  bool a[1000] = {0};
  bool b[1000] = {0};

  for(int i=0; i<nums1Size; ++i) {
    for(int j=0; i<nums2Size; ++j) {
      if (nums1[i] == nums2[j]) {
        a[i] = true;
        b[j] = true;
      }
    }
  }
  

  int* ans_a = malloc(size_of(int) * 1000);
  int* ans_b = malloc(size_of(int) * 1000);
  
  int ans_a_idx = 0;
  for(int i=0, idx=0; i<nums1Size; ++i) {
    if (!a[i]) {
      ans_a[ans_a_idx++] = nums1[i];
    }
  }

  int ans_b_idx = 0;
  for(int j=0; j<nums2Size; ++j) {
    if (!b[j]) {
      ans_b[ans_b_idx++] = nums2[j];
    }
  }


  int** ans = malloc(size_of(int*) * 2);
  ans[0] = ans_a;
  ans[1] = ans_b;

  *returnSize= 2;
  *returnColumnsSizes[0] = ans_a_idx;
  *returnColumnsSizes[1] = ans_a_idx;
  return ans;
}


int main() {
  printf("Find the Difference of Two Arrays\n\n");


  int** ans = findDifference();

  return 0;
}
