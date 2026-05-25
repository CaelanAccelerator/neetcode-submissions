class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = 0;

        int l = 0, r = 0;
        unordered_map<char,int> m;

        for(; r < s.length(); r++){
            m[s[r]]++;
            //cout<<s[r]<<" : "<<m[s[r]]<<endl;
            while(m[s[r]] > 1){
                cout<<s[l]<<" : "<<m[s[l]]<<endl;
                m[s[l]]--;
                l++;
            }
            cout<<"after "<<s[l]<<" : "<<m[s[l]]<<endl;

            len = r - l + 1;
            res = max(len,res);
            //cout<<r<<" "<<l<<endl;
        }
        return res;
    }
};
