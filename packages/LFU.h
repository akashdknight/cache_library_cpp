#ifndef __LFU__
#define __LFU__

#include <unordered_map>
#include <stdexcept>
using namespace std;

template <typename K, typename V>
struct LFUnode{
    V value;
    K key;
    LFUnode<K, V> * next;
    LFUnode<K, V> * prev;
    LFUnode<K, V> * child;

    LFUnode(K key, V value, LFUnode<K, V>* next, LFUnode<K, V>* prev, LFUnode<K, V>* child, LFUnode<K, V>* parent);
    LFUnode(LFUnode<K, V>* next, LFUnode<K, V>* prev, LFUnode<K, V>* child, LFUnode<K, V>* parent);
};

template <typename K, typename V>
class LFUCache{
private:
    int presentSize;
    int capacity;
    LFUnode<K, V> * head;
    LFUnode<K, V> * tail;
    unordered_map<K, LFUnode<K, V> *> Cache;

public:
    LFUCache(int capacity);
    V get(K key);
    void put(K key, V value);
    bool remove(K key);
}

#include "LFU_impl.h"

#endif