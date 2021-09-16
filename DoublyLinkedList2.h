#ifndef _DOUBLY_LINKED_LIST_2_H_
#define _DOUBLY_LINKED_LIST_2_H_

#include <iostream>
#include "Node.h"

/*
    Doubly Linked List with pointers to the head and to the tail,
    every node has two pointers, to the nest element and to the
    previous element
*/
template<typename T>
class DoublyLinkedList2
{
public:
    // Pointers to head and tail nodes
    Node<T> * head;
    Node<T> * tail;

public:
    //Default constructor
    DoublyLinkedList2();

    // Add methods
    void push_back(T data);
    void push_front(T data);

    // Delete methods
    void pop_back();
    void pop_front();

    // Merge Sort
    void sort();
    DoublyLinkedList2<T> merge(DoublyLinkedList2<T> a, DoublyLinkedList2<T> b);

    // Print methods
    void print();
    void reverse_print();
};
// Default Constructor
template<typename T>
DoublyLinkedList2<T>::DoublyLinkedList2()
{
    this->head = nullptr;
    this->tail = nullptr;
}

//Adds an element to the tail of the list
template<typename T>
void DoublyLinkedList2<T>::push_back(T data)
{
    if (!this->tail)
    {
        this->tail = new Node<T>(data);
        this->head = this->tail;
    }
    else
    {
        Node<T> * aux = this->tail;
        this->tail = new Node<T>(data);
        this->tail->prev = aux;
        this->tail->prev->next = this->tail; 
    }
}

// Adds an element at the head of the list
template<typename T>
void DoublyLinkedList2<T>::push_front(T data)
{
    if(!this->head)
    {
        this->head = new Node<T>(data);
        this->tail = this->head;
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
void DoublyLinkedList2<T>::pop_back()
{
    if(!this->tail) return;

    Node<T> * aux = this->tail;
    this->tail = this->tail->prev;
    if (this->tail)
    {
        this->tail->next = nullptr;
        if(this->tail->prev)
        {
            this->tail->prev->next = this->tail;
        }
    }
    else
    {
        this->head = nullptr;
    }
    delete aux;
}

// Deletes the first element of the list
template<typename T>
void DoublyLinkedList2<T>::pop_front()
{
    if (!this->head) return;

    Node<T> * aux = this->head;
    this->head = this->head->next;
    if (this->head)
    {
        this->head->prev = nullptr;
        if(this->head->next)
        {
            this->head->next->prev = this->head;
        }

    }
    else
    {
        this->tail = nullptr;
    }
    delete aux;
}

// Merge sort implementation
template<typename T>
void DoublyLinkedList2<T>::sort()
{
    int size {0}, c{0};
    Node<T> * aux = this->head;
    for(;aux;aux = aux->next)
    {
        size++;
    }
    if (size == 1) return;

    DoublyLinkedList2<T> list1;
    DoublyLinkedList2<T> list2;

    aux = this->head;

    for(;c < size/2;aux = aux->next)
    {
        list1.push_back(aux->data);
        c++;
    }
    for(;aux;aux = aux->next)
    {
        list2.push_back(aux->data);
    }

    list1.sort();
    list2.sort();

    *this = merge(list1,list2);
    
}
template<typename T>
DoublyLinkedList2<T> DoublyLinkedList2<T>::merge(DoublyLinkedList2<T> a, DoublyLinkedList2<T> b)
{
    DoublyLinkedList2<T> c;

    while(a.head && b.head)
    {
        if(a.head->data > b.head->data)
        {
            c.push_back(b.head->data);
            b.pop_front();
        }
        else
        {
            c.push_back(a.head->data);
            a.pop_front();
        }
    }

    while(a.head)
    {
        c.push_back(a.head->data);
        a.pop_front();
    }
    while(b.head)
    {
        c.push_back(b.head->data);
        b.pop_front();
    }

    return c;
}

// Prints every element of the list
template<typename T>
void DoublyLinkedList2<T>::print()
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
void DoublyLinkedList2<T>::reverse_print()
{
    Node<T> * aux = this->tail;
    for(;aux;aux = aux->prev)
    {
        std::cout << aux->data << " -> ";
    }
    std::cout << '\n';
}
#endif  //_DOUBLY_LINKED_LIST_2_H_