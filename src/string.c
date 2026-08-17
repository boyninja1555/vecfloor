#include "vecfloor/string.h"
#include <string.h>

String str_empty(void)
{
    return vec_empty(sizeof(char));
}

String str_ofcstr(const char *cstr)
{
    return vec_of(strlen(cstr), sizeof(char), cstr);
}

void str_tocstr(const String str, char *cstr)
{
    memcpy(cstr, str.items, str.length);
    cstr[str.length] = '\0';
}

String str_dup(const String str)
{
    return vec_dup(str);
}

char str_at(const String str, vec_size i)
{
    return *(char *)vec_get(str, i);
}

int str_insert(String *str, vec_size i, const char c)
{
    return vec_insert(str, i, &c);
}

int str_append(String *str, const char c)
{
    return vec_append(str, &c);
}

int str_prepend(String *str, const char c)
{
    return vec_prepend(str, &c);
}

int str_delete(String *str, vec_size i)
{
    return vec_delete(str, i);
}

bool str_equals(const String a, const String b)
{
    return vec_equals(a, b);
}

void str_free(String *str)
{
    vec_free(str);
}
