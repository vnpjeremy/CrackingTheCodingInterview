#include <ch1_prob1.h>
#include <unordered_set>
#include <string>
#include <assert.h>

bool is_unique(std::string const& arg)
{
    std::unordered_set<char> my_set;

    return false;
}

void test_unique(std::string const& arg)
{
    assert(is_unique(arg));
}

void test_nonunique(std::string const& arg)
{
    assert(!is_unique(arg));
}



void ch1_prob1()
{


    std::string unique = "beakmn";
    std::string non_unique = "beakman";
}