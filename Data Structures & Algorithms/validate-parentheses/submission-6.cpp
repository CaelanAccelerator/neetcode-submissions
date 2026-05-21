class Solution {
public:
    bool isValid(string s) {
        if((s.length() & 1) == 1) return false;
        stack<char> st;
        unordered_map<char,char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        for(auto &c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else if(c == ')' || c == ']' || c == '}'){
                if(st.empty() || m[st.top()] != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
