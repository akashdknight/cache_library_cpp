#ifndef __CACHE__
#define __CACHE__

#include "./packages/index.h"
#include <iostream>
#include <shared_mutex>
#include <thread>
using namespace std;

template <typename K, typename V>
class Cache{
    
    private:
        Policy evictionPolicy;
        int maxSize;
        policyObjects<K, V> policyObject;
        mutable shared_mutex cacheMutex;

    public:
        Cache(string evictionPolicy, int maxSize);
        V get(K key);
        void put(K key, V value);
        bool remove(K key);

};

#include "cache_impl.h"

#endif