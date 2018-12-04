class MinStack {
private:
    stack<int> st, min;
public:
    /** initialize your data structure here. */
    MinStack() { }
    
    void push(int x) {
        st.push(x);
        if(min.empty() || min.top() >= x){
            min.push(x);
        }
    }
    
    void pop() {
        if(st.top() == min.top()){
            st.pop();
            min.pop();
        }else{
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */