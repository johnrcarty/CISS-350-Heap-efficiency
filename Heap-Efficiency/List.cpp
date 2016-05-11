//
//  List.cpp
//  Week7
//
//  Created by John Carty on 5/7/16.
//  Copyright © 2016 John Carty. All rights reserved.
//

#include "List.h"


List::List() {
    head = nullptr;
    length = 0;
    count = 0;
    totalMoves = 0;
}

void List::enqueue(int newValue) {
    Node *newNode;  // Pointer to node being inserted.
    Node *predLoc;  // Trailing pointer.
    Node *nodePtr; // Traveling pointer.
    bool moreToSearch;
    count = 1;
    nodePtr = head;
    predLoc = NULL;
    moreToSearch = (nodePtr != nullptr);
    // Find insertion point.
    while (moreToSearch) {
        if (nodePtr->value < newValue) {
            predLoc = nodePtr;
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
    if (predLoc == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = nodePtr;
        predLoc->next = newNode;
    }
    length++;
    totalMoves+=count;
}

void List::dequeue(int &smallest) {
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

int List::getCount() {
    return count;
}

int List::getTotal() {
    return totalMoves;
}

void List::display() {
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