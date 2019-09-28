#ifndef ALGORITHMS_LAB1_NODE_H
#define ALGORITHMS_LAB1_NODE_H


class Node {
private:
    int data;
    Node *next;
    Node *prev;
public:
    Node(const int data);

    /**
     * @return data
     */
    int get_data() const;

    /**
     * @param data
     */
    void set_data(const int data);

    /**
     * @return next pointer
     */
    Node* get_next() const;

    /**
     * @param node next pointer
     */
    void set_next(Node *node);

    /**
     * @return previous pointer
     */
    Node* get_prev();

    /**
     * @param node previous pointer
     */
    void set_prev(Node *node) const;

    ~Node();
};


#endif //ALGORITHMS_LAB1_NODE_H
