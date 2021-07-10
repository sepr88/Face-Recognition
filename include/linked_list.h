#ifndef FACE_RECOGNITION_LINKED_LIST_H
#define FACE_RECOGNITION_LINKED_LIST_H

template <class T>
class node{

public:
    node():next(nullptr){}
    node* next;
    T obj;

};

template <class T>
class linked_list {
private:
    node<T>* _head = nullptr;

public:
    linked_list(){}

    void push_back(T obj)
    {
        if(!_head)
        {
            _head = new node<T>();
            _head->obj = obj;
        }
        else
        {
            auto * n = new node<T>();
            n->obj = obj;
            n->next = _head;
            _head = n;
        }
    }

    bool contains(const T &value, bool(*f)(const T&, const T&))
    {
        node<T> *n = _head;

        while(n)
        {
            if((*f)(value,&(n->obj)))
            {
                return true;
            }

            n=n->next;
        }

        return false;
    }
};

#endif //FACE_RECOGNITION_LINKED_LIST_H
