#include "MyQueue.hpp"
#include <stdexcept>

using namespace std;

void MyQueue::push(const string& val) { push_back(val); }

string MyQueue::pop() {
    if (size == 0) throw runtime_error("Queue is empty");
    string v = data[0];
    remove_at(0);
    return v;
}

void MyQueue::print() const {
    for (int i = 0; i < size; ++i) cout << data[i] << " ";
}
