#include "heap.h"

Heap::Heap() {
    root = nullptr;
    size = 0;
}

void Heap::swapValues(HeapNode *node1, HeapNode *node2) {
    int temp = node1->get_data();
    node1->set_data(node2->get_data());
    node2->set_data(temp);
}

bool Heap::contains(const int data) {
    Iterator* iterator = create_bft_iterator();
    while (iterator->has_next()) {
        if (iterator->next()->get_data() == data) {
            return true;
        }
    }

    return false;
}

void Heap::insert(const int data) {
    auto *node = new HeapNode(data);
    size++;

    if (size == 1) {
        root = node;
        return;
    }

    int height = (int) log2(size);
    int last_level_nodes_number = pow(2, height); // number of nodes at level if it would be full
    int position = last_level_nodes_number + 1 + size - pow(2, height + 1); // serial number of the new node at the level
    HeapNode *current = root;

    for (int i = 0; i < height - 1; i++) {
        if (node->get_data() > current->get_data()) {
            swapValues(node, current);
        }

        if (position > last_level_nodes_number / 2) {
            current = current->get_right();
            position = last_level_nodes_number - position;
        } else {
            current = current->get_left();
        }

        last_level_nodes_number = last_level_nodes_number / 2;
    }

    if (!current->get_left()) {
        current->set_left(node);
        swapValues(current, current->get_left());
    } else {
        current->set_right(node);
        swapValues(current, current->get_right());
    }
}

void Heap::remove(const int data) {
    HeapNode *deleting_node = nullptr;

    Iterator* iterator = create_bft_iterator();
    while (iterator->has_next()) {
        HeapNode *curr = iterator->next();
        if (curr->get_data() == data) {
            deleting_node = curr;
            break;
        }
    }

    if (!deleting_node) {
        return;
    }

    HeapNode *last_node = root;
    int height = (int) log2(size);
    int last_level_nodes_number = pow(2, height); // number of nodes at level if it would be full
    int position = last_level_nodes_number + 1 + size - pow(2, height + 1); // serial number of the new node at the level

    for (int i = 0; i < height - 1; i++) {
        if (position > last_level_nodes_number / 2) {
            last_node = last_node->get_right();
            position = last_level_nodes_number - position;
        } else {
            last_node = last_node->get_left();
        }

        last_level_nodes_number = last_level_nodes_number / 2;
    }

    if (last_node->get_right()) {
        deleting_node->set_data(last_node->get_right()->get_data());
        delete last_node->get_right();
        last_node->set_right(nullptr);
    } else {
        deleting_node->set_data(last_node->get_left()->get_data());
        delete last_node->get_left();
        last_node->set_left(nullptr);
    }

    while (deleting_node->get_left()) {
        HeapNode *biggest_children = deleting_node->get_left();
        if (deleting_node->get_right() && deleting_node->get_right()->get_data() > biggest_children->get_data()) {
            biggest_children = deleting_node->get_right();
        }

        if (biggest_children->get_data() > deleting_node->get_data()) {
            swapValues(deleting_node, biggest_children);
            deleting_node = biggest_children;
        } else {
            break;
        }
    }

    size--;
}

Iterator* Heap::create_bft_iterator() {
    return new BftIterator(root);
}

Iterator* Heap::create_dft_iterator() {
    return new DftIterator(root);
}

void Heap::print() const {
    recursivePrint(root, 0, '.');
}

void Heap::recursivePrint(HeapNode *start, const int level, const char symbol) const {
    if (!start) {
        return;
    }

    for (int i = 0; i < level; i++) {
        std::cout << "  |";
    }

    if (level != 0) {
        std::cout << "--" << symbol << ": ";
    } else {
        std::cout << "  ";
    }

    std::cout << start->get_data() << "\n";
    recursivePrint(start->get_left(), level + 1, 'L');
    recursivePrint(start->get_right(), level + 1, 'R');
}

Heap::~Heap() {
    Iterator* iterator = create_bft_iterator();
    while (iterator->has_next()) {
        delete iterator->next();
    }
    delete root;
}