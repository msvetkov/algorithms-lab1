#ifndef ALGORITHMS_LAB1_NODE_H
#define ALGORITHMS_LAB1_NODE_H

template <class T>
class Node {
private:
    T data;
    Node *next;
public:
    explicit Node(T value) {
        data = value;
        next = nullptr;
    };

    /**
     * @return data
     */
    T get_data() const {
        return data;
    };

    /**
     * @return next pointer
     */
    Node<T>* get_next() const {
        return next;
    };

    /**
     * @param node next pointer
     */
    void set_next(Node<T> *node) {
        next = node;
    };

    ~Node() {
        next = nullptr;
    };
};


#endif //ALGORITHMS_LAB1_NODE_H
