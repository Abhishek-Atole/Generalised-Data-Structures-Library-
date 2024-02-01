#pragma once
#include <iostream>
#include <stdexcept>

namespace gds {

template<typename T>
struct nodeS {
    T data;
    nodeS* next;
    nodeS(const T& val) : data(val), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
    nodeS<T>* head;
    size_t count;
public:
    SinglyLinkedList() : head(nullptr), count(0) {}
    ~SinglyLinkedList() {
        while (head) {
            nodeS<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertFirst(const T& value) {
        nodeS<T>* newn = new nodeS<T>(value);
        newn->next = head;
        head = newn;
        ++count;
    }
    void insertLast(const T& value) {
        nodeS<T>* newn = new nodeS<T>(value);
        if (!head) head = newn;
        else {
            nodeS<T>* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newn;
        }
        ++count;
    }
    void deleteFirst() {
        if (!head) throw std::out_of_range("List is empty");
        nodeS<T>* temp = head;
        head = head->next;
        delete temp;
        --count;
    }
    void deleteLast() {
        if (!head) throw std::out_of_range("List is empty");
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            nodeS<T>* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        --count;
    }
    void insertAtPos(const T& value, size_t pos) {
        if (pos < 1 || pos > count + 1) throw std::out_of_range("Invalid position");
        if (pos == 1) insertFirst(value);
        else if (pos == count + 1) insertLast(value);
        else {
            nodeS<T>* newn = new nodeS<T>(value);
            nodeS<T>* temp = head;
            for (size_t i = 1; i < pos - 1; ++i) temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
            ++count;
        }
    }
    void deleteAtPos(size_t pos) {
        if (pos < 1 || pos > count) throw std::out_of_range("Invalid position");
        if (pos == 1) deleteFirst();
        else {
            nodeS<T>* temp = head;
            for (size_t i = 1; i < pos - 1; ++i) temp = temp->next;
            nodeS<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            --count;
        }
    }
    void display(std::ostream& os = std::cout) const {
        nodeS<T>* temp = head;
        while (temp) {
            os << "| " << temp->data << " |->";
            temp = temp->next;
        }
        os << "NULL\n";
    }
    size_t size() const { return count; }
};

} // namespace gds
