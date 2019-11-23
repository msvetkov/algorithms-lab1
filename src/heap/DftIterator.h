#ifndef ALGORITHMS_LAB1_DFTITERATOR_H
#define ALGORITHMS_LAB1_DFTITERATOR_H


#include "Iterator.h"
#include "heap_node.h"
#include "../queue/queue.h"

class DftIterator : public Iterator {
    Queue<HeapNode*> *queue;
public:
    DftIterator(HeapNode *start);
    void dft(HeapNode *start);
    HeapNode* next() override;
    bool has_next() override;
    ~DftIterator();
};


#endif //ALGORITHMS_LAB1_DFTITERATOR_H
