#include <iostream>
#include <Windows.h>
#include <string>
#include <ch1_prob1.h>
#include <ch1_prob2.h>

int main()
{
    std::wstring delay = L"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    OutputDebugString(delay.c_str());

    ch1_prob1();
    ch1_prob2();

    std::wstring hello_world = L"\n\nHello, buttmunch\n\n";
    OutputDebugString(hello_world.c_str());

}