#pragma once

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
        };
        class iterator{

        }
    private:
        typedef std::vector<std::forward_list<Entry>> buckets_t;
        buckets_t buckets;
        size_t sz;
    public:
        HashMap(size_t size):sz(0){
            buckets.reserve(size);  // 改变allosize 在操作中不会需要重新申请空间
            for(size_t i = 0; i < size; ++i){
                buckets.emplace_back();
            }
        }

        //std::hash<std::string> hash_string;
        V* get(const K& key){
            size_t index = hash<k>()(key) % buckets.size();
            forward_list l = buckets.at(index);
            for(auto it = l.begin(); it != l.end(); ++it){
                if((it.tete->data).key == key){
                    return &((it.tete->data).value);
                }else{
                    return nullptr;
                }
            }  
        }
        bool push(cosnt K& key, const V& value){
            size_t index = hash<k>()(key) % buckets.size();
            forward_list l = buckets.at(index);
            size_t isinlist = 0;
            for(auto it = l.begin(); it != l.end(); ++it){
                if((it.tete->data).key == key){
                    isinlist = 1;
                    (it.tete->data).value = value;
                    return true;
                }
            }
            if(isinlist == 0){
                l.emplace_front(key, value);
                return false;
            }
        }
        size_t size(){
            size_t res = 0;
            for(size_t i = 0; i < buckets.size(); ++i){
                forward_list l = buckets.at(i);
                for(auto it = l.begin(), it != l.end; ++it){
                    if(it.tete != nullptr){
                        res++;
                    }
                }
            }
            return res;
        }


};