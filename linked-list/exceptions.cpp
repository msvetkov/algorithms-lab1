#ifndef ALGORITHMS_LAB1_EXCEPTIONS_CPP
#define ALGORITHMS_LAB1_EXCEPTIONS_CPP


#include <exception>

struct empty_list_get_error : public exception {
    const char *what() const throw () {
        return "Cannot get item from empty list";
    }
};

struct empty_list_remove_error : public exception {
    const char *what() const throw () {
        return "Cannot remove item from empty list";
    }
};

struct index_outside_list_error : public exception {
    const char *what() const throw () {
        return "This index is outside the list";
    }
};


#endif