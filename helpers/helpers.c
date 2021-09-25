#include "helpers.h"
#include "librarys_included.h"
#ifdef __HELPERS_FUNCTIONS_H__
#ifndef __PRINT_LINE_FUNCTION__
#define __PRINT_LINE_FUNCTION__
void println()
{
    printf("\n");
}

#endif

#ifndef __GET_NUMBER_OF_INT_IN_VALUES__
#define __GET_NUMBER_OF_INT_IN_VALUES__
int number_of_chars_to_allow_in_memory(int value)
{

    int result = 0;
    do
    {
        result++;
    } while ((value = value / 10));

    return result;
}
#endif
#endif
