#include <ch1_prob3.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include <print_to_console.h>
#include <vector>

bool is_an_anagram(std::string const& arg1, std::string const& arg2)
{
    if (arg1.size() != arg2.size())
        return false;

    std::string local_1 = arg1;
    std::sort(local_1.begin(), local_1.end());

    std::string local_2 = arg2;
    std::sort(local_2.begin(), local_2.end());

    return local_1 == local_2;
}

size_t find_charstar_length(char const* input)
{
    //char        null_terminator = '\0';
    size_t      length = 0;
    char const* itr = input;
    while (*itr)
    {
        ++length;
        ++itr;
    }
    return length;
}

//This can't be a char const* if we're going to sort in-place.
//Works the same either way, just pay for the copy.
//... Except. We don't have the length of the c-style char array.
//    would have to iterate over it twice, one for length, one for copy.
//    Or create an std::string FROM it. IRL would do that. This isn't C.
//bool is_an_anagram(char* arg1, char* arg2)
bool is_an_anagram(char const*const arg1, char const*const arg2)
{
    size_t arg1_length = find_charstar_length(arg1);
    size_t arg2_length = find_charstar_length(arg2);
    if (arg1_length != arg2_length)
        return false;

    /* scoped_ptr is neither copyable nor moveable.
    
       unique_ptr is not copyable, but is moveable. It supports
       ctr/dtr and therefore pimpl */

    //WTH you can't use non-static member functions to call std::sort??
    //we need to use bind or some similar trick to get this even to work?
    //what a sham! put the damn things in a vector??
    //std::unique_ptr<char> arg1_copy((char*)malloc(arg1_length * sizeof(char))); //std::array?!? //new instead of malloc!?
    //std::unique_ptr<char> arg1_copy(new char[arg1_length]);
    //std::unique_ptr<char> arg2_copy((char*)malloc(arg2_length * sizeof(char))); //Default uses 'delete', not free. This will work if you
                                                                                  //do std::unique_ptr<char, free> mm(...);
    //std::unique_ptr<char> arg2_copy(new char[arg2_length]);
    char* arg1_copy(new char[arg1_length]);
    char* arg2_copy(new char[arg2_length]);

    std::copy(arg1, arg1 + arg1_length, arg1_copy);
    std::copy(arg2, arg2 + arg2_length, arg2_copy);

    std::sort(arg1_copy, arg1_copy + arg1_length); 
    std::sort(arg2_copy, arg2_copy + arg2_length);

    bool const is_anagram = std::equal(arg1_copy, arg1_copy + arg1_length, arg2_copy);

    delete[] arg1_copy; //I'd rather just do a vector.
    delete[] arg2_copy;
    return is_anagram;
}

bool is_an_anagram_smarter(char const* arg1, char const* arg2)
{
    if (!arg1 || !arg2)
        return false; // or throw, maybe. Shouldn't encounter.

    std::vector<char> arg1_copy;
    std::vector<char> arg2_copy;

    char const* itr  = arg1;
    char const* itr2 = arg2;
    while (*itr)
        arg1_copy.push_back(*itr++);
    
    while (*itr2)
        arg2_copy.push_back(*itr2++);

    if (arg1_copy.size() != arg2_copy.size())
        return false;

    std::sort(arg1_copy.begin(), arg1_copy.end());
    std::sort(arg2_copy.begin(), arg2_copy.end());

    return arg1_copy == arg2_copy;
    //return std::equal(arg1_copy.begin(), arg1_copy.end(), arg2_copy.begin());
}


void ch1_prob3()
{
    std::string const test_string_a = "funeral";
    std::string const test_string_b = "realfun";

    std::string const test_string_c = "noob";
    std::string const test_string_d = "boo";

    assert(is_an_anagram(test_string_a, test_string_a));
    assert(!is_an_anagram(test_string_c, test_string_d));
    
    char const*const test_string_e = "huzzah";
    char const*const test_string_f = "hazzuh";

    char const*const test_string_g = "nope";
    char const*const test_string_h = "yup";

    assert(is_an_anagram(test_string_e, test_string_f));
    assert(!is_an_anagram(test_string_g, test_string_h));

    assert(is_an_anagram_smarter(test_string_e, test_string_f));
    assert(!is_an_anagram_smarter(test_string_g, test_string_h));

    print_string("Chapter 1 Problem 3 testing passed");

}