#include <stack>
#include <vector>
using namespace std;

// 版本 1：双栈（标准库 stack）
class MinStack1 {
public:
    stack<int> data;
    stack<int> min;

    MinStack1() {}

    void push(int val) {
        data.push(val);
        if (min.empty() || val <= min.top()) {
            min.push(val);
        } else {
            min.push(min.top());
        }
    }

    void pop() {
        data.pop();
        min.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};

// 版本 2：双数组（手写栈，常数更小）
class MinStack2 {
public:
    static const int MAXN = 8001;
    vector<int> data;
    vector<int> min;
    int size;

    MinStack2() : data(MAXN), min(MAXN), size(0) {}

    void push(int val) {
        data[size] = val;
        if (size == 0 || val <= min[size - 1]) {
            min[size] = val;
        } else {
            min[size] = min[size - 1];
        }
        size++;
    }

    void pop() {
        size--;
    }

    int top() {
        return data[size - 1];
    }

    int getMin() {
        return data[size - 1];
    }
};