#ifndef ALGORITHMS_LAB1_ITERATOR_H
#define ALGORITHMS_LAB1_ITERATOR_H

#include <stdexcept>
#include "heap_node.h"

class Iterator {
public:
    virtual HeapNode* next() = 0;
    virtual bool has_next() = 0;
};


#endif //ALGORITHMS_LAB1_ITERATOR_H
