//
// Created by sebas on 09.07.2021.
//

#ifndef FACE_RECOGNITION_RINGBUFFER_H
#define FACE_RECOGNITION_RINGBUFFER_H

template <class T>
class ringbuffer{
private:
    int _capacity, _head;
    T *_arr;

public:
    ringbuffer(int capacity):_capacity(capacity),_arr(new T[capacity]), _head(0){}
    int capacity()const{return _capacity;}
    T operator[](int idx){return _arr[idx];}

    void push_back(const T &obj)
    {
        _arr[_head++]=obj;

        if(_head >= _capacity)
        {
            _head=0;
        }

    }

    void clear()
    {
        _head = 0;
        _arr = new T[_capacity];
    }

};


#endif //FACE_RECOGNITION_RINGBUFFER_H
