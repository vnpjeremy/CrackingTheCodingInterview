#include <iostream>
#include <Windows.h>
#include <string>
#include <ch1_prob1.h>
#include <ch1_prob2.h>
#include <ch1_prob3.h>
#include <ch1_prob4.h>

void _chapter1()
{
    ch1_prob1();
    ch1_prob2();
    ch1_prob3();
    ch1_prob4();
}

int main()
{
    std::wstring delay = L"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    OutputDebugString(delay.c_str());

    _chapter1();

    std::wstring hello_world = L"\n\nHello, buttmunch\n\n";
    OutputDebugString(hello_world.c_str());

}