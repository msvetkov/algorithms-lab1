#ifndef ALGORITHMS_LAB1_HEAP_NODE_H
#define ALGORITHMS_LAB1_HEAP_NODE_H


class HeapNode {
    int data;
    HeapNode* right;
    HeapNode* left;
public:
    HeapNode(int value);

    /**
     * @return data
     */
    int get_data();

    /**
     * @param data of node
     * @brief set value into node
     */
    void set_data(int value);

    /**
     * @return right node
     */
    HeapNode* get_right();

    /**
     * @param node
     * @brief set rigth node of this node
     */
    void set_right(HeapNode* node);

    /**
     * @return left node
     */
    HeapNode* get_left();

    /**
    * @param node
    * @brief set left node of this node
    */
    void set_left(HeapNode* node);

    ~HeapNode();
};


#endif //ALGORITHMS_LAB1_HEAP_NODE_H
