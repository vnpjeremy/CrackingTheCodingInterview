#include <ch1_prob1.h>
#include <unordered_set>
#include <print_to_console.h>
#include <array>
#include <bitset>
#include <assert.h>
#include <Windows.h>


bool is_unique_bool_array(std::string const& input_string)
{
    //std::array<bool> is NOT a bitset. We'll do that after.
    std::array<bool, 256> ascii_check_map = { false };
    for (char const& i : input_string)
    {
        if (ascii_check_map[i])
            return false;
        else
            ascii_check_map[i] = true;
    }
    return true;
}


bool is_unique_bitset(std::string const& input_string)
{
    std::bitset<256> bitset_check_map;
    for (char const& i : input_string)
    {
        if (bitset_check_map[i])
            return false;
        else
            bitset_check_map[i] = true;
    }
    return true;
}

//This implementation will have to just store the string and loop over the substrings
//repeatedly as a naive solution. O(n^2)
bool is_unique_no_data_structures(std::string const& input_string)
{
    for (size_t i = 0; i < input_string.size(); ++i)
    {
        for (size_t j = 0; j < input_string.size(); ++j)
        {
            if (i == j)
                continue;
            if (input_string[i] == input_string[j])
                return false;
        }
    }
    return true;
}

//RVO: ZS said is related to single-return path. This seems to contradict it:
//https://softwareengineering.stackexchange.com/questions/118703/where-did-the-notion-of-one-return-only-come-from
bool is_unique_hash_version(std::string const& input_string)
{
    std::unordered_set<char> my_set;
    for (char const& i : input_string)
    {
        if (my_set.end() == my_set.find(i))
            my_set.insert(i);
        else
            return false;
    }
    return true;
}

void test_unique(std::string const& input_string)
{
    assert(is_unique_hash_version      (input_string));
    assert(is_unique_bool_array        (input_string));
    assert(is_unique_bitset            (input_string));
    assert(is_unique_no_data_structures(input_string));
}

void test_nonunique(std::string const& input_string)
{
    assert(!is_unique_hash_version      (input_string));
    assert(!is_unique_bool_array        (input_string));
    assert(!is_unique_bitset            (input_string));
    assert(!is_unique_no_data_structures(input_string));
}



void ch1_prob1()
{
    std::string unique_test     = "beakmn";
    std::string non_unique_test = "beakman";

    test_nonunique(non_unique_test);
    test_unique   (unique_test);

    print_string(std::string("Chapter 1 Problem 1 testing passed\n\n"));
}