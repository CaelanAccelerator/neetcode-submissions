class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = 0;

        int l = 0, r = 0;
        unordered_map<char,int> m;

        for(; r < s.length(); r++){
            m[s[r]]++;
            while(m[s[r]] > 1){
                m[s[l]]--;
                l++;
            }
            len = r - l + 1;
            res = max(len,res);
        }
        return res;
    }
};
