#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class linkedList {
private:
        class node {
        public:
            node *next;
            T data;

            node(T d) : data(d), next(nullptr) {}
        };

        node head;

public:
        // constructor
        linkedList() : head(nullptr) {}

        // destructor
        // ~singleLL() {
        // }

        // print each element in LL 
        void print() {
            node *current = head;
            while (current) {
                cout << current->data << " ";
            }
        }

        // add to end of LL
        void push_back(T d) {
            if (head == nullptr) {
                head = new node(d);
            }
            else {
                node *current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = new node(d);
            }
        }

        // takes 2 sorted lists and merges them, O(n)
        void merge(linkedList l, linkedList r) {}

        // open file, enter each word in ll element
        void loadFromFile(string w) {
            ifstream txtFile(w);
            string textIn;

            while (cin >> textIn) {
                push_back(textIn);
            }

            txtFile.close();
        }
    
        // write each item in ll to output file
        void writeToFile(string w) {}

};
#endif
