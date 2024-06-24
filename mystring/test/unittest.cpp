#include "lest.hpp"
#include "string.hpp"

using namespace std;
namespace mylib
{

const lest::test specification[] =
{
    CASE( "Empty string has length zero (succeed)" )
    {
        EXPECT( 0 == string(  ).size() );
        EXPECT( 0 == string("").size() );
    },

    CASE( "Handle construction with invalid pointer (succeed)" )
    {
        char *p = nullptr;
        string s(p);
        EXPECT( 0 == s.size() );
        EXPECT( nullptr == s.c_str() );
    },

    CASE( "Text compares lexically (succeed)" )
    {
        EXPECT( string("hello") != string("HELLO") );
    },

    CASE( "Text compares lexically (succeed)" )
    {
        EXPECT( string("hello") == string("hello") );
    },

    CASE( "Test basic operations (succeed)" )
    {
        string s1 = "hello";
        EXPECT( s1.size() == 5 );
        EXPECT( s1[0] == 'h' );
        EXPECT( s1[4] == 'o' );
        EXPECT( s1.at(0) == 'h' );
        EXPECT( s1.at(4) == 'o' );
    },
    
    CASE( "Copy constructor copy constructs (succeed)" )
    {
        string s1 = "hello";
        string s2 (s1);
        EXPECT( s1 == s2 );
    },

    CASE( "Copy assignment copy assigns (succeed)" )
    {
        string s1 = "hello";
        string s2;
        s2 = s1;
        const char* ptr1 = s1.c_str();
        const char* ptr2 = s2.c_str();
        EXPECT( s1 == s2 );
        EXPECT(  ptr1 != ptr2 );
    },

    CASE( "Copy assignment is a NOOP during self assignment (succeed)" )
    {
        string s1 = "hello";
        const char* ptr1 = s1.c_str();
        s1 = s1;
        const char* ptr2 = s1.c_str();
        EXPECT( s1 == s1 );
    },

    CASE( "Concatenate strings (succeed)" )
    {
        string s1 = "Hello";
        string s2 = "World!";
        string s3 = s1 + " " + s2;
        string s4 = "Hello World!";
        EXPECT( s3 == s4 );
    },

    CASE( "Copy string to buffer (succeed)" )
    {
        string s1 = "Hello World!";
        char* ptr = new char[s1.size()+1];
        size_t len = s1.copy(ptr, 6, 6);
        ptr[len] = '\0';
        string s3(ptr);
        string s4("World!");
        EXPECT( s3 == s4 );
    },

    CASE( "Not enough string to copy (fail with exception)" )
    {
        string s1 = "Hello";
        char* ptr = new char[s1.size()+1];
        EXPECT_THROWS_AS( s1.copy(ptr, 2, 6), std::out_of_range );
    },
};
}
int main( int argc, char * argv[] )
{
    return lest::run( mylib::specification, argc, argv );
}
