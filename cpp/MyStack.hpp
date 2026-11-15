#ifndef MYSTACK_HPP
#define MYSTACK_HPP
#include "MyArray.hpp"

using namespace std;

class MyStack : public MyArray {
public:
    void push(const string& val);
    string pop();
    void print() const;
};
#endif
