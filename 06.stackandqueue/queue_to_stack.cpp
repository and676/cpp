#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> queue;

    MyStack() {}

    // O(n)：新元素入队后，把前面所有元素依次"轮转"到后面
    void push(int x) {
        int n = queue.size();
        queue.push(x);
        for (int i = 0; i < n; i++) {
            queue.push(queue.front());   // 队头移到队尾
            queue.pop();                 // 删掉原来的队头
        }
    }

    int pop() {
        int ans = queue.front();
        queue.pop();
        return ans;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }
};