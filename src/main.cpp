#include <iostream>
#include "DataStructures.hpp"

int main() {
    using namespace gds;
    SinglyLinkedList<int> sll;
    sll.insertFirst(10);
    sll.insertLast(20);
    sll.display();

    DoublyLinkedList<char> dll;
    dll.insertFirst('A');
    dll.insertLast('B');
    dll.display();

    SinglyCircularList<int> scl;
    scl.insertFirst(1);
    scl.insertLast(2);
    scl.display();

    DoublyCircularList<char> dcl;
    dcl.insertFirst('X');
    dcl.insertLast('Y');
    dcl.display();

    return 0;
}
