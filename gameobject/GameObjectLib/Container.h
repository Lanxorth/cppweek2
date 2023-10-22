#pragma once
#include <iostream>

template <typename T>

class container {
private:
    T* data;          // Pointer to the dynamically allocated array
    size_t size;      // Current number of elements in the container
    size_t capacity;  // Current capacity of the container

public:
    // Constructor
    container() : data(nullptr), size(0), capacity(0) {}

    // Destructor
    ~container() {
        delete[] data;
    }

    // Function to add an element to the end of the container
    void push_back(const T& value) {
        if (size == capacity) {
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }

            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }

        data[size++] = value;
    }

    // Function to get the element at a specific index
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Function to get the current size of the container
    size_t getSize() const {
        return size;
    }

    // Function to check if the container is empty
    bool empty() const {
        return size == 0;
    }

    // Function to get the current capacity of the container
    size_t getCapacity() const {
        return capacity;
    }
};