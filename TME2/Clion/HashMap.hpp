#ifndef TP2_HASHMAP_HPP
#define TP2_HASHMAP_HPP

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <utility>
#include <forward_list>

template <typename K, typename V>
class HashMap{

public:
    class Entry{
    public:
        const K key;
        V value;
        Entry(const K& k, const V& v):key(k),value(v){}
    };

    class HashMapIte {
    private:
        typedef typename std::vector<std::forward_list < HashMap<K, V>::Entry>>::
        iterator VectorIte;
        typedef typename std::forward_list<HashMap<K, V>::Entry>::iterator ListIte;
        VectorIte Vit;
        ListIte Lit;
    };

private:
    typedef std::vector<std::forward_list<Entry>> buckets_t;
    buckets_t buckets;
    size_t sz;
    HashMapIte hit;
public:
    HashMap(size_t size = 100):sz(0){
        buckets.reserve(size);  // 改变allosize 在操作中不会需要重新申请空间
        for(size_t i = 0; i < size; ++i){
            buckets.emplace_back();
        }
    }

    bool push(const K& key, const V& value){
        size_t index = std::hash<K>()(key) % buckets.size();
        auto &l = buckets.at(index);
        size_t exist_list = 0;
        for(auto it = l.begin(); it != l.end(); ++it){
            if(it->key == key){
                ++exist_list;
                it->value = value;
                return true;
            }
        }
        if(exist_list == 0){
            std::cout <<"im here"<< std::endl;
            l.emplace_front(key, value);
            ++sz;
            return false;
        }
        return false;
    }

    V* get(const K& key){
        size_t index = std::hash<K>()(key) % buckets.size();
        auto l = buckets.at(index);
        for(auto it = l.begin(); it != l.end(); ++it){
            if(it->key == key){
                return &(it->value);
            }else{
                return nullptr;
            }
        }
    }

    size_t size(){
        return sz;
    }

    HashMapIte(VectorIte Vit, ListIte Lit):Vit(Vit), Lit(Lit){}

    HashMapIte operator++(){
        Lit++;
        if(Lit == Vit.end()){
            for(++Vit; Vit != buckets.end(); ++Vit){
                if(!Vit.empty()) {
                    Lit = Vit.begin();
                    break;
                }
            }
        }
            return HashMapIte(Vit, Lit);
    }

    HashMapIte begin(){
        Vit = buckets.begin();
        for(Vit = buckets.begin(); Vit != buckets.end(); ++Vit) {
            if (!Vit.empty()) {
                Lit = Vit.begin();
                break;
            }
        }
        return HashMapIte(Vit, Lit);
    }

    HashMapIte begin(){
        Vit = buckets.begin();
        for(Vit = buckets.end(); Vit != buckets.begin(); --Vit) {
            if (!Vit.empty()) {
                Lit = Vit.end();
                break;
            }
        }
        return HashMapIte(Vit, Lit);
    }

    /*HashMapIte operator!=(){
        if
    }*/





    };
};

#endif //TP2_HASHMAP_HPP
