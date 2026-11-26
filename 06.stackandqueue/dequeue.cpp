#include <deque>
#include <vector>
using namespace std;

// 版本 1：标准库 deque（对应 Java 的 LinkedList 实现）
class MyCircularDeque1 {
public:
    deque<int> dq;
    int size;
    int limit;

    MyCircularDeque1(int k) : size(0), limit(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        dq.push_front(value);
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        dq.push_back(value);
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        dq.pop_front();
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        dq.pop_back();
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return dq.front();
    }

    int getRear() {
        if (isEmpty()) return -1;
        return dq.back();
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
};

// 版本 2：手写循环数组（常数更快）
class MyCircularDeque2 {
public:
    vector<int> deque;
    int l, r, size, limit;

    MyCircularDeque2(int k) : deque(k), l(0), r(0), size(0), limit(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            l = r = 0;
            deque[0] = value;
        } else {
            l = (l == 0) ? (limit - 1) : (l - 1);
            deque[l] = value;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            l = r = 0;
            deque[0] = value;
        } else {
            r = (r == limit - 1) ? 0 : (r + 1);
            deque[r] = value;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        l = (l == limit - 1) ? 0 : (l + 1);
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        r = (r == 0) ? (limit - 1) : (r - 1);
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deque[l];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deque[r];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
};