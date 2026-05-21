class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;

        vector<int> m1(26,0);
        vector<int> m2(26,0);

        int l = 0;
        int r = 0;
        for(auto &c : s1){
            m1[c - 'a'] += 1;
        }
        for(int i = 0; i < s1.size(); i++){
            m2[s2[i] - 'a'] += 1;
        }

        int match = 0;
        for(int i = 0; i < m1.size(); i++){
            if(m1[i] == m2[i]){
                match++;
            }
        }

        for(int l = 0, r = s1.size() - 1; r < s2.size(); l++, r++){
            if(match == 26) return true;
            if(l == 0) continue;
             
            
            m2[s2[l - 1] - 'a'] -= 1;
            char dropped = s2[l - 1];
            
            if(m1[dropped - 'a'] == m2[dropped - 'a']){
                match += 1;
            }else if(m1[dropped - 'a'] - 1 == m2[dropped - 'a']){
                match -= 1;
            }
            m2[s2[r] - 'a'] += 1;
            char added = s2[r];
            if(m1[added - 'a'] == m2[added - 'a']){
                match += 1;
            }else if(m1[added - 'a'] + 1 == m2[added - 'a']){
                match -= 1;
            }
            
        }

        return match == 26;
    }
};
