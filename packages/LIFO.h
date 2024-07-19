#ifndef __LIFO__
#define __LIFO__

#include "customStack.h"
#include <unordered_map>
#include <stdexcept>
using namespace std;

template <typename K, typename V>
class LIFOCache{
private:
    customStack<K> evictionQueue;
    unordered_map<K, V> Cache;
    int presentSize;
    int capacity;

public:
    LIFOCache(int capacity);
    V get(K key);
    void put(K key, V value);
    bool remove(K key);
};

#include "LIFO_impl.h"

#endif