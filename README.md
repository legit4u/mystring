A basic implementation of a string class

Unit tests using lest framework from : https://github.com/martinmoene/lest

At the moment compilation/makefile is based on Microsoft Windows platform (cl.exe)

# To Build
Open a Developer Command Prompt for VS 2022
cd to mystring directory

```
gnumake all

usemystring.exe # to run a sample usage of the class
```

### Sample output:
Hello World!

Bye World!!

```
unittest.exe -p #
```

### Sample output: #
unittest.cpp(12): passed: Empty string has length zero (succeed): 0 == string( ).size() for 0 == 0

unittest.cpp(13): passed: Empty string has length zero (succeed): 0 == string("").size() for 0 == 0

unittest.cpp(18): passed: Text compares lexically (succeed): string("hello") != string("HELLO") for hello != HELLO

unittest.cpp(23): passed: Text compares lexically (succeed): string("hello") == string("hello") for hello == hello

unittest.cpp(30): passed: Copy constructor copy constructs (succeed): s1 == s2 for hello == hello

unittest.cpp(40): passed: Copy assignment copy assigns (succeed): s1 == s2 for hello == hello

unittest.cpp(41): passed: Copy assignment copy assigns (succeed): ptr1 != ptr2 for "hello" != "hello"

unittest.cpp(50): passed: Copy assignment is a NOOP during self assignment (succeed): s1 == s1 for hello == hello

All 6 selected tests passed.
