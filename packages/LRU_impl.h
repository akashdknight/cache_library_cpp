#ifndef __LRU_IMPL__
#define __LRU_IMPL__

template <typename K , typename V>
LRUnode<K, V>::LRUnode(K key , V value, LRUnode<K, V> * next, LRUnode<K, V> * prev){
    this->key = key;
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template <typename K , typename V>
LRUnode<K, V>::LRUnode(LRUnode<K, V> * next, LRUnode<K, V> * prev){
    this->next = next;
    this->prev = prev;
}


template <typename K, typename V>
LRUCache<K, V>::LRUCache(int capacity) {

    if(capacity <= 1)capacity = 1;

    this->capacity = capacity;
    this->presentSize = 0;
    this->head = new LRUnode<K, V>(NULL, NULL);
    this->tail = new LRUnode<K, V>(NULL, this->head);
    this->head->next = this->tail;
}

template <typename K, typename V>
void removeNode(LRUnode<K, V> * nodeToRemove){
    if(nodeToRemove){
        if(nodeToRemove->prev){
            nodeToRemove->prev->next = nodeToRemove->next;
        }

        if(nodeToRemove->next){
            nodeToRemove->next->prev = nodeToRemove->prev;
        }

        nodeToRemove->next = NULL;
        nodeToRemove->prev = NULL;
    }
}

template <typename K, typename V>
void insertNodeBefore(LRUnode<K, V> * nodeToInsert, LRUnode<K, V> * targetNode){
    
    if(nodeToInsert && targetNode){
        nodeToInsert->next = targetNode;
        nodeToInsert->prev = targetNode->prev;

        if(targetNode->prev){
            targetNode->prev->next = nodeToInsert;
        }

        targetNode->prev = nodeToInsert;
    }
}

template <typename K, typename V>
V LRUCache<K, V>::get(K key){
    V retValue;
    if(this->Cache.find(key) == this->Cache.end()){
        throw out_of_range("Queried key does not exist");
    }
    LRUnode<K, V> * keyLRUnode = this->Cache[key];

    removeNode(keyLRUnode);
    insertNodeBefore(keyLRUnode, this->tail);

    retValue = keyLRUnode->value;
    return retValue;
}

template <typename K, typename V>
void LRUCache<K, V>::put(K key, V value){
    if(this->Cache.find(key) == this->Cache.end()){
        if(this->presentSize == capacity){
            LRUnode<K, V> * keyLRUnode = this->head->next;

            removeNode(keyLRUnode);

            this->Cache.erase(keyLRUnode->key);
            delete keyLRUnode;

            this->presentSize--;
        }

        LRUnode<K, V> * newLRUnode = new LRUnode<K, V>(key, value, this->tail, this->tail->prev);
        this->Cache[key] = newLRUnode;

        insertNodeBefore(newLRUnode, this->tail);

        this->presentSize++;
    }else{
        LRUnode<K, V> * keyLRUnode = this->Cache[key];
        keyLRUnode->value = value;

        removeNode(keyLRUnode);
        insertNodeBefore(keyLRUnode, this->tail);
    }
}

template <typename K, typename V>
bool LRUCache<K, V>::remove(K key){
    if(this->Cache.find(key) == this->Cache.end()){
        return false;
    }

    LRUnode<K, V> * keyLRUnode = this->Cache[key];
    removeNode(keyLRUnode);
    delete keyLRUnode;
    this->Cache.erase(key);

    this->presentSize--;

    return true;
}

#endif