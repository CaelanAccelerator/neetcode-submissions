class MinStack {
private:
    vector<int> st;
    vector<int> withMin;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        int minE;
        if(withMin.size() > 0)
            minE = min(val,withMin.back());
        else
            minE = val;
        withMin.push_back(minE);
    }
    
    void pop() {
        st.pop_back();
        withMin.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return withMin.back();
    }
};
