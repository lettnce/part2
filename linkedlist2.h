#ifndef LINKEDLIST2_H
#define LINKEDLIST2_H

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

template <typename T>
class linkedList {
    private:
        class node {
        public:
            node *next;
            T data;

            node(T d);
        };

        node *head;
        node *tail;
        node *current;
    
    public:
        linkedList();

        ~linkedList();

        void print();

        int size();

        void push_back(T d);

        void pop_front();

        void split(linkedList<T> &l, linkedList<T> &r);

        void merge(linkedList<T> &l, linkedList<T> &r);

        void loadFromFile(string s);

        void writeToFile(string s);

        void slowSort();

        void mergeSort();

};

template <typename T>
linkedList<T>::node::node(T d) : data(d), next(nullptr) {}

template <typename T>
linkedList<T>::linkedList() : head(nullptr), current(nullptr) {}
// TODO: write destructor
template <typename T>
linkedList<T>::~linkedList() {
    current = head;
    while (current) {
        node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <typename T>
void linkedList<T>::print() {
    current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
int linkedList<T>::size() {
    int count(0);
    current = head;
    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

template <typename T>
void linkedList<T>::push_back(T d) {
    if (!head) {
        head = new node(d);
        tail = head;
    }
    else {
        tail->next = new node(d);
        tail = tail->next;
    }
}

template <typename T>
void linkedList<T>::pop_front() {
    current = head;
    if (!current->next) {
        head = nullptr;
    }
    else {
        node *temp = current;
        head = current->next;
        temp = nullptr;
    }
}
// TODO: ticket closed ✅
template <typename T>
void linkedList<T>::split(linkedList<T> &l, linkedList<T> &r) {
    int LLsize = size();

    int mid = LLsize/2;

    if (LLsize % 2 == 0) {
        for (int i(0); i < mid; i++) {
            l.push_back(head->data);
            pop_front();
        }

        for (int i(mid); i < LLsize; i++) {
            r.push_back(head->data);
            pop_front();
        }
    }
    else {
        // left LL
        for (int i(0); i < mid + 1; i++) {
            l.push_back(head->data);
            pop_front();
        }

        // right LL
        for (int i(mid + 1); i < LLsize; i++) {
            r.push_back(head->data);
            pop_front();
        }
    }

}

// TODO: write method
template <typename T>
void linkedList<T>::merge(linkedList<T> &l, linkedList<T> &r) {
    node *left = l.head;
    node *right = r.head;

    while (left && right) {
        if (left->data < right->data) {
            push_back(left->data);
            l.pop_front();
            left = l.head;
        }
        else {
            push_back(right->data);
            r.pop_front();
            right = r.head;
        }
        
    }

    while (left) {
        push_back(left->data);
        l.pop_front();
        left = l.head;
    }
    while (right) {
        push_back(right->data);
        r.pop_front();
        right = r.head;
    }
}

template <typename T>
void linkedList<T>::loadFromFile(string s) {
    fstream scanner;
    string word = "";
    scanner.open(s);

    while (scanner >> word) {
        push_back(word);
    }

    scanner.close();
}
// TODO: write method
template <typename T>
void linkedList<T>::writeToFile(string s) {
    ofstream scanner(s);

    if (!scanner.is_open()) {
        cerr << "ERROR! Could not open file!";
        return;
    }

    current = head;
    while (current) {
        scanner << current->data << "\n";
        current = current->next;
    }

    scanner.close();
}

template <typename T>
void linkedList<T>::slowSort() {

    for (node *i = head; i->next; i = i->next) {
        node *min = i;

        for (node *j = i->next; j; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }

        T temp = i->data;
        i->data = min->data;
        min->data = temp;
    }
}

template <typename T>
void linkedList<T>::mergeSort() {

    if (!head || !head->next) {
        return;
    }

    linkedList<T> l, r;

    split(l, r);
    l.mergeSort();
    r.mergeSort();
    merge(l, r);
}

#endif
