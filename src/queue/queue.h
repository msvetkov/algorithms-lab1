#ifndef ALGORITHMS_LAB1_LIST_H
#define ALGORITHMS_LAB1_LIST_H


#include <stdexcept>
#include "node.h"

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
public:
    Queue() {
        head = nullptr;
        size = 0;
    };

    /**
     * @brief Add data to queue
     * @param data
     */
    void enqueue(const T data) {
        auto *new_node = new Node<T>(data);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->set_next(new_node);
            tail = new_node;
        }

        size++;
    };

    /**
     * @brief Remove first item of queue
     * @return this item
     */
    T dequeue() {
        if (this->size == 0) {
            throw std::out_of_range("Inaccessible using of empty queue");
        }

        T data = head->get_data();

        if (size != 1) {
            head = head->get_next();
        } else {
            head = nullptr;
        }

        size--;
        return data;
    };

    /**
     * @return first item of queue
     */
    T peek() const {
        if (this->size == 0) {
            throw std::out_of_range("Inaccessible using of empty queue");
        }

        return this->head->get_data();
    };

    /**
     * @return size of queue
     */
    size_t get_size() const {
        return size;
    };

    ~Queue() {
        // deleting all elements of queue
        for (int i = 0; i < size; i++) {
            Node<T> *deleting = head;
            head = deleting->get_next();
            delete deleting;
        }
        size = 0;
    };
};


#endif //ALGORITHMS_LAB1_LIST_H
