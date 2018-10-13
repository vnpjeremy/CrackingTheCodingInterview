#pragma once

/*
Ch 1 Prob 1
    A. Implement an algorithm to determine if a string has all unique characters.
    B. What if you cannot use additional data structures?

*/

/*
Solution:
    The obvious solution is a hash table. It has O(1) average complexity [AMORTIZED] (O(n) worst, from
    either 1. hashing to the same key, or 2. having passed load balance, rehash with a bigger
    table. Operation is O(n) but happens at most n/2 times, averaging to O(1))

McDowell's Solution:
    Part A:
        Smart, but I'm not sure if it's really 'better'. Implement a bool array of the length of the
        ASCII character map (if it were all lower-case english aplha non-numerics it would only have
        to be 26. There are 256 ASCII characters, 128 standard and 128 Extended.
        
*/

void ch1_prob1();