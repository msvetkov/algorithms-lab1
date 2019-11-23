#ifndef ALGORITHMS_LAB1_HEAP_H
#define ALGORITHMS_LAB1_HEAP_H

#include "heap_node.h"
#include "Iterator.h"
#include "BftIterator.h"
#include "DftIterator.h"
#include <stdexcept>
#include <iostream>
#include <math.h>

class Heap {
    HeapNode* root;
    size_t size;
    void swapValues(HeapNode *node1, HeapNode *node2);
    void recursivePrint(HeapNode* start, int level, char symbol) const;
public:
    Heap();
    bool contains(int data);
    void insert(int);
    void remove(int data);
    Iterator* create_dft_iterator();
    Iterator* create_bft_iterator();
    void print() const;
    ~Heap();
};


#endif //ALGORITHMS_LAB1_HEAP_H
