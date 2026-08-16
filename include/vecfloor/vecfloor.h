#pragma once

#include <stddef.h>

#define VEC_DEFCAP 8

/**
 * Datatype used to index and measure vectors.
 */
typedef size_t vec_size;

/**
 * Datatype used to measure vector items.
 */
typedef size_t vec_isize;

/**
 * Dynamically-sized array. Each item is of the same data size, to immediately improve UX while not compromising speed. Length measures the amount of items. Capacity measures the amount of allocated bytes.
 */
typedef struct
{
    vec_size length;
    vec_size cap;
    vec_isize item_length;
    void *items;
} Vector;

/**
 * Allocates an empty, dynamically-sized array. Capacity is 8 items by default to optimize initial insertations.
 * @param item_length Fixed size of each item
 */
Vector vec_empty(vec_isize item_length);

/**
 * Allocates a dynamically-sized array by duplicating existing items. Capacity is 8 items by default (if set to 0) to optimize initial insertations.
 * @param length Initial size of vector
 * @param item_length Fixed size of each item
 * @param items Initial items to duplicate
 */
Vector vec_of(vec_size length, vec_isize item_length, const void *items);

/**
 * Duplicates a Vector to a new instance.
 * @param vec Vector to duplicate
 */
Vector vec_dup(const Vector vec);

/**
 * Retrieves the item at an index inside a dynamically-sized array.
 * @param vec Vector to index
 * @param i Index to use
 */
void *vec_get(const Vector vec, vec_size i);

/**
 * Inserts the duplicated value of an item into a dynamically-sized array.
 * @param vec Vector to insert into
 * @param i Index to use
 * @param item Item to insert
 */
int vec_insert(Vector *vec, vec_size i, const void *item);

/**
 * Appends the duplicated value of an item to the end of a dynamically-sized array.
 * @param vec Vector to append onto
 * @param item Item to append
 */
int vec_append(Vector *vec, const void *item);

/**
 * Appends the duplicated value of an item to the beginning of a dynamically-sized array.
 * @param vec Vector to prepend onto
 * @param item Item to prepend
 */
int vec_prepend(Vector *vec, const void *item);

/**
 * Deletes the item at an index inside a dynamically-sized array.
 * @param vec Vector to delete from
 * @param i Index to use
 */
int vec_delete(Vector *vec, vec_size i);

/**
 * Frees/deallocates a dynamically-sized array.
 * @param vec Vector to free/deallocate
 */
void vec_free(Vector *vec);
