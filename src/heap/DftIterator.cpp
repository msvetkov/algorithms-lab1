#include "DftIterator.h"

DftIterator::DftIterator(HeapNode *start) {
    queue = new Queue<HeapNode*>;
    dft(start);
}

void DftIterator::dft(HeapNode *start) {
    if (start) {
        queue->enqueue(start);
        dft(start->get_left());
        dft(start->get_right());
    }
}

bool DftIterator::has_next() {
    return queue->get_size() != 0;
}

HeapNode* DftIterator::next() {
    if (!has_next()) {
        throw std::out_of_range("Hasn't next element");
    }

    return queue->dequeue();
}

DftIterator::~DftIterator() {
    delete queue;
}

