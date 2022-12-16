#pragma once

#include <iostream>

template <typename T>
class Vector{
    size_t allo_sz;
    size_t sz;
    T* tab;
    public:
        Vector(size_t init = 10):allo_sz(init), sz(0)){
            tab = new T[allo_sz];
        }
        ~Vector(){
            delete[]tab;
        }
        /*
        T* access_at(size_t index, T* tab){
            return teb+index
        }
        */
       T& operator[](size_t index){
        return tab[index];
       }
       const T& operator[](size_t index)const{
        return tab[index];
       }
       void push_back(const T& val){
        if(sz >= alloc_sz){
            alloc_sz *= 2;  // log si N alloc
            T* tmp = new T[alloc_sz];
            for(size_t i = 0; i < sz; ++i){
                tmp[i] = tab[i];
                delete[] tab;
                tab = tmp;
            }
            tab[sz+1] = val;
        }
        size_t size()const{
            return sz;
        }
        bool empty()const{
            if(sz == 0){
                return true;
            }else{
                return false;
            }
        }
    }
};