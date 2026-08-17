#pragma once

#include "vecfloor/vecfloor.h"

/**
 * Dynamically-sized array representing many characters. Direct alias of Vector with extra utility functions.
 */
typedef Vector String;

/**
 * Allocates an empty String. Capacity is 8 characters by default to optimize initial insertations.
 */
String str_empty(void);

/**
 * Duplicates a cstr into a new String/Vector. Does not duplicate the null terminator.
 * @param cstr Cstr to create a String from
 */
String str_ofcstr(const char *cstr);

/**
 * Duplicates the value of a String into a proper null-terminated cstr.
 * @param str Source String
 * @param cstr Output buffer, which must be at least (str.length + 1) bytes
 */
void str_tocstr(const String str, char *cstr);

/**
 * Duplicates a String to a new instance.
 * @param str String to duplicate
 */
String str_dup(const String str);

/**
 * Retrieves the character at an index inside a String.
 * @param str String to index
 * @param i Index to use
 */
char str_at(const String str, vec_size i);

/**
 * Inserts the duplicated value of a character into a String.
 * @param str String to insert into
 * @param i Index to use
 * @param c Character to insert
 */
int str_insert(String *str, vec_size i, const char c);

/**
 * Appends the duplicated value of a character to the end of a String.
 * @param str String to append onto
 * @param c Character to append
 */
int str_append(String *str, const char c);

/**
 * Appends the duplicated value of a character to the beginning of a String.
 * @param str String to prepend onto
 * @param c Character to prepend
 */
int str_prepend(String *str, const char c);

/**
 * Deletes the character at an index inside a String.
 * @param str String to delete from
 * @param i Index to use
 */
int str_delete(String *str, vec_size i);

/**
 * Whether String A == String B
 * @param a Lefthand String
 * @param b Righthand String
 */
bool str_equals(const String a, const String b);

/**
 * Frees/deallocates a String.
 * @param str String to free/deallocate
 */
void str_free(String *str);
