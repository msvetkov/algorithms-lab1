#ifndef ALGORITHMS_LAB1_LIST_H
#define ALGORITHMS_LAB1_LIST_H


#include <iostream>
#include "node.h"
#include "exceptions.cpp"

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

    /*
     * @brief For isolation logic of common logic of "insert" functions. Check the presence of elements and run passed function.
     * @param data
     * @param f function for insert
     */
    void push(int data, void(*f)(*Node));

    /**
     * @param index
     * @return {Node} node of list by index
     */
    Node* get_node(int index) const;
public:
    LinkedList();

    /**
     * @brief Add data at list tail
     * @param data
     */
    void push_back(const int data);

    /**
     * @brief Add data at list head
     * @param data
     */
    void push_front(const int data);

    /**
     * @brief Remove item from list tail
     */
    void pop_back();

    /**
     * @brief Remove item from list head
     */
    void pop_front();

    /**
     * @brief Insert data to list by index
     * @param data
     * @param index
     */
    void insert(const int data, const int index);

    /**
     * @brief Insert another list to our starts from index
     * @param list
     * @param index
     */
    void insert(LinkedList list, const int index);

    /**
     * @param index
     * @return data by index
     */
    int at(const int index) const;

    /**
     * @brief Remove item by index
     * @param index
     */
    void remove(const int index);

    /**
     * @return size of list
     */
    int get_size() const;

    /**
     * @brief Print list at format [1, 2, 3, ...] using <iostream> cout
     */
    void print_to_console() const;

    /**
     * @brief clear all list
     */
    void clear();

    /**
     * @brief replace data by index
     * @param data
     * @param index
     */
    void set(const int data, const int index);

    /**
     *
     * @return is list empty
     */
    bool is_empty() const;

    ~LinkedList();
};


#endif //ALGORITHMS_LAB1_LIST_H
