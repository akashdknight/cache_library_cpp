#ifndef __CUSTOM_QUEUE__
#define __CUSTOM_QUEUE__

#include <stdexcept>
using namespace std;

template <typename T>
struct queueNode{
    T value;
    queueNode<T> * next;
    queueNode<T> * prev;

    queueNode(T value, queueNode<T> * next, queueNode<T> * prev);
    queueNode(queueNode<T> * next, queueNode<T> * prev);
    void removeNode();
};

template <typename T>
class customQueue{
private:
    queueNode<T> * head;
    queueNode<T> * tail;
    int size;

public:
    customQueue();
    T front();
    void push(T value);
    void pop();
    bool remove(T value);
};

#include "customQueue_impl.h"

#endif