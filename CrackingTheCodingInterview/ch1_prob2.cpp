#include <ch1_prob2.h>
#include <print_to_console.h>
#include <Windows.h>

//Can do this in O(n) time and O(n) space with a buffer
//or... could std::swap()

char* reverse_string_in_place(char const* input_string)
{
    //Without the length of an std::string, this will be 2n, but still O(n)
    char const* beg_itr = input_string;
    while (*beg_itr != '\0')
    {
        std::string str(1, *beg_itr);
        print_string(str);

        ++beg_itr;
    }

    char dummy[] = "1234";
    return dummy;
}

void test_reverse_string(char const*const input_string)
{


}

void ch1_prob2()
{
    char string1[] = "shoop";
    char string2[] = "deadpool";

    char* out = reverse_string_in_place(string1);
    
}