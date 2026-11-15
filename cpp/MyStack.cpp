#include "MyStack.hpp"
#include <stdexcept>

using namespace std;

void MyStack::push(const string& val) { push_back(val); }

string MyStack::pop() {
    if (size == 0) throw runtime_error("Stack is empty");
    string v = data[size - 1];
    remove_at(size - 1);
    return v;
}

void MyStack::print() const {
    for (int i = size - 1; i >= 0; --i) cout << data[i] << " ";
}
