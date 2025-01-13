#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdexcept> //exception handling
#include<fstream>  // for input/output file
#include <string>
#include <algorithm> // For std::copy
template <typename T>
class Array
{
protected:
    size_t Size;
    size_t capacity;
    T* arr;

    // Resize function
    void resize(size_t newCapacity) {
        T* newarr = new T[newCapacity];
        std::copy(arr, arr + Size, newarr);
        delete[] arr;
        arr = newarr;
        capacity = newCapacity;
    }
public:
    Array(size_t cap = 2) :capacity(cap), Size(0) {
        arr = new T[capacity];
    }
    ~Array() {
        delete[] arr;
        arr = nullptr;
    }
    void Append(const T& p) {
        if (Size >= capacity) {
            size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
            resize(newCapacity);
        }
        arr[Size++] = p;
    }
    void Delete(size_t index) {
        if (index >= Size) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        for (size_t i = index; i < Size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        Size--;
        //shrink
        if (Size <= capacity / 4) {
            resize(capacity / 2);
        }
    }
    void Reverse() {
        size_t Start = 0, End = Size - 1;
        while (Start < End) {
            T temp = arr[Start];
            arr[Start] = arr[End];
            arr[End] = temp;
            Start++;
            End--;
        }
    }
    void searchByLast(std::string last) {
        bool exist = false;
        size_t id;
        for (size_t i = 0; i < Size; i++) {
            if (arr[i].getlName() == last) {
                exist = true;
                id = i;
            }
        }
        if (exist == false)
            std::cout << "Not founded" << std::endl;
        else {
            std::cout << "----------contact info----------" << std::endl;
            arr[id].printTablehead();
            std::cout << std::setw(10) << std::left << id + 1;
            arr[id].printInfo();
        }
    }
    void searchByClass(std::string classs) {
        size_t id;
        bool exist = false;
        for (size_t i = 0; i < Size; i++) {
            if (arr[i].getClassi() == classs) {
                id = i;
                exist = true;
                std::cout << "----------contacts info----------" << std::endl;
                arr[id].printTablehead();
                std::cout << std::setw(10) << std::left << id + 1;
                arr[id].printInfo();
            }
        }
        if (exist == false)
            std::cout << "No contacts in this classification" << std::endl;
    }
    void printAll() {
        size_t id;
        std::cout << "----------contacts info----------" << std::endl;
        arr[0].printTablehead();
        for (size_t i = 0; i < Size; i++) {
            id = i;
            std::cout << std::setw(10) << std::left << id + 1;
            arr[i].printInfo();
        }
    }
    void printFav() {
        size_t id;
        std::cout << "----------contacts info----------" << std::endl;
        arr[0].printTablehead();
        for (size_t i = 0; i < Size; i++) {
            if (arr[i].isFav() == 1) {
                id = i;
                std::cout << std::setw(10) << std::left << id + 1;
                arr[i].printInfo();
            }
        }
    }
    Array& operator[](const Array& other) {
        if (this != &other) {
            delete[] arr;
            Size = other.Size;
            capacity = other.capacity;
            for (size_t i = 0; i < Size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] arr;
            Size = other.Size;
            capacity = other.capacity;
            for (size_t i = 0; i < Size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    void Update(const T& p, size_t index) {
        arr[index] = p;
    }
    size_t getsize() {
        return Size;
    }
    void displayfile(std::ofstream& outfile) {
        for (int i = 0; i < this->getsize(); i++) {
            outfile << std::setw(10) << std::left << i + 1;
            arr[i].printdataPfile(outfile);
            for (size_t i = 0; i < 146; i++) {
                outfile << "-";
            }
        }
    }
    void displayFromFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            throw std::runtime_error("Could not open file for reading.");
        }
        std::string line;
        std::getline(infile, line);
        std::cout << line << std::endl;
        while (std::getline(infile, line)) {
            std::cout << line << std::endl;
            std::cout << std::endl;
        }
        infile.close();
    }
};
#endif
