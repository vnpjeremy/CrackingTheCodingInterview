#include <ch1_prob2.h>
#include <print_to_console.h>
#include <Windows.h>
#include <algorithm>
#include <assert.h>

//Can do this in O(n) time and O(n) space with a buffer
//or... could std::swap()

void reverse_string_in_place(std::string & input_string)
{
    std::reverse(input_string.begin(), input_string.end());
}

//This will infinite loop for non null-terminated strings.
//Could add an if length_of_string == std::max<size_t>() throw std::exception, but adds a branch.
size_t _get_length_of_charstar(char const* str)
{
    char const*  beg_itr = str;
    size_t       length_of_string = 0;
    while (*beg_itr != '\0')
    {
        ++length_of_string;
        ++beg_itr;
    }
    return length_of_string;
}

//char* reverse_string_in_place(char const* input_string) //can't be const if we are attempting in-place
void reverse_charstar_in_place(char* input_string)
{
    //Without the length of an std::string, this will be 2n, but still O(n)
    //With the length we could directly assign a pointer to the end of the string.
    size_t const length_of_string = _get_length_of_charstar(input_string);
    
    char*        beg_itr            = input_string; //don't forget about std::advance<classtype>(itr, distance)
    char*        end_itr            = input_string + length_of_string - 1;
    size_t const string_half_length = length_of_string / 2;

    for(size_t i = 0; i < string_half_length; ++ i)
    {
        std::swap(*beg_itr, *end_itr);
        ++beg_itr;
        --end_itr;
    }    
}

void test_reverse_string(char const* input_string, char const* solution )
{
    assert(!std::strcmp(input_string, solution));
}

void test_reverse_string(std::string const& input_string, std::string const& solution)
{
    assert(!input_string.compare(solution));
}

void ch1_prob2()
{
    char string1[] = "shoop";
    char string2[] = "deadpool";

    std::string solution1 = "poohs";
    std::string solution2 = "loopdaed";
    std::string st1(string1);
    std::string st2(string2);

    reverse_charstar_in_place(string1);
    reverse_charstar_in_place(string2);
    reverse_string_in_place(st1);
    reverse_string_in_place(st2);

    test_reverse_string(string1, solution1.c_str());
    test_reverse_string(string2, solution2.c_str());
    test_reverse_string(st1, solution1);
    test_reverse_string(st2, solution2);

    print_string("Chapter 1 Problem 2 testing passed");
    /*print_string("The swapped string1 is " + std::string(string1));
    print_string("The swapped string2 is " + std::string(string2));

    print_string("The swapped st1 is " + st1);
    print_string("The swapped st2 is " + st2);*/

    
}