/**
 * SC.H - Utility functions for LeetCode solutions
 *
 * Provides common operations including:
 * - Array manipulation (unique elements, binary search, printing)
 * - Dynamic storage with exponential growth
 */

#ifndef SC_H
#define SC_H

/* ========================================================================
 * Array Utilities
 * ======================================================================== */

/**
 * Sort an array and remove duplicates in-place.
 *
 * @param arr  The array to process (will be modified in-place)
 * @param sz   The size of the array
 * @return     The resulting size after removing duplicates, or 0 if arr is NULL
 *
 * Note: The array will be sorted in ascending order after this operation.
 */
int sc_sort_uniq(int *arr, int sz);

/**
 * Binary search for an element in a sorted array.
 *
 * @param arr    The sorted array to search (ascending order)
 * @param begin  The starting index (inclusive)
 * @param end    The ending index (exclusive)
 * @param e      The element to search for
 * @return       The index where the element is found, or -1 if not found
 *
 * Note: Returns -1 if arr is NULL or if the range is invalid.
 */
int sc_bsearch(const int arr[], int begin, int end, int e);

/**
 * Print an array with a label.
 *
 * @param arr    The array to print
 * @param sz     The size of the array
 * @param label  A label to print before the array elements
 *
 * Output format: "label: elem1 elem2 elem3 ... elemN\n"
 */
void sc_print(const int arr[], int sz, const char *label);

/* ========================================================================
 * Dynamic Vector (sc_vec)
 * ======================================================================== */

/**
 * Opaque structure for dynamic vector that grows exponentially.
 * - Initial capacity: 1024 elements
 * - Growth strategy: 2X on each expansion
 * - Maximum capacity: ~33.5M elements (16 storage blocks)
 */
typedef struct sc_vec sc_vec;

/**
 * Type of elements stored in sc_vec.
 * Currently defined as int, can be changed as needed.
 */
#define sc_vec_t int

/**
 * Initialize a new dynamic vector.
 *
 * @return  A pointer to the newly created vector, or NULL on allocation failure
 *
 * Note: The vector grows 2X each time it fills up. No individual deletion is provided.
 *       Initial capacity: 1024 elements, max chunks: 16 (total ~33.5M elements).
 */
sc_vec *sc_vec_init(void);

/**
 * Push an element to the vector.
 *
 * @param vec  The vector structure
 * @param t    The element to push
 * @return     0 on success, -1 on failure (NULL pointer, capacity limit, or allocation error)
 */
int sc_vec_push(sc_vec *vec, sc_vec_t t);

/**
 * Free all storage and the vector structure itself.
 *
 * @param vec  The vector structure to free (can be NULL)
 */
void sc_vec_free(sc_vec *vec);

#endif /* SC_H */
