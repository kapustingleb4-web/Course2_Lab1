#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP
#include "MyArray.hpp"

using namespace std;

class MyQueue : public MyArray {
public:
    void push(const string& val);
    string pop();
    void print() const;
};
#endif
