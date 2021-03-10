#pragma once

#include <iostream>
template <class T>
class list {
public:
    list();
    // ~list();
    list(const T elements[], int length);
    list(const list& lis);
    T& operator[](const int i);
    friend bool operator== (const list& left, const list& right);
    void setValue(T value) { this->data = value; }
    void add(T newElement);
    T GetData() { return data; }
    void deleteByValue(T& value);
    int GetLength() { return length; };
    void SetLength(int len) { length = len; }
private:
    T data;
    list* next;
    list* head;
    int length;
};

template <class T>
bool operator== (list<T>& left, list<T>& right) {
    return left.GetData() == right.GetData();
}

template <class T>
list<T>::list() {
    head = this;
    next = nullptr;
    length = 0;
}


template <class T>
list<T>::list(const T elements[], int length) {
    head = nullptr;
    this->data = elements[0];
    this->next = new list;
    head = this->next;
    for (int i = 1; i < length; i++) {
        head->data = elements[i];
        head->next = new list;
        head = head->next;
    }
    head->next = nullptr;
}

template <class T>
list<T>::list(const list& lis) {
    this->data = lis.data;
    this->next = lis.next;
    this->head = lis.head;
    this->length = lis.length;
    // delete lis.next;
    //  delete lis.head;

}

template <class T>
T& list<T>::operator[](const int i) {
    int j = 0;
    list* helper = this;
    while (helper->next != nullptr) {
        if (j == i) return helper->data;
        helper = helper->next;
        j++;
    };
    std::cout << "OUT OF RANGE" << std::endl;

};


template <class T>
void  list<T>::add(T newElement) {
    head->data = newElement;
    head->next = new list;
    head = head->next;
    head->next = nullptr;
    length++;
};


template <class T>
void  list<T>::deleteByValue(T& value) {
    if (this->data == value) {
        if (length <= 1) {
            head = this;
            next = nullptr;
            length--;
            return;
        }
        if (this->next == nullptr) {
            head = this;
            length--;
            return;
        }

        list* nex = this->next;
        if (this->next->next == nullptr) {
            this->data = nex->data;
        }
        else {
            this->next = this->next->next;
            std::cout << length << std::endl;
            this->data = this->next->data;
        }
        delete nex;

    }
    list* helper = this;
    list* helper2 = this->next;
    while (helper2 != nullptr) {
        if (helper2->data == value) {
            helper->next = helper2->next;
            delete helper2;
            break;
        }
        helper = helper->next;
        helper2 = helper2->next;
    }
    length--;
}