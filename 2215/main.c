#include <stdlib.h>
#include <stdio.h>

#include "../sc.h"

/**
   https://leetcode.com/problems/find-the-difference-of-two-arrays/
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size,
                     int* returnSize, int** returnColumnSizes) {
    
    printf("computing!\n");
    // make them unique.
    int n1 = sc_uniq(nums1, nums1Size);
    int n2 = sc_uniq(nums2, nums2Size);

    // -1001 is not one of the values
    const int DEL = -1001;
    int intersection_count = 0;

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (nums1[i] == nums2[j]) {
                nums1[i] = DEL;
                nums2[j] = DEL;
                intersection_count++;
                break;
            }
        }
    }

    int sz1 = n1 - intersection_count;
    int sz2 = n2 - intersection_count;

    int* ans_a = (int*)malloc(sizeof(int) * (sz1));
    int* ans_b = (int*)malloc(sizeof(int) * (sz2));

    for (int i = 0, ii = 0; i < n1; ++i) {
        if (nums1[i] != DEL ) {
	    ans_a[ii++] = nums1[i];
	}
    }

    for (int j = 0, jj = 0; j < n2; ++j) {
        if (nums2[j] != DEL) {
	    ans_b[jj++] = nums2[j];
	}
    }


    // of course it's 2. this requirement is dumb
    *returnSize = 2;
    *returnColumnSizes = malloc(sizeof(int)*2);
    (*returnColumnSizes)[0] = sz1;
    (*returnColumnSizes)[1] = sz2;

    int** ans = malloc(sizeof(int*) * 2);
    ans[0] = ans_a;
    ans[1] = ans_b;

    printf("done computing!\n");
    return ans;
}

int main() {
    printf("Find the Difference of Two Arrays\n\n");

    int nums1[] = {1,2};
    int nums1Size = 2;
    int nums2[] = {0, 2, 3};
    int nums2Size = 3;
    int returnSize;
    int* returnColumnSizes;

    int** ans = findDifference(nums1, nums1Size, nums2, nums2Size, &returnSize, &returnColumnSizes );
    
    printf("done!\n");
    sc_print(ans[0], returnColumnSizes[0], "first");
    sc_print(ans[1], returnColumnSizes[1], "second");
    printf("done!\n");

    return 0;
}
