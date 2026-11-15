#include "ForwardList.hpp"
#include <stdexcept>

using namespace std;

ForwardList::ForwardList() : head(nullptr), size(0) {}
ForwardList::~ForwardList() {
    while (head) { Node* t = head; head = head->next; delete t; }
}

void ForwardList::push_front(const string& val) {
    Node* n = new Node(val); n->next = head; head = n; size++;
}

void ForwardList::push_back(const string& val) {
    Node* n = new Node(val);
    if (!head) head = n;
    else { Node* cur = head; while (cur->next) cur = cur->next; cur->next = n; }
    size++;
}

void ForwardList::insert_before_at(int index, const string& val) {
    if (index < 0 || index > size) throw out_of_range("Index out of range");
    if (index == 0) { push_front(val); return; }
    Node* cur = head;
    for (int i = 0; i < index - 1; ++i) cur = cur->next;
    Node* n = new Node(val); n->next = cur->next; cur->next = n; size++;
}

void ForwardList::insert_after_at(int index, const string& val) {
    if (index < 0 || index >= size) throw out_of_range("Index out of range");
    Node* cur = head;
    for (int i = 0; i < index; ++i) cur = cur->next;
    Node* n = new Node(val); n->next = cur->next; cur->next = n; size++;
}

void ForwardList::insert_before_value(const string& target, const string& val) {
    if (!head) return;
    if (head->data == target) { push_front(val); return; }
    Node* cur = head;
    while (cur->next && cur->next->data != target) cur = cur->next;
    if (cur->next) {
        Node* n = new Node(val); n->next = cur->next; cur->next = n; size++;
    }
}

void ForwardList::insert_after_value(const string& target, const string& val) {
    Node* cur = head;
    while (cur && cur->data != target) cur = cur->next;
    if (cur) {
        Node* n = new Node(val); n->next = cur->next; cur->next = n; size++;
    }
}

void ForwardList::pop_front() {
    if (!head) return;
    Node* t = head; head = head->next; delete t; size--;
}

void ForwardList::pop_back() {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; size--; return; }
    Node* cur = head;
    while (cur->next->next) cur = cur->next;
    delete cur->next; cur->next = nullptr; size--;
}

void ForwardList::remove_at(int index) {
    if (index < 0 || index >= size) throw out_of_range("Index out of range");
    if (index == 0) { pop_front(); return; }
    Node* cur = head;
    for (int i = 0; i < index - 1; ++i) cur = cur->next;
    Node* t = cur->next; cur->next = t->next; delete t; size--;
}

void ForwardList::remove_by_value(const string& val) {
    if (!head) return;
    if (head->data == val) { pop_front(); return; }
    Node* cur = head;
    while (cur->next && cur->next->data != val) cur = cur->next;
    if (cur->next) { Node* t = cur->next; cur->next = t->next; delete t; size--; }
}

void ForwardList::remove_all_by_value(const string& val) {
    while (head && head->data == val) pop_front();
    if (!head) return;
    Node* cur = head;
    while (cur->next) {
        if (cur->next->data == val) {
            Node* t = cur->next; cur->next = t->next; delete t; size--;
        } else {
            cur = cur->next;
        }
    }
}

void ForwardList::remove_before_value(const string& target) {
    if (!head || head->data == target) return;
    if (head->next && head->next->data == target) { pop_front(); return; }
    Node* cur = head;
    while (cur->next && cur->next->next && cur->next->next->data != target) cur = cur->next;
    if (cur->next && cur->next->next) {
        Node* t = cur->next; cur->next = t->next; delete t; size--;
    }
}

void ForwardList::remove_after_value(const string& target) {
    Node* cur = head;
    while (cur && cur->data != target) cur = cur->next;
    if (cur && cur->next) {
        Node* t = cur->next; cur->next = t->next; delete t; size--;
    }
}

bool ForwardList::find(const string& val) const {
    Node* cur = head;
    while (cur) { if (cur->data == val) return true; cur = cur->next; }
    return false;
}

int ForwardList::getSize() const { return size; }


void ForwardList::print() const {
    Node* cur = head;
    while (cur) { cout << cur->data << " -> "; cur = cur->next; }
    cout << "NULL";
}

vector<string> ForwardList::getData() const {
    vector<string> res; Node* cur = head;
    while (cur) { res.push_back(cur->data); cur = cur->next; }
    return res;
}

void ForwardList::setData(const vector<string>& d) {
    while (head) { Node* t = head; head = head->next; delete t; }
    size = 0;
    for (const auto& v : d) push_back(v);
}