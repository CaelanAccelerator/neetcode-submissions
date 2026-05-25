class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int len = 0;

        int l = 0, r = 0;
        int maxf = 0;
        unordered_map<char, int> m;
        for(char c= 'A'; c <= 'Z'; c++){
            m.emplace(c, 0);
        }

        for(; r < s.length(); r++){
            m[s[r]]++;
            maxf = max(maxf, m[s[r]]);
            
            while(r - l + 1 > maxf + k){
                m[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
