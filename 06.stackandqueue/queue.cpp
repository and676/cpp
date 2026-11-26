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