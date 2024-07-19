#ifndef __CUSTOM_QUEUE_IMPL__
#define __CUSTOM_QUEUE_IMPL__

template <typename T>
queueNode<T>::queueNode(T value, queueNode<T>* next, queueNode<T>* prev){
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template <typename T>
queueNode<T>::queueNode(queueNode<T>* next, queueNode<T>* prev){
    this->next = next;
    this->prev = prev;
}

template <typename T>
void queueNode<T>::removeNode(){
    queueNode<T> * nodeToRemove = this;
    if(nodeToRemove->prev){
        nodeToRemove->prev->next = nodeToRemove->next;
    }
    if(nodeToRemove->next){
        nodeToRemove->next->prev = nodeToRemove->prev;
    }
    delete nodeToRemove;
}

template <typename T>
customQueue<T>::customQueue(){
    this->size = 0;
    this->head = new queueNode<T>(NULL, NULL);
    this->tail = new queueNode<T>(NULL, this->head);
    this->head->next = this->tail;
}

template <typename T>
T customQueue<T>::front(){
    T retValue;
    if(this->size == 0){
        throw out_of_range("Cannot read from empty queue");
    }else{
        retValue = this->head->next->value;
    }

    return retValue;
}

template <typename T>
void customQueue<T>::push(T value){
    queueNode<T> * newNode = new queueNode<T>(value, this->tail, this->tail->prev);
    newNode->next->prev = newNode;
    newNode->prev->next = newNode;

    this->size++;
}

template <typename T>
void customQueue<T>::pop(){
    if(this->size == 0){
        throw out_of_range("cannot pop from empty queue");
    }
    queueNode<T> * nodeToRemove = this->head->next;
    nodeToRemove->removeNode();
    this->size--;
}

template <typename T>
bool customQueue<T>::remove(T value){
    queueNode<T> * present = this->head->next;
    while(present && present != this->tail){
        if(present->value == value){
            present->removeNode();
            this->size--;
            return true;
        }
        present = present->next;
    }
    return false;
}

#endif