#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <iostream>
#include "Node.h"
/*
    Doubly linked list that only has a head, but the nodes have two pointers,
    to the next one and to the the previous one.
*/
template<typename T>
class DoublyLinkedList
{
public:
    Node<T> * head;

public:
    // Cosntructor
    DoublyLinkedList();

    // Adding methods
    void push_back(T data);
    void push_front(T data);

    // Delete methods
    void pop_back();
    void pop_front();

    void sort();
    
    // Print methods
    void print();
    void reverse_print();

    

};

// Default Constructor
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = nullptr;
}

// Adds an element to the end of the list
template<typename T>
void DoublyLinkedList<T>::push_back(T data)
{
    if (!this->head)
    {
        this->head = new Node<T>(data);
    }
    else
    {
        Node<T> ** aux = &this->head;
        Node<T> ** aux2 = nullptr;

        while(*aux)
        {
            aux2 = aux;
            aux = &(*aux)->next;
        }
        *aux = new Node<T>(data);
        (*aux2)->next = *aux;
        (*aux)->prev = *aux2;
    }
}

// Adds an element to the start of the list
template<typename T>
void DoublyLinkedList<T>::push_front(T data)
{
    if(!this->head)
    {
        this->head = new Node<T>(data);
    }
    else
    {
        Node<T> * aux = this->head;
        this->head = new Node<T>(data);
        this->head->next = aux;
        this->head->next->prev = this->head; 
    }
}

// Deletes the last element of the list
template<typename T>
void DoublyLinkedList<T>::pop_back()
{
    if(!this->head) return;

    Node<T> ** aux = &this->head;
    for(;(*aux)->next;aux = &(*aux)->next);
    delete *aux;
    *aux = nullptr;
}

// Deletes the first element of the list
template<typename T>
void DoublyLinkedList<T>::pop_front()
{
    if(!this->head) return;

    Node<T> * aux = this->head;
    this->head = this->head->next;
    if(this->head->next)
    {
        this->head->next->prev = this->head;
    }
    delete aux;
    aux = nullptr;
}

// Prints every element on the list
template<typename T>
void DoublyLinkedList<T>::print()
{
    Node<T> * aux = this->head;
    for(;aux;aux = aux->next)
    {
        std::cout << aux->data << " -> ";
    }
    std::cout << '\n';
}

// Prints every element of the list the other way around
template<typename T>
void DoublyLinkedList<T>::reverse_print()
{
    if (!this->head) return;

    Node<T> * aux = this->head;
    for(;aux->next;aux = aux->next);
    for(;aux;aux = aux->prev)
    {
        std::cout << aux->data << " -> ";
    }
    std::cout << '\n';
}

#endif  //_DOUBLY_LINKED_LIST_H_