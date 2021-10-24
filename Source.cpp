#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*—делать реализацию очереди queue на шаблонах.
Ч enque
Ч T deque() (бросает исключение, если очередь пуста)
Ч size
Ч clear
Ч operator<< дл€ вывода*/

class MyException {
private:
    char message[256];
public:
    MyException(const char* text) {
        strcpy(message, text);
    }
    char* get() {
        return message;
    }
};



class Point {
private:
    int x;
    int y;
    int z;
public:
    Point(int cordx, int cordy, int cordz) {
        x = cordx;
        y = cordy;
        z = cordz;
    }
    friend std::ostream& operator<<(std::ostream& os, Point p) {
        os << "(" << p.x << "," << p.y << "," << p.z << ")";
        return os;
    }
};
/*value шаблонный (значени€ в очеред€х всех типов )
 умные указатели в динамической пам€ти
 приоритет интовое число */

 
template <typename T>
class Queue {
private:
    T* array;
    size_t size;
    size_t capacity;
public:
    Queue();
    ~Queue();
    Queue(Queue& q);
    void enque(T item);
    T deque();
    size_t getsize();
    void clear();
    Queue& operator=(Queue& q) {
        if (&q == this) return *this;
        free(array);
        size = q.size;
        capacity = q.capacity;
        array = (T*)malloc(capacity * sizeof(T));
        for (int i = 0; i < size; i++) array[i] = q.array[i];
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, Queue<T> q) {
        if (q.getsize() == 0) std::cout << "nothing";
        else for (int i = 0; i < q.getsize(); i++) os << q.get(i) << " ";
        return os;
    }

    T get(int index);
};

template <typename T>
Queue<T>::Queue() {
    array = nullptr;
    size = capacity = 0;
}

template <typename T>
Queue<T>::~Queue() {
    //if (array != nullptr) free(array);
}

template <typename T>
Queue<T>::Queue(Queue& q) {
    size = q.size;
    capacity = q.capacity;
    array = (T*)malloc(capacity * sizeof(T));
    for (int i = 0; i < size; i++)
        array[i] = q.array[i];
}

template <typename T>
void Queue<T>::enque(T item) {
    if (size == capacity) {
        if (capacity == 0) 
        capacity = 1;
        capacity *= 2;
        array = (T*)realloc(array, capacity * sizeof(T));
    }
    array[size] = item;
    size++;
}

template <typename T>
T Queue<T>::deque() {
    try {
        if (size == 0) throw MyException("Error: the queue is empty");
        T temp = array[0];
        for (int i = 0; i < size - 1; i++) array[i] = array[i + 1];
        size--;
        return temp;
    }
    catch (MyException& e) {
        std::cout << e.get() << "\n\n";
        exit(-1);
    }
}

template <typename T>
size_t Queue<T>::getsize() {
    return size;
}

template <typename T>
void Queue<T>::clear() {
    if (array != nullptr) {
        size = capacity = 0;
        free(array);
    }
}

template <typename T>
T Queue<T>::get(int index) {
    return array[index];
}