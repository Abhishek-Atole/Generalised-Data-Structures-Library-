#pragma once
#include <iostream>
#include <stdexcept>

namespace gds {

template<typename T>
struct nodeDC {
    T data;
    nodeDC* next;
    nodeDC* prev;
    nodeDC(const T& val) : data(val), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyCircularList {
    nodeDC<T>* head;
    nodeDC<T>* tail;
    size_t count;
public:
    DoublyCircularList() : head(nullptr), tail(nullptr), count(0) {}
    ~DoublyCircularList() {
        while (count) deleteFirst();
    }
    void insertFirst(const T& value) {
        nodeDC<T>* newn = new nodeDC<T>(value);
        if (!head) {
            head = tail = newn;
            head->next = head->prev = head;
        } else {
            newn->next = head;
            newn->prev = tail;
            head->prev = newn;
            tail->next = newn;
            head = newn;
        }
        ++count;
    }
    void insertLast(const T& value) {
        nodeDC<T>* newn = new nodeDC<T>(value);
        if (!head) {
            head = tail = newn;
            head->next = head->prev = head;
        } else {
            newn->prev = tail;
            newn->next = head;
            tail->next = newn;
            head->prev = newn;
            tail = newn;
        }
        ++count;
    }
    void deleteFirst() {
        if (!head) throw std::out_of_range("List is empty");
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            nodeDC<T>* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        --count;
    }
    void deleteLast() {
        if (!head) throw std::out_of_range("List is empty");
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            nodeDC<T>* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
        --count;
    }
    void insertAtPos(const T& value, size_t pos) {
        if (pos < 1 || pos > count + 1) throw std::out_of_range("Invalid position");
        if (pos == 1) insertFirst(value);
        else if (pos == count + 1) insertLast(value);
        else {
            nodeDC<T>* newn = new nodeDC<T>(value);
            nodeDC<T>* temp = head;
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
        else if (pos == count) deleteLast();
        else {
            nodeDC<T>* temp = head;
            for (size_t i = 1; i < pos - 1; ++i) temp = temp->next;
            nodeDC<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            toDelete->next->prev = temp;
            delete toDelete;
            --count;
        }
    }
    void display(std::ostream& os = std::cout) const {
        if (!head) { os << "NULL\n"; return; }
        nodeDC<T>* temp = head;
        os << "<=>";
        do {
            os << "| " << temp->data << " |<=>";
            temp = temp->next;
        } while (temp != head);
        os << "\n";
    }
    size_t size() const { return count; }
};

} // namespace gds
