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

    CASE( "Text compares lexically (succeed)" )
    {
        EXPECT( string("hello") != string("HELLO") );
    },

    CASE( "Text compares lexically (succeed)" )
    {
        EXPECT( string("hello") == string("hello") );
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
};
}
int main( int argc, char * argv[] )
{
    return lest::run( mylib::specification, argc, argv );
}
