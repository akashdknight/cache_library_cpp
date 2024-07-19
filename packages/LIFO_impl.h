#ifndef __LIFO_IMPL__
#define __LIFO_IMPL__

template <typename K, typename V>
LIFOCache<K, V>::LIFOCache(int capacity){
    if(capacity <= 1){
        capacity = 1;
    }
    
    this->capacity = capacity;
    this->presentSize = 0;
}

template <typename K, typename V>
V LIFOCache<K, V>::get(K key){
    V retValue;

    if(this->Cache.find(key) == this->Cache.end()){
        throw out_of_range("Queried key does not exist");
    }

    retValue = this->Cache[key];
    return retValue;
}

template <typename K, typename V>
void LIFOCache<K, V>::put(K key, V value){
    if(this->Cache.find(key) == this->Cache.end()){

        if(this->presentSize == this->capacity){
            K keyToRemove = this->evictionQueue.top();
            this->Cache.erase(keyToRemove);
            this->evictionQueue.pop();

            this->presentSize--;
        }

        this->Cache[key] = value;
        this->evictionQueue.push(key);
        this->presentSize++;
    }else{
        this->Cache[key] = value;
        // no need to update the position in eviction queue
    }
}

template <typename K, typename V>
bool LIFOCache<K, V>::remove(K key){
    if(this->evictionQueue.remove(key)){
        this->Cache.erase(key);
        this->presentSize--;

        return true;
    }
    return false;
}
#endif