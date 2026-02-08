#include "linkedlist2.h"

int main() {


    linkedList<string> A;
    A.loadFromFile("test.txt");
    A.slowSort();
    A.writeToFile("hello2.txt");

    linkedList<string> B;
    B.loadFromFile("test.txt");
    B.mergeSort();
    B.writeToFile("hello.txt");

    return 0;
}
