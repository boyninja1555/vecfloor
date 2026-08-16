#include "vecfloor/vecfloor.h"

int vec_append(Vector *vec, const void *item)
{
    return vec_insert(vec, vec->length, item);
}

int vec_prepend(Vector *vec, const void *item)
{
    return vec_insert(vec, 0, item);
}
