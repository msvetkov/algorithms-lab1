#ifndef ALGORITHMS_LAB1_BFTITERATOR_H
#define ALGORITHMS_LAB1_BFTITERATOR_H


#include <stdexcept>
#include "Iterator.h"
#include "../queue/queue.h"

class BftIterator : public Iterator {
    Queue<HeapNode*> *queue;
public:
    BftIterator(HeapNode *start);
    HeapNode* next() override;
    bool has_next() override;
    ~BftIterator();
};


#endif //ALGORITHMS_LAB1_BFTITERATOR_H
