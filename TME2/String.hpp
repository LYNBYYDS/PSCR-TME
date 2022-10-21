#pragma once
#include <cstddef> // size_t
#include "strutil.h"

namespace pr {

    class String {
    const char * str;
        public:
        // ctor : copie
        String(const char *cstr=""): str(newcopy(cstr)){}
        // dtor : libère
        virtual ~String(){
            delete [] str;
        }

        // taille
        size_t length()const{ 
            return pr::length(str);
        }
    };

} // fin namespace pr