#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> in;
    stack<int> out;

    MyQueue() {}

    // 倒数据：in → out，条件是 out 空了才倒，而且一次倒完
    void inToOut() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());   // 先看 in 顶是谁
                in.pop();             // 再删掉
            }
        }
    }

    void push(int x) {
        in.push(x);
        inToOut();
    }

    int pop() {
        inToOut();
        int ans = out.top();   // 先取
        out.pop();             // 再删
        return ans;
    }

    int peek() {
        inToOut();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};