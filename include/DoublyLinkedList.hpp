#pragma once
#include <iostream>
#include <stdexcept>

namespace gds {

template<typename T>
struct nodeD {
    T data;
    nodeD* next;
    nodeD* prev;
    nodeD(const T& val) : data(val), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
    nodeD<T>* head;
    size_t count;
public:
    DoublyLinkedList() : head(nullptr), count(0) {}
    ~DoublyLinkedList() {
        while (head) {
            nodeD<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertFirst(const T& value) {
        nodeD<T>* newn = new nodeD<T>(value);
        newn->next = head;
        if (head) head->prev = newn;
        head = newn;
        ++count;
    }
    void insertLast(const T& value) {
        nodeD<T>* newn = new nodeD<T>(value);
        if (!head) head = newn;
        else {
            nodeD<T>* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newn;
            newn->prev = temp;
        }
        ++count;
    }
    void deleteFirst() {
        if (!head) throw std::out_of_range("List is empty");
        nodeD<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        --count;
    }
    void deleteLast() {
        if (!head) throw std::out_of_range("List is empty");
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            nodeD<T>* temp = head;
            while (temp->next) temp = temp->next;
            temp->prev->next = nullptr;
            delete temp;
        }
        --count;
    }
    void insertAtPos(const T& value, size_t pos) {
        if (pos < 1 || pos > count + 1) throw std::out_of_range("Invalid position");
        if (pos == 1) insertFirst(value);
        else if (pos == count + 1) insertLast(value);
        else {
            nodeD<T>* newn = new nodeD<T>(value);
            nodeD<T>* temp = head;
            for (size_t i = 1; i < pos - 1; ++i) temp = temp->next;
            newn->next = temp->next;
            newn->prev = temp;
            temp->next->prev = newn;
            temp->next = newn;
            ++count;
        }
    }
    void deleteAtPos(size_t pos) {
        if (pos < 1 || pos > count) throw std::out_of_range("Invalid position");
        if (pos == 1) deleteFirst();
        else {
            nodeD<T>* temp = head;
            for (size_t i = 1; i < pos - 1; ++i) temp = temp->next;
            nodeD<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next) toDelete->next->prev = temp;
            delete toDelete;
            --count;
        }
    }
    void display(std::ostream& os = std::cout) const {
        nodeD<T>* temp = head;
        os << "NULL <=>";
        while (temp) {
            os << "| " << temp->data << " |<=>";
            temp = temp->next;
        }
        os << "NULL\n";
    }
    size_t size() const { return count; }
};

} // namespace gds
