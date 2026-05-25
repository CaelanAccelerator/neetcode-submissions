class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int val = stoi(tokens[0]);
        for(auto &token : tokens)
        {
            st.push(token);
            int left,right;
            if(token == "+"){
                st.pop();
                    right = stoi(st.top());
                    st.pop();
                    left = stoi(st.top());
                    st.pop();
                    val = left + right;
                    st.push(to_string(val));
            }
            if(token == "-"){
                st.pop();
                    right = stoi(st.top());
                    st.pop();
                    left = stoi(st.top());
                    st.pop();
                    val = left - right;
                    st.push(to_string(val));
            }
            if(token == "*"){
                st.pop();
                    right = stoi(st.top());
                    st.pop();
                    left = stoi(st.top());
                    st.pop();
                    val = left * right;
                    st.push(to_string(val));
            }
            if(token == "/"){
                st.pop();
                    right = stoi(st.top());
                    st.pop();
                    left = stoi(st.top());
                    st.pop();
                    val = left / right;
                    st.push(to_string(val));
            }
            
        }
        return val;        
    }
};
