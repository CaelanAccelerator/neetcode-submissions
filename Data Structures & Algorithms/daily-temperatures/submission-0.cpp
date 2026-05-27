class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int>res(temperatures.size(),0);

        for(int i = 0; i < temperatures.size(); i++)
        {
            if(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                while(!st.empty()&& temperatures[i] > temperatures[st.top()])
                {
                    int idx = st.top();
                    res[idx] = i -idx;
                    st.pop();
                }
            }
            st.push(i);
            
        }
        return res;
    }
};
