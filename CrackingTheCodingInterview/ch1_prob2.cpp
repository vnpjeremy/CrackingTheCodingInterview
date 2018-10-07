#include <ch1_prob2.h>
#include <print_to_console.h>
#include <Windows.h>
#include <algorithm>

//Can do this in O(n) time and O(n) space with a buffer
//or... could std::swap()

//char* reverse_string_in_place(char const* input_string) //can't be const if we are attempting in-place
void reverse_string_in_place(char* input_string)
{
    //Without the length of an std::string, this will be 2n, but still O(n)
    //With the length we could directly assign a pointer to the end of the string.
    char*  beg_itr          = input_string;
    size_t length_of_string = 0;
    while (*beg_itr != '\0')
    {
        std::string str(1, *beg_itr);
        print_string(str);
        ++length_of_string;
        ++beg_itr;
    }

    //don't forget about std::advance<classtype>(itr, distance)
    beg_itr                         = input_string;
    char* end_itr                   = input_string + length_of_string - 1;
    size_t const string_half_length = length_of_string / 2;

    for(size_t i = 0; i < string_half_length; ++ i)
    {
        std::swap(*beg_itr, *end_itr);
        ++beg_itr;
        --end_itr;
    }

    //print_string("The length of the string is " + std::to_string(length_of_string));
    
}

void test_reverse_string(char const*const input_string)
{


}

void ch1_prob2()
{
    char string1[] = "shoop";
    char string2[] = "deadpool";

    reverse_string_in_place(string1);
    reverse_string_in_place(string2);

    print_string("The swapped string1 is " + std::string(string1));
    print_string("The swapped string2 is " + std::string(string2));

    
}