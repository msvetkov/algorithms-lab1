#include "list.h"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

void LinkedList::push(const int data, void (*)(*Node) f) {
    Node *new_node = new Node(data);

    if (this->head == nullptr) {
        this->head = new_node;
        this->tail = this->head;
    } else {
        (*f)(new_node);
    }

    this->size = this->size + 1;
}

Node* LinkedList::get_node(const int index) const {
    Node *result = this->head;
    for (int i = 0; i < index, i++) {
        result = result->get_next();
    }

    return result;
}

void LinkedList::push_back(int data) {
    this->push(data, [](Node *new_node) {
        this->tail->set_next(new_node);
        new_node->set_prev(this->tail);
        this->tail = new_node;
    });
}

void LinkedList::push_front(const int data) {
    this->push(data, [](Node new_node) {
        this->head->set_prev(new_node);
        new_node->set_next(this->head);
        this->head = new_node;
    });
}

void LinkedList::pop_back() {
    if (this->size == 0) {
        throw empty_list_get_error;
    }

    this->tail = this->tail->get_prev();
    this->tail->set_next(nullptr);
    this->size = this->size - 1;
}

void LinkedList::pop_front() {
    if (this->size == 0) {
        throw empty_list_get_error;
    }

    this->head = this->head->get_next();
    this->head->set_prev(nullptr);
    this->size = this->size - 1;
}

void LinkedList::insert(const int data, const int index) {
    if (index < 0 || index > this->size) {
        throw index_outside_list_error;
    }

    // check can we use push methods
    if (index == 0) {
        return this->push_front(data);
    } else if (index == this->size) {
        return this->push_back(data)
    }

    Node *current = get_node(index);

    this->push(data, [](Node *new_node) {
        new_node->set_next(current);
        new_node->set_prev(current->get_prev());
        current->get_prev()->set_next(new_node);
    });
}

/**
 * Insert another list to our starts from index
 * @param list
 * @param index
 */
void LinkedList::insert(LinkedList list, const int index) {
    if (index < 0 || index > this->size) {
        throw index_outside_list_error;
    }

    if (list.get_size() == 0) {
        return;
    }

    Node *current_sublist = list.head;

    // if we must add items to end of list just using push_back
    if (index == this->get_size()) {
        for (int i = 0; i < list.get_size(); i++) {
            this->push_back(current_sublist->get_data());
            current_sublist = current_sublist->set_next();
        }
        return;
    }

    // handle if we must replace head
    if (index == 0) {
        this->push_front(current_sublist->get_data());
        current_sublist = current_sublist->set_next();
        list.pop_front();
    }

    // by default insert items
    Node *current_self = get_node(index);
    for (int i = 0; i < list.get_size(); i++) {
        this->push(current_sublist->get_data(), [](Node *new_node) {
            new_node->set_next(current_self);
            new_node->set_prev(current_self->get_prev());
            current_self->get_prev()->set_next(new_node);
        });
    }
}

int LinkedList::at(const int index) const {
    if (index < 0 || index > this->size) {
        throw index_outside_list_error;
    }

    Node *current = get_node(index);

    return current->get_data();
}

void LinkedList::remove(const int index) {
    if (index < 0 || index > this->size) {
        throw index_outside_list_error;
    } else if (this->size == 0) {
        throw empty_list_remove_error;
    }

    // check can we use pop methods
    if (index == 0) {
        return this->pop_front()
    } else if (index == this->size) {
        return this->pop_back();
    }

    Node *current = get_node(index);
    current->get_prev()->set_next(current->get_next());
    current->get_next()->set_prev(current->get_prev());
}

int LinkedList::get_size() const {
    return this->size;
}

void LinkedList::print_to_console() const {
    Node *current = this->head;
    std::cout << "[";
    for (int i = 0; i < this->size, i++) {
        std::cout << current->get_data();
        if (current->get_next() != nullptr) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

void LinkedList::clear() {
    for (int i = 0; i < this->size, i++) {
        this->pop_back();
    }
    this->size = 0;
}

bool LinkedList::is_empty() const {
    return this->size == 0;
}

LinkedList::~LinkedList() { }
