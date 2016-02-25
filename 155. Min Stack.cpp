class MinStack {
public:
    void push(int x) {
        stack.push_back(x);
        if(min_stack.empty() || min_stack.back() >= x)
            min_stack.push_back(x);
    }

    void pop() {
        if(stack.empty()) return;
        if(stack.back() == min_stack.back())
            min_stack.pop_back();
        stack.pop_back();
    }

    int top() {
        if(stack.empty()) return INT_MAX;
        return stack.back();
    }

    int getMin() {
        if(min_stack.empty()) return INT_MAX;
        return min_stack.back();
    }
    
private:
    vector<int> stack;
    vector<int> min_stack;
};
