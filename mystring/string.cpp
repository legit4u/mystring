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

/*
int main()
{
    mylib::string str1("Hello World!");
    mylib::string str2("Bye World!");
    std::cout << str1 << endl << str2 << endl;
    return 0;
}
*/

namespace
{
    bool areStringsEqual(const mylib::string& str1, const mylib::string& str2) 
    {
        if (str1.size() != str2.size()) 
        {
            return false;
        }
        for (size_t i = 0; i < str1.size(); ++i) 
        {
            if (str1[i] != str2[i]) 
            {
                return false;
            }
        }
    return true;
}

} // anonymous namespace

namespace mylib
{
string::string()
{
    len = 0;
    str = nullptr;
}

string::string(const char * str)
{
    len = strlen(str);
    this->str = new char[len+1];
    strcpy(this->str, str);
}

string::string(const string &rhs)
{
    len = rhs.len;
    this->str = new char[len+1];
    strcpy(this->str, rhs.c_str());
}

string::string(const string &&)
{
}

string &string::operator=(const string &rhs)
{
    // TODO: insert return statement here
    if (&rhs != this)
    {
        len = rhs.len;
        this->str = new char[len+1];
        strcpy(this->str, rhs.c_str());
    }
    return *this; 
}

string &string::operator=(const string &&)
{
    // TODO: insert return statement here
    return *this;
}

size_t string::size() const
{
    return len;
}

bool string::operator==(const string& that) const
{
    return areStringsEqual(*this, that);
}

bool string::operator!=(const string &that) const
{
    return !areStringsEqual(*this, that);
}

char &string::operator[](size_t pos)
{
    // TODO: insert return statement here
    return str[pos];
}

const char &string::operator[](size_t pos) const
{
    return str[pos];
}

ostream &mylib::operator<<(ostream & out, const mylib::string &str)
{
    // TODO: insert return statement here
    out << str.c_str();
    return out;
}
string::~string()
{
    delete [] str;
}
const char *string::c_str() const
{
    return str;
}
}