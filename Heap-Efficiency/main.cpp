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

#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"
#include "MinimumQueue.h"
#include <cstdlib>

int MAX = 50;

int main() {
    // insert code here...
    List<int> list;
    MinimumQueue<int> queue(MAX);
    std::fstream outputFile;
    outputFile.open("output.out", std::ios::out | std::ios::trunc);
    double eff = 0,
    listTotal = 0,
    queueTotal = 0;
    
    std::srand(std::time(NULL));
    
    
    for (int i = 0; i < MAX; i++) {
        int random = std::rand() % 1000 + 1;
        try {
            queue.enqueue(random);
            list.enqueue(random);
        } catch (FullQueue) {
            std::cout << "Heap Queue is full, cannot add!" << std::endl;
            outputFile << "Heap Queue is full, cannot add!" << std::endl;
        }
        
        
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Queueing Random Number: " << random << std::endl;
        std::cout << "\tMinimum Priority Heap in " << queue.getCount();
        std::cout << " moves" << std::endl;
        std::cout << "\tLinear Linked List in " << list.getCount();
        std::cout << " move(s)" << std::endl;
        outputFile << "---------------------------------------" << std::endl;
        outputFile << "Queueing Random Number: " << random << std::endl;
        outputFile << "\tMinimum Priority Heap in " << queue.getCount();
        outputFile << " moves" << std::endl;
        outputFile << "\tLinear Linked List in " << list.getCount();
        outputFile << " move(s)" << std::endl;
    }
    std::cout << "---------------------------------------\n\n" << std::endl;
    outputFile << "---------------------------------------\n\n" << std::endl;
    
    for (int i = 0; i < MAX; i++) {
        int queueOut = 0;
        int listOut = 0;
        try {
            queue.dequeue(queueOut);
            list.dequeue(listOut);
        } catch (EmptyQueue) {
            std::cout << "Heap is empty, can not dequeue!" << std::endl;
            outputFile << "Heap is empty, can not dequeue!" << std::endl;
        } catch (EmptyList) {
            std::cout << "List is empty, can not dequeue!" << std::endl;
            outputFile << "List is empty, can not dequeue!" << std::endl;
        }
        
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Dequeueing from Heap: Number " << queueOut << std::endl;
        std::cout << "\tHeap moves: " << queue.getCount() << std::endl;
        std::cout << "Dequeueing from List: Number " << listOut << std::endl;
        std::cout << "\tList moves: " << list.getCount() << std::endl;
        outputFile << "---------------------------------------" << std::endl;
        outputFile << "Dequeueing from Heap: Number " << queueOut << std::endl;
        outputFile << "\tHeap moves: " << queue.getCount() << std::endl;
        outputFile << "Dequeueing from List: Number " << listOut << std::endl;
        outputFile << "\tList moves: " << list.getCount() << std::endl;
    }
    listTotal = double(list.getTotal());
    queueTotal = double(queue.getTotal());
    eff = ((listTotal - queueTotal) / queueTotal) * 100;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Total Moves..." << std::endl;
    std::cout << "\tHeap: " << queue.getTotal() << std::endl;
    std::cout << "\tList: " << list.getTotal() << std::endl << std::endl;
    std::cout << std::setprecision(3) << "Heap efficiency: " << eff << "%\n";
    outputFile << "---------------------------------------" << std::endl;
    outputFile << "Total Moves..." << std::endl;
    outputFile << "\tHeap: " << queue.getTotal() << std::endl;
    outputFile << "\tList: " << list.getTotal() << std::endl << std::endl;
    outputFile << std::setprecision(3) << "Heap efficiency: " << eff << "%\n";
    
    outputFile.close();
    return 0;
}
