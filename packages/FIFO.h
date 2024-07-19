#ifndef __FIFO__
#define __FIFO__

#include "customQueue.h"
#include <unordered_map>
#include <stdexcept>
using namespace std;


template <typename K, typename V>
class FIFOCache{
private:
    customQueue<K> evictionQueue;
    unordered_map<K, V> Cache;
    int presentSize;    // can use queue's or map's size directly instead too.
    int capacity;

public:
    FIFOCache(int capacity);
    V get(K key);
    void put(K key, V value);
    bool remove(K key);
};

#include "FIFO_impl.h"

#endif