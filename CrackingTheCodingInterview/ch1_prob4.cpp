#include <ch1_prob4.h>




//We are moving from ' ' to '%20', 1 to 3. An increase of 2.
//Each test string should have 2x the number of spaces allocated
//at the end of the string.

void replace_spaces(char* input, size_t length)
{
    char* itr = input + length;
}

void ch1_prob4()
{
    size_t const len = 23;
    char test_arr_1[len] = "the small things      ";
   
    replace_spaces(test_arr_1, len);

}