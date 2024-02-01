#pragma once
#include <iostream>
#include <stdexcept>

namespace gds {

template<typename T>
struct nodeSC {
    T data;
    nodeSC* next;
    nodeSC(const T& val) : data(val), next(nullptr) {}
};

template<typename T>
class SinglyCircularList {
    nodeSC<T>* head;
    nodeSC<T>* tail;
    size_t count;
public:
    SinglyCircularList() : head(nullptr), tail(nullptr), count(0) {}
    ~SinglyCircularList() {
        while (count) deleteFirst();
    }
    void insertFirst(const T& value) {
        nodeSC<T>* newn = new nodeSC<T>(value);
        if (!head) {
            head = tail = newn;
            tail->next = head;
        } else {
            newn->next = head;
            head = newn;
            tail->next = head;
        }
        ++count;
    }
    void insertLast(const T& value) {
        nodeSC<T>* newn = new nodeSC<T>(value);
        if (!head) {
            head = tail = newn;
            tail->next = head;
        } else {
            tail->next = newn;
            tail = newn;
            tail->next = head;
        }
        ++count;
    }
    void deleteFirst() {
        if (!head) throw std::out_of_range("List is empty");
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            nodeSC<T>* temp = head;
            head = head->next;
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
            nodeSC<T>* temp = head;
            while (temp->next != tail) temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = head;
        }
        --count;
    }
    void insertAtPos(const T& value, size_t pos) {
        if (pos < 1 || pos > count + 1) throw std::out_of_range("Invalid position");
        if (pos == 1) insertFirst(value);
        else if (pos == count + 1) insertLast(value);
        else {
            nodeSC<T>* newn = new nodeSC<T>(value);
            nodeSC<T>* temp = head;
            for (size_t i = 1; i < pos - 1; ++i) temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
            ++count;
        }
    }
    void deleteAtPos(size_t pos) {
        if (pos < 1 || pos > count) throw std::out_of_range("Invalid position");
        if (pos == 1) deleteFirst();
        else if (pos == count) deleteLast();
        else {
            nodeSC<T>* temp = head;
            for (size_t i = 1; i < pos - 1; ++i) temp = temp->next;
            nodeSC<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            --count;
        }
    }
    void display(std::ostream& os = std::cout) const {
        if (!head) { os << "NULL\n"; return; }
        nodeSC<T>* temp = head;
        os << "<-";
        do {
            os << "| " << temp->data << " |->";
            temp = temp->next;
        } while (temp != head);
        os << "\n";
    }
    size_t size() const { return count; }
};

} // namespace gds
