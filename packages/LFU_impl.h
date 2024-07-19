#ifndef __LFU_IMPL__
#define __LFU_IMPL__

template <typename K, typename V>
LFUnode<K, V>::LFUnode(K key, V value, LFUnode<K, V> * next, LFUnode<K, V> * prev, LFUnode<K, V> * child, LFUnode<K, V>* parent){
    this->key = key;
    this->value = value;
    this->next = next;
    this->prev = prev;
    this->child = child;
    this->parent = parent;
}

template <typename K, typename V>
LFUnode<K, V>::LFUnode(LFUnode<K, V>* next, LFUnode<K, V>* prev, LFUnode<K, V>* child, LFUnode<K, V>* parent){
    this->next = next;
    this->prev = prev;
    this->child = child;
    this->parent = parent;
}

template <typename K, typename V>
LFUCache(int capacity){
    if(capacity <= 1)capacity = 1;

    this->capacity = capacity;
    this->presentSize = 0;
    this->head = new LFUnode<K, V>(NULL, NULL, NULL);
    this->tail = new LFUnode<K, V>(NULL, this->head, NULL);
    this->head->next = this->tail;
}

#endif