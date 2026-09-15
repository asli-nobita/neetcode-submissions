class MinStack { 
    stack<pair<int,int>> stk; 
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minElement = val; 
        if (!stk.empty()) minElement = min(minElement, stk.top().second); 
        stk.push({val, minElement});  
    }
     
    void pop() {
        stk.pop(); 
    }
    
    int top() {
        return stk.top().first; 
    }
    
    int getMin() {
        return stk.top().second; 
    }
};
