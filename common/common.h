#ifndef COMMON_H
#define COMMON_H

#pragma once
#include "../types.h"

/* Helper function to convert interger to string, used in logger
 */
s8int *integer_to_string(u32int number);

/* Helper function to calculate length of string, used in logger
 */
u32int strlen(const char *str);

/* Helper function for memset, used in paging and heap
 */
void custom_memset(u8int *address, u32int val, u32int size);

#endif 
