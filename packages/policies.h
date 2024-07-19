#ifndef __POLICIES__
#define __POLICIES__

#include "LRU.h"
#include "FIFO.h"
#include "LIFO.h"
#include <iostream>
using namespace std;

enum class Policy{
    LRU, 
    LIFO,
    FIFO,
    LFU
};

template <typename K, typename V>
struct policyObjects{
    LRUCache<K, V> * LRUObject;
    FIFOCache<K, V> * FIFOObject;
    LIFOCache<K, V> * LIFOObject;
};

Policy getPolicy(string policyName);

#endif