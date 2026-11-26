#include <vector>
using namespace std;

class MyCircularQueue {
public:
    vector<int> queue;
    int l, r, size, limit;

    MyCircularQueue(int k) : queue(k), l(0), r(0), size(0), limit(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;   // ← 调 isFull
        queue[r] = value;
        r = (r == limit - 1) ? 0 : (r + 1);
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;  // ← 调 isEmpty
        l = (l == limit - 1) ? 0 : (l + 1);
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return queue[l];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int last = (r == 0) ? (limit - 1) : (r - 1);
        return queue[last];
    }

    bool isEmpty() {       // ← 这里定义了
        return size == 0;
    }

    bool isFull() {        // ← 这里也定义了（和顺序无关，放最后也行）
        return size == limit;
    }
};   // ← 类结尾必须有分号！