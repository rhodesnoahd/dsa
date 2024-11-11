#include <iostream>

int main()
{
    char ch = 'N';
    char* ptr = &ch; // pointer

    std::cout << *ptr << "\n"; // N

    *ptr = 'Z';
    std::cout << ch << "\n"; // Z
  
    ch = '#';
    std::cout << *ptr << std::endl; // #
}