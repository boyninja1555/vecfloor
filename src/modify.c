#include "vecfloor/vecfloor.h"
#include <stdlib.h>
#include <string.h>

void *vec_get(const Vector vec, vec_size i)
{
    return (char *)vec.items + i * vec.item_length;
}

int vec_insert(Vector *vec, vec_size i, const void *item)
{
    if (i < 0 || i > vec->length)
        return 1;

    if ((vec->length + 1) * vec->item_length > vec->cap)
    {
        vec->cap *= 2;
        void *dup = realloc(vec->items, vec->cap);
        if (!dup)
        {
            vec->cap /= 2;
            return 1;
        }

        vec->items = dup;
    }

    memmove((char *)vec->items + (i + 1) * vec->item_length, (char *)vec->items + i * vec->item_length, (vec->length - i) * vec->item_length);
    memcpy((char *)vec->items + i * vec->item_length, item, vec->item_length);
    vec->length++;
    return 0;
}

int vec_delete(Vector *vec, vec_size i)
{
    if (i < 0 || i >= vec->length)
        return 1;

    memmove((char *)vec->items + i * vec->item_length, (char *)vec->items + (i + 1) * vec->item_length, (vec->length - i - 1) * vec->item_length);
    vec->length--;
    return 0;
}
