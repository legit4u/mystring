/*
 * A custom string implementation similar to std::string (not exhaustive) using also
 * some modern C++ (C++11) features such as:
 *    rvalue references and move constructor/assignment operators
 *    list initialisation / brace-or-equal initialisers
 *    nullptr
 *    noexcept specifier
 */

#include <iostream>
#include <algorithm>
#include "string.hpp"

using namespace std;

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
string::string() : len(0), str(nullptr) {}

string::string(size_t len, char c) : len(len)
{
    this->str = new char[len+1];
    *(this->str) = {c};
}

string::string(const char * str) : string()
{
    if (str == nullptr)
    {
        return;
    }
    len = strlen(str);
    this->str = new char[len+1];
    std::copy(str, str+len+1, this->str);

}

string::string(const string &rhs)
{
    len = rhs.len;
    this->str = new char[len+1];
    std::copy(rhs.str, rhs.str+len+1, this->str);
}

string::string(string && source) noexcept
{
    len = source.len;
    str = source.str;
    source.str = nullptr;
}

string &string::operator=(const string &rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    if (str != nullptr)
    {
        delete [] str;
    }
    len = rhs.len;
    this->str = new char[len+1];
    std::copy(rhs.str, rhs.str+len+1, this->str);
    return *this;
}

string &string::operator=(string &&rhs) noexcept
{
    if (&rhs == this)
    {
        return * this;
    }

    if (str != nullptr)
    {
        delete [] str;
    }

    len = rhs.len;
    this->str = new char[len + 1];
    std::copy(rhs.str, rhs.str+len+1, this->str);
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

char &string::at(size_t pos)
{
    return str[pos];
}

const char &string::at(size_t pos) const
{
    return str[pos];
}

ostream &operator<<(ostream & out, const mylib::string &str)
{
    // TODO: insert return statement here
    out << str.c_str();
    return out;
}

string operator+(const string &s1, const string &s2)
{
    string s3(s1.size() + s2.size());
    std::copy(s1.c_str(), s1.c_str()+s1.size()+1, s3.str);
    std::copy(s2.c_str(), s2.c_str()+s2.size()+1, s3.str+s1.size());
    return s3;
}

string::~string()
{
    if (str != nullptr)
    {
        delete [] str;
    }
}
const char *string::c_str() const
{
    return str;
}

size_t string::copy(char* s, size_t len, size_t pos) const
{
    if (this->len < pos)
    {
        throw std::out_of_range("Not enough content in string"); 
    }

    size_t numChars = (this->len < (pos + len)) ? this->len - pos : len;
    std::copy(this->str + pos, this->str + pos + numChars, s);
    return numChars;
}
} // namespace mylib