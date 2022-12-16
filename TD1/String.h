#pragma once
#include <cstddef>
#include <iostream>

class String{
    const char* str;
    public :
        String(const char* s);
        size_t length() const;

        friend ostream & operator << (ostream & const string & s);

        ~string();
}

ostream & operator << (ostream & out, const String & s)
