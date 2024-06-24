#ifndef __MYLIB_STRING__
#define  __MYLIB_STRING__
using namespace std;

namespace mylib
{
class string 
{
private:
    char* str;
    size_t len;

public:
// Constructors
    string();
    string(size_t, char c = '\0');
    string(const char*);
    string(const string&);
    string(string&&) noexcept;

// Assignment
    string& operator=(const string&);
    string& operator=(string&&) noexcept;

// Size
    size_t size() const;

// Standard operations
    bool operator==(const string&) const;
    bool operator!=(const string&) const;
    
    char& operator[] (size_t);
    const char& operator[] (size_t) const;

    friend ostream& operator<<(ostream&, const string&);
    friend string operator+ (const string&, const string&);
    
    char& at(size_t);
    const char& at(size_t) const;
    
    char& front();
    const char& front() const;
    
    char& back();
    const char& back() const;

    const char* c_str() const;
    size_t copy(char*, size_t, size_t pos = 0) const;
    size_t find (const string&, size_t pos = 0) const;
    string substr(size_t, size_t) const;


// Iterators
    template <typename Iterator>
    const Iterator begin() const;
   
    ~string();
};
};

#endif