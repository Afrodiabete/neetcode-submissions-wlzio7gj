class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(min_stk.empty() || min_stk.top()>= val){
            min_stk.push(val);
        }
        return;
    }
    
    void pop() {
        if(min_stk.top()== stk.top()){
            min_stk.pop();
        }
        stk.pop();
        
        return;
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
