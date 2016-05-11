/******************************************************************************
 Week 7
 Heaps
 CISS-350
 
 <description>  Heap struct to be used in the MinimumQueue class. Creates an
                array that is dynamically allocated to the max size, then 
                provides the needed methods to enqueue and dequeue.
 
 <author> John Carty
 <date> 8 - May - 2016
 <revision> NONE
 
 ******************************************************************************/

#ifndef Heap_h
#define Heap_h
template <class T>
void swap(T &one, T &two);

template <class T>
struct HeapType {
    
    void reheapDown(int, int, int &);
    void reheapUp(int, int, int &);
    T *elements;   // Array to be allocated dynamically
};

template <class T>
void swap(T &one, T &two) {
    T temp;
    temp = one;
    one = two;
    two = temp;
}

template<class T>
void HeapType<T>::reheapDown(int root, int bottom, int &count) {
    // Balance the heap after a dequeue
    int minChild = 0;
    int rightChild = 0;
    int leftChild = 0;
    leftChild = root*2+1;
    rightChild = root*2+2;
    if (leftChild <= bottom) {
        if (leftChild == bottom) {
            minChild = leftChild;
        } else {
            if (elements[leftChild] >= elements[rightChild]) {
                minChild = rightChild;
            } else {
                minChild = leftChild;
            }
        }
        if (elements[root] > elements[minChild]) {
            swap(elements[root], elements[minChild]);
            reheapDown(minChild, bottom, count+=1);
        }
    }
}


template<class ItemType>
void HeapType<ItemType>::reheapUp(int root, int bottom, int &count) {
    // balance the heap after an enqueue
    int parent = 0;
    if (bottom > root) {
        parent = (bottom-1) / 2;
        if (elements[parent] > elements[bottom]) {
            swap(elements[parent], elements[bottom]);
            reheapUp(root, parent, count+=1);
        }
    }
}


#endif /* Heap_h */
