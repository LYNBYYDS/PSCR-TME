

template <typename T>
class list{
    class Chainon{
        public:
            Chainon* next;
            T data;
            Chinon(const T& data, Chainon* next = nullptr): next(next), data(data){}
    }
    Chainon *tete;
    public:
        list():tete(nullptr){}
        ~list(){
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
}