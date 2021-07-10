//
// Created by sebas on 09.07.2021.
//

#ifndef FACE_RECOGNITION_MYVECTOR_H
#define FACE_RECOGNITION_MYVECTOR_H

template <class T>
class myvector {
private:
    int _capacity, _size;
    T *_arr;

public:
    myvector():_size(0), _capacity(1),_arr(new T[1]){}

    int capacity() const {return this->_capacity;}
    int size() const {return this->_size;}
    int empty() const {return _size==0;}
    T operator[](int idx){ return _arr[idx];}

    void push_back(const T &obj)
    {
        if(_size<_capacity)
        {
            _arr[_size++] = obj;
        }else
        {
            auto capacity = _capacity *2;
            T *h = new T[capacity];

            for (int i = 0; i < _capacity; ++i) {
                h[i]=_arr[i];
            }

            _arr = h;
            _capacity=capacity;

            push_back(obj);
        }
    }


};


#endif //FACE_RECOGNITION_MYVECTOR_H
