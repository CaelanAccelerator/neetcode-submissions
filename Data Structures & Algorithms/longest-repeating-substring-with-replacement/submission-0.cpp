class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0;
        int l = 0;
        int res = 0;
        unordered_map<char,int> m;
        for(int r = 0; r < s.size(); r++){
            m[s[r]]++;
            maxf = max(maxf,m[s[r]]);

            while((r - l + 1) - maxf > k){
                m[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
