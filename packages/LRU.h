#ifndef __LRU__
#define __LRU__

#include <unordered_map>
#include <stdexcept>
using namespace std;

template <typename K, typename V>
struct LRUnode{
    V value;
    K key;
    LRUnode<K, V> * next;
    LRUnode<K, V> * prev;

    LRUnode(K key , V value, LRUnode<K, V> * next, LRUnode<K, V> * prev);
    LRUnode(LRUnode<K, V> * next, LRUnode<K, V> * prev);
};

template <typename K, typename V>
class LRUCache {
private:
    int presentSize;
    int capacity;
    LRUnode<K, V> * head;
    LRUnode<K, V> * tail;
    unordered_map<K, LRUnode<K, V> *> Cache;

public:
    LRUCache(int capacity);
    V get(K key);
    void put(K key, V value);
    bool remove(K key);
};

#include "LRU_impl.h"

#endif