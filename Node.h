#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
class DoublyLinkedList;

/*
    Node for a doubly Linked List, with two pointers
    to the next and to the previous element of the
    list.
*/
template<typename T>
class Node
{
public:
    T data;
    Node<T> * next;
    Node<T> * prev;
    friend class DoublyLinkedList<T>;
public:
    Node(T data);
};

//Constructor
template<typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

#endif  //_NODE_H_