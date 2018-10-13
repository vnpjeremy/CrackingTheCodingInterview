#pragma once

/*
Ch 1 Prob 4
    Write a function to replace spaces in a string with '%20'.

    Assume you have the full length of the string as well as enough
    space at the end to add to it

    We can do this in linear time but also linear space. Need a buffer
    the size of the string.

    OR, can start at the *end* of the string. Then not worry about overwriting.
    Don't have to iterate over it to find the last pointer as we have size.*/

void ch1_prob4();