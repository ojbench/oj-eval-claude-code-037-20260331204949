#include <bits/stdc++.h>
#include <iostream>
using namespace std;

namespace DoubleLinkList {

struct NODE {
    int data;
    NODE *next;
    NODE *pre;
    NODE() {}
    NODE(int val) { this->data = val; }
};

NODE *head = nullptr, *tail = nullptr;
int len = 0;

void Pre() {
    head = new NODE();
    tail = new NODE();
    head->pre = NULL;
    tail->next = NULL;
    head->next = tail;
    tail->pre = head;
}

NODE *move(int i) {
    NODE *cur = head;
    for (int j = 0; j <= i; j++) {
        cur = cur->next;
    }
    return cur;
}

void insert(int i, int x) {
    // Insert at position i (0-indexed)
    // The new node will be at position i after insertion
    NODE *newNode = new NODE(x);
    NODE *cur = move(i);  // Get node that will be at position i+1

    // Insert newNode before cur
    newNode->next = cur;
    newNode->pre = cur->pre;
    cur->pre->next = newNode;
    cur->pre = newNode;

    len++;
}

void remove(int i) {
    // Remove node at position i (0-indexed)
    NODE *cur = move(i);  // Get node at position i

    // Remove cur from the list
    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;

    delete cur;
    len--;
}

int Get_length() {
    return len;
}

int Query(int i) {
    // Return the value at position i (0-indexed)
    if (i < 0 || i >= len) {
        return -1;
    }
    NODE *cur = move(i);
    return cur->data;
}

void Print() {
    if (len == 0) {
        cout << -1 << endl;
        return;
    }

    NODE *cur = head->next;
    bool first = true;
    while (cur != tail) {
        if (!first) {
            cout << " ";
        }
        cout << cur->data;
        first = false;
        cur = cur->next;
    }
    cout << endl;
}

void Clear() {
    NODE *cur = head;
    while (cur != nullptr) {
        NODE *next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
    tail = nullptr;
    len = 0;
}

} // namespace DoubleLinkList

int n;
int main() {
    cin >> n;
    int op, x, p, ans;
    DoubleLinkList::Pre();
    for (int _ = 0; _ < n; ++_) {
        cin >> op;
        switch (op) {
        case 0:
            ans = DoubleLinkList::Get_length();
            cout << ans << endl;
            break;
        case 1:
            cin >> p >> x;
            DoubleLinkList::insert(p, x);
            break;
        case 2:
            cin >> p;
            ans = DoubleLinkList::Query(p);
            cout << ans << endl;
            break;
        case 3:
            cin >> p;
            DoubleLinkList::remove(p);
            break;
        case 4:
            DoubleLinkList::Print();
            break;
        }
    }
    DoubleLinkList::Clear();
    return 0;
}
