class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        vector<int> count(26,0);
        int maxf = 0;
        for(; r < s.length(); r++){
            count[s[r] - 'A']++;
            maxf = max(maxf, count[s[r] - 'A']);
            while(r - l + 1 > k + maxf){
                // cout<<s[r] - 'A'<<endl;
                count[s[l] - 'A']--;
                l++;               
            }
            ans = max(ans, r - l + 1);
            
        }
        return ans;
    }
};
