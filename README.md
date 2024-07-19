# **In memory cache library for cpp.**

### **General Info** : 
- Supports all data types including the user-defined types.
- Supports following eviction policies :     
   - LRU
   - FIFO
   - LIFO
- Ensures thread safety.

#### **LRU** : 
- *Least Recently Used*  Eviction policy.
- In case the user tries to insert new key-value pair to Cache when it has reached its capacity (size limit) , the least recently used key-value pair will be removed from the cache in order to accommodate new insertion.
- Cases in which keys are considered to be *used* :     
    - When user inserts a new key.
    - When user updates the existing key.
    - When user reads the value of key.

#### **FIFO** : 
- *First In First Out*  Eviction Policy
- In case the user tries to insert new key-value pair to Cache when it has reached its capacity (size limit) , the key-value pair inserted first among all the present key-value pairs will be removed from the cache in order to accommodate new insertion.
- Internally uses self-implemented queue data structure.
- Updation of value of existing key and Reading the value of a key will **not** reset the the position in queue.

#### **LIFO** : 
- *Last In First Out*  Eviction Policy
- In case the user tries to insert new key-value pair to Cache when it has reached its capacity (size limit) , the key-value pair inserted last (latest) among all the present key-value pairs will be removed from the cache in order to accommodate new insertion.
- Internally uses self-implemented stack data structure.
- Updation of value of existing key and Reading the value of a key will **not** reset the the position in queue.
----------------------
### **Usage**:
- Initialise Cache Object :       
  - `Cache<key-type, value-type> varName(string, int);`
  - First argument : `eviction policy`   
    - {"LRU", "LIFO", "FIFO"} (case insensitive)
  - Second argument : `max size`
    - any integer
  - Examples : 
    - `Cache<int, string> myCache("LRU", 10);`
    - `Cache< string, vector<int> > myCache2("fifo", 6);`

- Other methods : 
    - void Cache.put(key, value);    
        - `myCache.put(2, "two");`
    - value Cache.get(key);    
        - `string val = myCache.get(2);`
    - bool Cache.remove(key);
        - returns false if key could not be deleted(not found), true otherwise.
        - `myCache.remove(2);`

- Check `driver.cpp` for further examples and test code.

### **`Warning`**:
- `Cache.get(key)` throws error if key is not found in the Cache. So, in case of doubt, use it inside try catch block. Can be modified to return a default value if key not found after discussion. 
----------------

### **Adding Custom eviction policies** : 
- Create a new Class and write the logic in .h file
- Open `packages/policies.h`
- include the new .h file
- update `Policy enum` and `policyObjects` to include new eviction Policy.
- Update `getPolicy` function in `packages/policies.cpp`.
- Update if else class inside functions in `cache_impl.h` to include new eviction policy.
-----------------------

### **Testing** : 
- run the command `make`
- In driver.cpp, functions are defined with names `checkLRU` , `checkFIFO`, `checkLIFO`, `checkThreadSafety`.
- Just call the required function and see the output and play around as required.
- For checkThreadSafety, you should put and get some time taking values to actually see the difference but instead you can uncomment sleep function inside put function of `cache_impl.h` to simulate the same.

----------------
**Authored by :** `Akash C R (akashnavya2001@gmail.com)` 