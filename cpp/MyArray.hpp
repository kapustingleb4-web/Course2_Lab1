#ifndef MYARRAY_HPP
#define MYARRAY_HPP
#include <string>
#include <iostream>

using namespace std;

class MyArray {
protected:
    string* data;
    int size;
    int capacity;
    void resize(int new_capacity);

public:
    MyArray();
    ~MyArray();

    void push_back(const string& val);
    void insert_at(int index, const string& val);
    void remove_at(int index);
    void remove_by_value(const string& val);
    void update_at(int index, const string& val);
    string get(int index) const;
    int length() const;
    void print() const;
    
    string* get_raw_data() const { return data; }
    void set_from_array(const string* arr, int count);
};
#endif
