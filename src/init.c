#include "vecfloor/vecfloor.h"
#include <stdlib.h>
#include <string.h>

Vector vec_empty(vec_isize item_length)
{
    vec_size cap = VEC_DEFCAP * item_length;
    return (Vector){
        .length = 0,
        .cap = cap,
        .item_length = item_length,
        .items = malloc(cap),
    };
}

Vector vec_of(vec_size length, vec_isize item_length, const void *items)
{
    vec_size cap = (length == 0 ? VEC_DEFCAP : length) * item_length;
    void *dup = malloc(cap);
    if (length > 0)
        memcpy(dup, items, length * item_length);

    return (Vector){
        .length = length,
        .cap = cap,
        .item_length = item_length,
        .items = dup,
    };
}

Vector vec_dup(const Vector vec)
{
    return vec_of(vec.length, vec.item_length, vec.items);
}
