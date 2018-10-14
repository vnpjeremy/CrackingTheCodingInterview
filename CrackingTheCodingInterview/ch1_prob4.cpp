#include <ch1_prob4.h>




//We are moving from ' ' to '%20', 1 to 3. An increase of 2.
//Each test string should have 2x the number of spaces allocated
//at the end of the string.

void replace_spaces_cstyle(char* input, size_t length)
{
    size_t num_spaces = 0; //could also be unsigned int
    for (size_t ii = 0; ii < length; ++ii)
    {
        if (input[ii] == ' ')
            ++num_spaces;
    }

    size_t const new_length     = length + num_spaces * 2;
    char*        itr_string_end = input  + length;
    char*        itr_new_end    = input  + new_length;

    //for(size_t ii = new_length; ii >= 0; --ii) //--------------------review how to get around the decrement gotcha with unsigned integers!! JSK
    for (size_t ii = new_length; ii-- > 0; ) //Special use of the POST-increment
    {
        for (size_t jj = length; jj-- > 0; )
        {

        }
    }

}

void replace_spaces_cpp11()
{

}

void ch1_prob4()
{
    size_t const len = 23;

    /* Assumptions: 
           We know the 'length' of the string. We assume this to mean the
           length of the assigned characters, as 'past the string' might be
           null terminated, or it might not, as we know it *is* allocated.
           Pass once to count the number of spaces. Multiply by 2 to get
           total added elements (1->3)
    */
    char test_arr_1[len] = "the small things";
   
    replace_spaces_cstyle(test_arr_1, len);

    //Test leading character space! End character space!

    replace_spaces_cpp11();

}