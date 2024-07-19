#ifndef __CUSTOM_STACK__
#define __CUSTOM_STACK__

#include <stdexcept>
using namespace std;

template <typename T>
struct stackNode{
    T value;
    stackNode<T> * next;
    stackNode<T> * prev;

    stackNode(T value, stackNode<T> * next, stackNode<T> * prev);
    stackNode(stackNode<T> * next, stackNode<T> * prev);
    void removeNode();
};

template <typename T>
class customStack{
private:
    stackNode<T> * head;
    stackNode<T> * tail;
    int size;

public:
    customStack();
    T top();
    void push(T value);
    void pop();
    bool remove(T value);
};

#include "customStack_impl.h"

#endif