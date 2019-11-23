#include "heap_node.h"

HeapNode::HeapNode(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

void HeapNode::set_data(int value) {
    data = value;
}

int HeapNode::get_data() {
    return data;
}

void HeapNode::set_right(HeapNode *node) {
    right = node;
}

HeapNode* HeapNode::get_right() {
    return  right;
}

void HeapNode::set_left(HeapNode *node) {
    left = node;
}

HeapNode* HeapNode::get_left() {
    return  left;
}

HeapNode::~HeapNode() {
    left = nullptr;
    right = nullptr;
}
