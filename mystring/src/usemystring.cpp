/*
Imagine std::string did not exist and you need to write a multiplatform 
string class with similar functionality to the one provided by the STL. 
Provide at least 8 different functions (operators do count as functions) beyond
 constructors. Provide the solution in a compressed git folder including all the
commits and specify which Modern standard C++ version was used. In case you used
unit tests, and/or a building toolchain, please include them as well in the 
compressed git folder
*/

#include <iostream>
#include "string.hpp"

using namespace std;

int main()
{
    mylib::string str1("Hello World!");
    mylib::string str2("Bye World!!");
    std::cout << str1 << endl << str2 << endl;
    return 0;
}
