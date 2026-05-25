class Solution {
    // string evaluate(string expr){
    //     int left = expr[0] - '0';
    //     int right = expr[2] - '0';
    //     switch (expr[1]){
    //         case '+':
    //             return to_string(left + right);
    //             break;
    //         case '-':
    //             return to_string(left - right);
    //             break;
    //         case '*':
    //             return to_string(left * right);
    //             break;
    //         case '/':
    //             return to_string(left / right);
    //             break;
    //     }   
    // }
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
                    st.pop();cout<<left<<token<<right<<endl;
                    val = left + right;
                    st.push(to_string(val));
            }
            if(token == "-"){
                st.pop();
                    right = stoi(st.top());
                    st.pop();
                    left = stoi(st.top());
                    st.pop();cout<<left<<token<<right<<endl;
                    val = left - right;
                    st.push(to_string(val));
            }
            if(token == "*"){
                st.pop();
                    right = stoi(st.top());
                    st.pop();
                    left = stoi(st.top());
                    st.pop();cout<<left<<token<<right<<endl;
                    val = left * right;
                    st.push(to_string(val));
            }
            if(token == "/"){
                st.pop();
                    right = stoi(st.top());
                    st.pop();
                    left = stoi(st.top());
                    st.pop();cout<<left<<token<<right<<endl;
                    val = left / right;
                    st.push(to_string(val));
            }
            
        }
        return val;        
    }
};
