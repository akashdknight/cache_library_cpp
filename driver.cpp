#include <bits/stdc++.h>
using namespace std;

#include "cache.h"

#define vi vector<int>

void threadFunc(string type, int key, vi &value, Cache<int, vi > &cacheObject);

void checkLRU();
void checkFIFO();
void checkLIFO();
void checkThreadSafety();

int main(){
    // checkLRU();
    // checkFIFO();
    // checkLIFO();
    // checkThreadSafety();

    return 0;
}

void checkLRU(){
    cout << "\n\n\033[32mChecking LRU cache...\033[0m\n\n";
    Cache<int, string> LRU("LRU", 2);
    LRU.put(1, "key 1");
    LRU.put(2, "key 2");

    cout << LRU.get(1) << endl;
    cout << LRU.get(2) << endl;

    LRU.put(3, "key 3");
    
    try{
        cout << LRU.get(1) << endl;
    }catch(const exception& e){
        cout << "\nError as expected" << endl;
        cerr << e.what() << "\n" << endl;
    }
    cout << LRU.get(2) << endl;
    cout << LRU.get(3) << endl;

    LRU.get(2);
    
    LRU.put(4, "key 4");

    cout << LRU.get(2) << endl;
    try{
        cout << LRU.get(3) << endl;
    }catch(const exception& e){
        cout << "\nError as expected" << endl;
        cerr << e.what() << "\n" << endl;
    }
    cout << LRU.get(4) << endl;

}

void checkFIFO(){
    cout << "\n\n\033[32mChecking FIFO cache...\033[0m\n\n";

    Cache<int, int> FIFO("FIFO", 3);
    FIFO.put(1, 1);
    FIFO.put(2, 2);
    FIFO.put(3, 3);

    cout << FIFO.get(1) << endl;
    cout << FIFO.get(2) << endl;
    cout << FIFO.get(3) << endl;

    FIFO.put(4, 4);
    
    try{
        cout << FIFO.get(1) << endl;
    }catch(const exception& e){
        cout << "\nError as expected" << endl;
        cerr << e.what() << "\n" << endl;
    }
    cout << FIFO.get(2) << endl;
    cout << FIFO.get(3) << endl;
    cout << FIFO.get(4) << endl;

    FIFO.get(2);
    
    FIFO.put(5, 5);

    try{
        cout << FIFO.get(2) << endl;
    }catch(const exception& e){
        cout << "\nError as expected" << endl;
        cerr << e.what() << "\n" << endl;
    }
    cout << FIFO.get(3) << endl;
    cout << FIFO.get(4) << endl;
    cout << FIFO.get(5) << endl;

}

void checkLIFO(){
    cout << "\n\n\033[32mChecking LIFO cache...\033[0m\n\n";

    Cache<int, int> LIFO("LIFO", 3);
    LIFO.put(1, 1);
    LIFO.put(2, 2);
    LIFO.put(3, 3);

    cout << LIFO.get(1) << endl;
    cout << LIFO.get(2) << endl;
    cout << LIFO.get(3) << endl;

    LIFO.put(4, 4);
    
    cout << LIFO.get(1) << endl;
    cout << LIFO.get(2) << endl;

    try{
        cout << LIFO.get(3) << endl;
    }catch(const exception& e){
        cout << "\nError as expected" << endl;
        cerr << e.what() << "\n" << endl;
    }
    cout << LIFO.get(4) << endl;

    LIFO.get(2);
    
    LIFO.put(5, 5);

    cout << LIFO.get(1) << endl;
    cout << LIFO.get(2) << endl;
    try{
        cout << LIFO.get(4) << endl;
    }catch(const exception& e){
        cout << "\nError as expected" << endl;
        cerr << e.what() << "\n" << endl;
    }
    cout << LIFO.get(5) << endl;

}

void checkThreadSafety(){
    Cache<int, vi > LRUCache("LRU", 10);

    vector<int> ans(1e4);
    for(int i = 0; i < 1e4 ; i++){
        ans[i] = i;
    }

    vector<thread> allThreads;
    for(int i = 0; i < 10; i++){
        allThreads.emplace_back(threadFunc, "put", i, ref(ans), ref(LRUCache));
    }

    for(auto &x : allThreads)x.join();

}

void threadFunc(string type, int key, vi &value, Cache<int, vi > &cacheObject){
    if(type == "get"){
        vector<int> ret = cacheObject.get(key); 
    }else if(type == "put"){
        cacheObject.put(key, value);
        cout << "vector inserted for key : " << key  << endl;
    }
}