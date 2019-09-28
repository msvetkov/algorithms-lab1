#include "node.h"

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

int Node::get_data() const{
    return this->data;
}

void Node::set_data(const int data) {
    this->data = data;
}

Node* Node::get_next() const {
    return this->next;
}

void Node::set_next(Node *node) {
    this->next = node;
}

Node* Node::get_prev() const {
    return this->prev;
}

void Node::set_prev(Node *node) {
    this->prev = node;
}
Node::~Node() { }
