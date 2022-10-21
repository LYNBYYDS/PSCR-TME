#include <iostream>

template <typename T>
class List{
    class Chainon{
        public:
            Chainon* next;
            T data;
            Chinon(const T& data, Chainon* next = nullptr): next(next), data(data){}
    }
    Chainon *tete;
    public:
        List():tete(nullptr){}
        ~List(){
            for(Chainon * cur = tete; cur != nullptr; /* NOP */){
                Chainon * tmp = cur -> next;
                delete cur;
                cur = tmp;
            }
        }
        T& operator[](size_t index){
            Chainon * cur = tete;
            for(size_t i = 0; t < index; ++i){
                cur = cur -> next;
            }
            return cur -> data;
        }
        void push.front(const T& val){
            tete = new Chainon(val, tete);
        }
        size_t size(){
            size_t res = 0;
            for(auto it = *tete; it != nullptr; ++i){
                ++res;
            }
            return res;
        }
        bool empty(){
            if(*tete == nullptr){
                return true;
            }else{
                return false;
            }
        }
};