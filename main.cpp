#include "DoublyLinkedList.h"
#include "DoublyLinkedList2.h"

int main()
{
    DoublyLinkedList2<int> lista;

    lista.push_back(32);
    lista.push_back(5);
    lista.push_back(73);
    lista.push_front(10);
    lista.print();
    lista.reverse_print();

    std::cout << lista.head->next->prev->data << '\n';

    lista.print();
    lista.reverse_print();

    DoublyLinkedList<float> lista2;

    lista2.push_back(10.6);
    lista2.push_back(1.5);
    lista2.push_back(23.45);
    lista2.push_back(14.34);
    lista2.print();
    lista2.reverse_print();

    lista.sort();
    lista.print();



    return 0;
}