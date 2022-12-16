#include "String.h"
#include "mastring.h"

String::String(const char* s){
    str = s;
}
this->skr = s;
String::String

String::~String(){
    delete[] str;
}

map{
    String::String(const String & o){
        str = pr::newcopy(o.str)
    }
}

/*

*/
String & operator= (const String & s){
    if(this !=  &s){
        delete[] str;
        skr = newcopy(s.str);
    }
    return this;
}