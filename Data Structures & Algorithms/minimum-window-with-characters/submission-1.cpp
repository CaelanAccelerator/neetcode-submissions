class Solution {
public:
    bool contained(unordered_map<char,int> m1, unordered_map<char,int> m2, string t){
        for(auto &c : t){
            if(m1[c] > m2[c])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";

        int l = 0,r = 0;
        int lFinal = l, rFinal = r;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        int minLen = INT_MAX;

        for(auto &c : t){
            m1[c]++;
        }
        
        for(;r < s.length(); r++){
            m2[s[r]]++;
            while(contained(m1,m2,t)){
                if(r - l + 1 < minLen){
                minLen = r - l + 1;
                lFinal = l;
                rFinal = r + 1;
                }
                 m2[s[l]]--;
                l++;
            }
        }
        string ans = "";
        for(;lFinal < rFinal; lFinal++){
            ans += s[lFinal];
        }
        

        return ans;
    }

    
};
