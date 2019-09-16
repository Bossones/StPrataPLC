#ifndef QUEUETP_HPP__
#define QUEUETP_HPP__

#include <iostream>
#include <cstdlib>

//2 templates. Common template for some data in stack
//end specialization for pointers for some data in stack

template <typename T>
class stack {
private:
    struct Node {
        Node * next;
        Node * prev;
        T data;
    };
    Node * cur;
public:
    stack() : cur(nullptr) {}
    ~stack();

    bool push(const T & elem);
    bool pop(T & elem);
    bool delCur();
    T & getData();
};

template <typename T>
stack<T>::~stack() {
    if (cur != nullptr) {
        if (cur->prev == nullptr)
            delete cur;
        else {
            Node * temp = cur->prev;
            while(temp != nullptr) {
                delete cur;
                cur = temp;
                temp = cur->prev;
            }
        }
    }
}

template <typename T>
bool stack<T>::push(const T & elem) {
    if(cur == nullptr) {
        cur = new Node;
        cur->next = nullptr;
        cur->data = elem;
        cur->prev = nullptr;
    }
    else {
        Node * temp = cur;
        cur->next = new Node;
        cur = cur->next;
        cur->prev = temp;
        cur->next = nullptr;
        cur->data = elem;
    }
    return true;
}

template <typename T>
bool stack<T>::pop(T & elem) {
    if(cur == nullptr)
        return false;
    else {
        if (cur->prev != nullptr) {
            Node * temp = cur->prev;
            elem = cur->data;
            delete cur;
            cur = temp;
            cur->next = nullptr;
        }
        else {
            elem = cur->data;
            delete cur;
            cur = nullptr;
        }
    }
    return true;
}

template <typename T>
bool stack<T>::delCur() {
    if (cur == nullptr)
        return false;
    else {
        if (cur->prev != nullptr) {
            Node * temp = cur->prev;
            delete cur;
            cur = temp;
            cur->next = nullptr;
        }
        else {
            delete cur;
            cur = nullptr;
        }
    }
    return true;
}

template<typename T>
T & stack<T>::getData() {
    if(cur == nullptr) {
        std::cout << "No data in current Node. Programm will be terminated." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return cur->data;
}

template <typename T>
class stack<T*> {
private:
    struct Node {
        Node * next;
        Node * prev;
        T * data;
    };
    Node * cur;
public:
    stack() : cur(nullptr) {}
    ~stack();

    bool push(const T * elem);
    bool pop(T * elem);
    bool delCur();
    T * getData();
};

template <typename T>
stack<T*>::~stack() {
    if (cur != nullptr) {
        if (cur->prev == nullptr) {
            delete cur->data;
            delete cur;
        }
        else {
            Node * temp = cur->prev;
            while(temp != nullptr) {
                delete cur->data;
                delete cur;
                cur = temp;
                temp = cur->prev;
            }
        }
    }
}

template <typename T>
bool stack<T*>::push(const T * elem) {
    if (cur == nullptr) {
        cur = new Node;
        cur->prev = nullptr;
        cur->next = nullptr;
        cur->data = new T;
        *cur->data = *elem;
    }
    else {
        Node * temp = cur;
        cur->next = new Node;
        cur = cur->next;
        cur->prev = temp;
        cur->data = new T;
        *cur->data = *elem;
    }
    return true;
}

template <typename T>
bool stack<T*>::pop(T * elem) {
    if (cur == nullptr)
        return false;
    else {
        if (cur->prev == nullptr) {
            *elem = *(cur->data);
            delete cur->data;
            delete cur;
            cur = nullptr;
        }
        else {
            Node * temp = cur->prev;
            *elem = *(cur->data);
            delete cur->data;
            delete cur;
            cur = temp;
            cur->next = nullptr;
        }
    }
    return true;
}

template <typename T>
bool stack<T*>::delCur() {
    if (cur == nullptr)
        return false;
    else {
        if (cur->prev == nullptr) {
            delete cur->data;
            delete cur;
            cur = nullptr;
        }
        else {
            Node * temp = cur->prev;
            delete cur->data;
            delete cur;
            cur = temp;
            cur->next = nullptr;
        }
    }
    return true;
}

template <typename T>
T * stack<T*>::getData() {
    if(cur == nullptr) {
        std::cout << "No data in current Node. Programm will be terminated." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return cur->data;
}
#endif