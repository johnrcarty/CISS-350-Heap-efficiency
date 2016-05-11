/******************************************************************************
 Week 7
 Heaps
 CISS-350
 
 <description>  This program will compare the effieciency of Heaps compared to
 a Linear Linked List.
 
 <author> John Carty
 <date> 8 - May - 2016
 <revision> NONE
 
 ******************************************************************************/

#ifndef List_h
#define List_h

#include <stdio.h>
#include <iostream>
class EmptyList{};

template <class T>
class List {
private:
    struct Node {
        T value;
        Node *next = nullptr;
    };
    
    Node *head;
    int length;
    int count;
    int totalMoves;
    
public:
    List();
    void enqueue(T newValue);
    void dequeue(T &smallest);
    void display();
    int getCount();
    int getTotal();
};

//default constructor
template <class T>
List<T>::List() {
    head = nullptr;
    length = 0;
    count = 0;
    totalMoves = 0;
}

template <class T>
void List<T>::enqueue(T newValue) {
    Node *newNode;  // Pointer to node being inserted.
    Node *prev;  // pointer to previous location
    Node *nodePtr;
    bool moreToSearch;
    count = 1;
    nodePtr = head;
    prev = nullptr;
    moreToSearch = (nodePtr != nullptr);
    // Find insertion point.
    while (moreToSearch) {
        if (nodePtr->value < newValue) {
            prev = nodePtr;
            nodePtr = nodePtr->next;
            moreToSearch = (nodePtr != nullptr);
            count+=1;
        } else {
            moreToSearch = false;
        }
    }
    // Prepare node for insertion.
    newNode = new Node;
    newNode->value = newValue;
    // Insert node into list.
    if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = nodePtr;
        prev->next = newNode;
    }
    length++;
    totalMoves+=count;
}

//output the first node and shift the list down
template <class T>
void List<T>::dequeue(T &smallest) {
    if (!head) {
        throw EmptyList();
    } else {
        count = 1;
        totalMoves += count;
        length--;
        Node *nodePtr = head;
        smallest = nodePtr->value;
        head = head->next;
        delete nodePtr; 
    }
}

//output count of steps for enqueue or dequeue
template <class T>
int List<T>::getCount() {
    return count;
}

//output total moves made by both enqueue and dequeue
template <class T>
int List<T>::getTotal() {
    return totalMoves;
}

//output the list
template <class T>
void List<T>::display() {
    if (!head) {
        std::cout << "List is empty!" << std::endl;
    } else {
        Node *nodePtr = head;
        while (nodePtr) {
            std::cout << nodePtr->value << std::endl;
            nodePtr = nodePtr->next;
        }
    }
}

#endif /* List_hpp */
