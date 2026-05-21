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
            if(m.contains(c)){
                st.push(c);
            }else if(!st.empty()){
                if(m[st.top()] == c){
                    st.pop();
                }else{
                    return false;
                }    
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
