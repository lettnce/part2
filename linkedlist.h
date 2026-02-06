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
            int data;

            node(T d);
        };

        node *head;

public:
        // constructor
        singleLL();

        // // destructor
        // ~singleLL();

        // print each element in LL 
        void print();

        // add to end of LL
        T push_back(T d);

        // takes 2 sorted lists and merges them, O(n)
        void merge(node l, node r);

        // open file, enter each word in ll element
        void loadFromFile(string w);
    
        // write each item in ll to output file
        void writeToFile(string w);

};


#endif 
