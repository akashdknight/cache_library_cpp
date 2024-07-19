#ifndef __CUSTOM_STACK_IMPL__
#define __CUSTOM_STACK_IMPL__

template <typename T>
stackNode<T>::stackNode(T value, stackNode<T>* next, stackNode<T>* prev){
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template <typename T>
stackNode<T>::stackNode(stackNode<T>* next, stackNode<T>* prev){
    this->next = next;
    this->prev = prev;
}

template <typename T>
void stackNode<T>::removeNode(){
    stackNode<T> * nodeToRemove = this;
    if(nodeToRemove->prev){
        nodeToRemove->prev->next = nodeToRemove->next;
    }

    if(nodeToRemove->next){
        nodeToRemove->next->prev = nodeToRemove->prev;
    }
    delete nodeToRemove;
}


template <typename T>
customStack<T>::customStack(){
    this->size = 0;
    this->head = new stackNode<T>(NULL, NULL);
    this->tail = new stackNode<T>(NULL, this->head);
    this->head->next = this->tail;
}

template <typename T>
T customStack<T>::top(){
    T retValue;

    if(this->size == 0){
        throw out_of_range("Cannot read from empty stack");
    }else{
        retValue = this->tail->prev->value;
    }
    return retValue;
}

template <typename T>
void customStack<T>::push(T value){
    stackNode<T> * newNode = new stackNode<T>(value, this->tail, this->tail->prev);
    newNode->prev->next = newNode;
    newNode->next->prev = newNode;

    this->size++;
}

template <typename T>
void customStack<T>::pop(){
    if(this->size == 0){
        throw out_of_range("cannot pop from empty stack");
    }
    stackNode<T> * nodeToRemove = this->tail->prev;
    nodeToRemove->removeNode();
    this->size--;
}

template <typename T>
bool customStack<T>::remove(T value){
    stackNode<T> * present = this->tail->prev;
    while(present && present != this->head){
        if(present->value == value){
            present->removeNode();
            this->size--;
            return true;
        }
        present = present->prev;
    }
    return false;
}

#endif