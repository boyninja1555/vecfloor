#include "vecfloor/vecfloor.h"
#include <stdlib.h>

void vec_free(Vector *vec)
{
    for (vec_size i = 0; i < vec->length; i++)
    {
        void *item = &vec->items + i;
        free(item);
    }

    vec->length = 0;
    vec->cap = 0;
    vec->item_length = 0;
}
