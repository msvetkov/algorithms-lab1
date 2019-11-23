#include "BftIterator.h"

BftIterator::BftIterator(HeapNode *start) {
    queue = new Queue<HeapNode*>();
    if (start) {
        queue->enqueue(start);
    }
}

bool BftIterator::has_next() {
    return queue->get_size() != 0;
}

HeapNode* BftIterator::next() {
    if (!has_next()) {
        throw std::out_of_range("Hasn't next element");
    }

    HeapNode *next_node = queue->dequeue();
    if (next_node->get_left()) {
        queue->enqueue(next_node->get_left());
    }
    if (next_node->get_right()) {
        queue->enqueue(next_node->get_right());
    }

    return next_node;
}

BftIterator::~BftIterator() {
    delete queue;
}
