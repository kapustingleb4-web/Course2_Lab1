#include "MyArray.hpp"
#include <stdexcept>

using namespace std;

MyArray::MyArray() : data(nullptr), size(0), capacity(0) {}
MyArray::~MyArray() { delete[] data; }

void MyArray::resize(int new_capacity) {
    string* new_data = new string[new_capacity];
    for (int i = 0; i < size; ++i) new_data[i] = data[i];
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void MyArray::push_back(const string& val) {
    if (size == capacity) resize(capacity == 0 ? 2 : capacity * 2);
    data[size++] = val;
}

void MyArray::insert_at(int index, const string& val) {
    if (index < 0 || index > size) throw out_of_range("Index out of range");
    if (size == capacity) resize(capacity == 0 ? 2 : capacity * 2);
    for (int i = size; i > index; --i) data[i] = data[i - 1];
    data[index] = val;
    size++;
}

void MyArray::remove_at(int index) {
    if (index < 0 || index >= size) throw out_of_range("Index out of range");
    for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
    size--;
}

void MyArray::remove_by_value(const string& val) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == val) { remove_at(i); return; }
    }
}

void MyArray::update_at(int index, const string& val) {
    if (index < 0 || index >= size) throw out_of_range("Index out of range");
    data[index] = val;
}

string MyArray::get(int index) const {
    if (index < 0 || index >= size) throw out_of_range("Index out of range");
    return data[index];
}

int MyArray::length() const { return size; }

void MyArray::print() const {
    cout << "[ ";
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
    cout << "]";
}

void MyArray::set_from_array(const string* arr, int count) {
    delete[] data;
    data = new string[count];
    for (int i = 0; i < count; ++i) data[i] = arr[i];
    size = count;
    capacity = count;
}
