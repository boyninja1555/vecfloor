#include "vecfloor/vecfloor.h"
#include <stdlib.h>

void vec_free(Vector *vec)
{
    free(vec->items);
    vec->length = 0;
    vec->cap = 0;
    vec->item_length = 0;
}
