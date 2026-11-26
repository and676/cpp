#include <stack>

class Stack1 {
public:
    stack<int> stack;   // C++ 标准库的栈，对应 java.util.Stack

    bool isEmpty() {
        return stack.empty();
    }

    void push(int num) {
        stack.push(num);
    }

    int pop() {
        int ans = stack.top();   // C++ 的 pop 不返回值，要先 top 再 pop
        stack.pop();
        return ans;
    }

    int peek() {
        return stack.top();
    }

    int size() {
        return (int)stack.size();
    }
};






class Stack2 {
public:
    vector<int> stack;
    int size;

    // 同时在栈里的元素个数不会超过 n
    Stack2(int n) {
        stack = vector<int>(n);
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int num) {
        stack[size++] = num;
    }

    int pop() {
        return stack[--size];
    }

    int peek() {
        return stack[size - 1];
    }

    int size() {
        return size;
    }
};