#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <string>
#include <map>
#include "MyArray.hpp"
#include "ForwardList.hpp"
#include "DoublyList.hpp"
#include "MyStack.hpp"
#include "MyQueue.hpp"
#include "AVLTree.hpp"

using namespace std;

struct Database {
    map<string, MyArray> arrays;
    map<string, ForwardList> fLists;
    map<string, DoublyList> dLists;
    map<string, MyStack> stacks;
    map<string, MyQueue> queues;
    map<string, AVLTree> trees;

    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};
#endif
