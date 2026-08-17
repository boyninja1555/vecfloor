#include "vecfloor/vecfloor.h"
#include <string.h>

int vec_append(Vector *vec, const void *item)
{
    return vec_insert(vec, vec->length, item);
}

int vec_prepend(Vector *vec, const void *item)
{
    return vec_insert(vec, 0, item);
}

bool vec_equals(const Vector a, const Vector b)
{
    return a.length == b.length && a.item_length == b.item_length && memcmp(a.items, b.items, a.length) == 0;
}
