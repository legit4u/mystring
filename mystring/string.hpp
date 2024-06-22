#ifndef __MYLIB_STRING__
#define  __MYLIB_STRING__
using namespace std;

namespace mylib
{
class string 
{
private:
    char* str = nullptr;
    size_t len = 0;

public:
// Constructors
    string();
    string(const char*);
    string(const string&);
    string(const string&&);

// Assignment
    string& operator=(const string&);
    string& operator=(const string&&);

// Size
    size_t size() const;

// Standard operations
    bool operator==(const string&) const;
    bool operator!=(const string&) const;
    
    char& operator[] (size_t);
    const char& operator[] (size_t) const;

    friend ostream& operator<<(ostream&, const string&);
    
    char& at(size_t);
    const char& at(size_t) const;
    
    char& front();
    const char& front() const;
    
    char& back();
    const char& back() const;

    const char* c_str() const;
    size_t copy(const string&) const;
    size_t find (const string&, size_t pos = 0) const;
    string substr(size_t, size_t) const;


// Iterators
    template <typename Iterator>
    const Iterator begin() const;
   
    ~string();
};
ostream& operator<<(std::ostream&, const mylib::string&);
};

#endif