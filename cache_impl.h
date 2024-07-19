#ifndef __CACHE_IMPL__
#define __CACHE_IMPL__

template <typename K, typename V>
Cache<K, V>::Cache(string evictionPolicy, int maxSize){
    this->evictionPolicy = getPolicy(evictionPolicy);
    this->maxSize = maxSize;
    
    if(this->evictionPolicy == Policy::LRU){
        this->policyObject.LRUObject = new LRUCache<K, V>(this->maxSize);
    }else if(this->evictionPolicy == Policy::FIFO){
        this->policyObject.FIFOObject = new FIFOCache<K, V>(this->maxSize);
    }else if(this->evictionPolicy == Policy::LIFO){
        this->policyObject.LIFOObject = new LIFOCache<K, V>(this->maxSize);
    }
}

template <typename K, typename V>
V Cache<K, V>::get(K key){ 
    shared_lock<shared_mutex> lock(cacheMutex);
    
    V retValue;
    if(this->evictionPolicy == Policy::LRU){
        retValue = (this->policyObject.LRUObject->get(key));
    }else if(this->evictionPolicy == Policy::FIFO){
        retValue = (this->policyObject.FIFOObject->get(key));
    }else if(this->evictionPolicy == Policy::LIFO){
        retValue = (this->policyObject.LIFOObject->get(key));
    }

    // lock.unlock(); //this is not even required since shared mutex gets unlocked once its scope ends.
    return retValue;
}

template <typename K, typename V>
void Cache<K, V>::put(K key, V value){
    unique_lock<shared_mutex> lock(cacheMutex);
    
    //the following line is to simulate time taking process
    //it should be used only to verify thread safety.
    //keep it commented otherwise.
    // this_thread::sleep_for(chrono::milliseconds(500));

    if(this->evictionPolicy == Policy::LRU){
        this->policyObject.LRUObject->put(key, value);
    }else if(this->evictionPolicy == Policy::FIFO){
        this->policyObject.FIFOObject->put(key, value);
    }else if(this->evictionPolicy == Policy::LIFO){
        this->policyObject.LIFOObject->put(key, value);
    }

    // lock.unlock();
}

template <typename K, typename V>
bool Cache<K, V>::remove(K key){ 
    unique_lock<shared_mutex> lock(cacheMutex);
    
    if(this->evictionPolicy == Policy::LRU){
        return (this->policyObject.LRUObject->remove(key));
    }else if(this->evictionPolicy == Policy::FIFO){
        return (this->policyObject.FIFOObject->remove(key));
    }else if(this->evictionPolicy == Policy::LIFO){
        return (this->policyObject.LIFOObject->remove(key));
    }

    // lock.unlock();
}

#endif