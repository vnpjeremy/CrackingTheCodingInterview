#include <print_to_console.h>
#include <Windows.h>

void print_string(std::string input_string)
{
    std::wstring str2(input_string.length(), L' '); // Make room for characters
    std::copy(input_string.begin(), input_string.end(), str2.begin());
    OutputDebugString(str2.c_str());

    std::wstring endline = L"\n";
    OutputDebugString(endline.c_str());
}
