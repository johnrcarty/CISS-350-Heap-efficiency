/******************************************************************************
 Week 7
 Heaps
 CISS-350
 
 <description>  MinimumQueue class provides the ability to organize the Heap
                stuct with the smallest key in the first spot. Counts the steps
                taken for each enqueue and dequeue operation.
 
 <author> John Carty
 <date> 8 - May - 2016
 <revision> NONE
 
 ******************************************************************************/

#ifndef MinimumQueue_h
#define MinimumQueue_h

#include <stdio.h>
#include "Heap.h"

class FullQueue{};
class EmptyQueue{};

template <class T>
class MinimumQueue {
private:
    int length;
    HeapType<T> items;
    int maxItems;
    int count;
    int totalMoves;
    
public:
    MinimumQueue(int);
    ~MinimumQueue();
    
    bool isEmpty();
    bool isFull();
    void enqueue(T newItem);
    void dequeue(T &item);
    int getCount();
    int getTotal();
    void setTotal();
};

template <class T>
MinimumQueue<T>::MinimumQueue(int max) {
    maxItems = max;
    items.elements = new T[max];
    length = 0;
    totalMoves = 0;
}

template <class T>
MinimumQueue<T>::~MinimumQueue() {
    delete [] items.elements;
}

//check if the Heap is full
template <class T>
bool MinimumQueue<T>::isFull() {
    return length == maxItems;
}

//check if the heap is empty
template <class T>
bool MinimumQueue<T>::isEmpty() {
    return length == 0;
}

//add value to the heap
template <class T>
void MinimumQueue<T>::enqueue(T newItem) {
    if (length == maxItems) {
        throw FullQueue();
    } else {
        count = 1;
        length++;
        items.elements[length-1] = newItem;
        items.reheapUp(0, length-1, count);
        totalMoves+=count;
    }
}

//remove smallest value from the heap
template <class T>
void MinimumQueue<T>::dequeue(T &item) {
    if (length == 0) {
        throw EmptyQueue();
    } else {
        count = 1;
        item = items.elements[0];
        items.elements[0] = items.elements[length-1];
        length--;
        items.reheapDown(0, length-1, count);
        totalMoves+=count;
    }
}

//get the nubmer of moves made in either enqueue or dequeue
template <class T>
int MinimumQueue<T>::getCount() {
    return count;
}

//get the total moves made by enqueue and dequeue
template <class T>
int MinimumQueue<T>::getTotal(){
    return totalMoves;
}
#endif /* MinimumQueue_h */
