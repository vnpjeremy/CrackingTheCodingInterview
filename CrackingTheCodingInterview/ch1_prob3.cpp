#include <ch1_prob3.h>
#include <string>
#include <algorithm>

bool is_an_anagram(std::string const& arg1, std::string const& arg2)
{
    std::string local_1 = arg1;
    std::sort(local_1.begin(), local_1.end());

    std::string local_2 = arg2;
    std::sort(local_2.begin(), local_2.end());

    return local_1 == local_2;
}

bool is_an_anagram(char* arg1, char* arg2)
{
    return false;
}

void ch1_prob3()
{
    std::string const test_string_a = "funeral";
    std::string const test_string_b = "realfun";

    std::string const test_string_c = "noob";
    std::string const test_string_d = "boo";

    char const*const test_string_e = "huzzah";
    char const*const test_string_f = "hazzuh";

    char const*const test_string_g = "nope";
    char const*const test_string_h = "yup";

}