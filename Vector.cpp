#include <iostream>
template<typename T>
struct  vector {
    int _size;
    int capacity;
    T* data;
    vector() {
        _size=0;
        capacity=1;
        data=new T[capacity];
    }
    ~vector() {
        delete[] data;
        data=nullptr;
    }
    void resize(int n) {
        int new_capacity=capacity;
        while(new_capacity<n) new_capacity=new_capacity*2; {}
        while ( new_capacity>=2 && new_capacity/2>=n) new_capacity=new_capacity/2; {}
        T* new_data=new T[new_capacity];;
        for(int i=0;i<_size;i++) {
            new_data[i]=data[i];
        }
        capacity=new_capacity;
        delete[] data;
        data=new_data;
        new_data=nullptr;
    }
    void push_back(T item) {
        if (_size==capacity) {
            resize(capacity*2);
        }
        data[_size++]=item;
    }
    void pop_back() {
        if (_size==0) {
            std::cout<<"pop_back() called on empty vector"<<std::endl;
        }
        else {
            --_size;
            if (_size>0 and _size<=capacity/4) {
                resize(capacity/2);
            }
        }
    }
    int size() {return _size;}
    int capacidad() {return capacity;}
    T& operator[](int i) {return data[i];}
    void print(vector<T> &v) {
        for (int i=0;i<v.size();i++) {
            std::cout<<v[i]<<" ";
        }
        std::cout<<std::endl;
    }


};



int main() {
    return 0;
}