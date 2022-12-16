#include "mastring.h"
#include <cstring> // string.h

size_t pr::length(const char* s){
    size_t sz = 0;

    for(sz = 0; s[sz] != '\0'; sz++){
        //NOP
    }

    /*
    const char* cp;
    for(cp = s; *cp; ++cp){}


    */
    return sz;
}

char* pr::newcopy(const char* s){
    size_t sz = pr::length(s);
    // metode1&2
    // char news = (char*)malloc(sz+1)     // sizeof(char) = 1 所以这里没有加sizeof
    char* cs;
    /* metode 1
    for(cs = news; *s != 0; ++sc, ++s){
        *cs = *s;
    }
    *cs = '\0';
    */

    /* metode 2
    for(char* cs = news;*cs++ = )
    */
    
    // new define tous les case
    // metode avec new
    char* news = new char[sz+1];
    memcpy(news, s, sz+1);
    return news;
}