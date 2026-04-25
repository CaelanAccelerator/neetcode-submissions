class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
       unordered_map<char,int> contains;
       for(auto& elem: s){
            contains[elem]++;
       }
       for(auto& elem: t){
            contains[elem]--;
       }
       for(auto& elem: s){
            if(contains[elem] != 0) return false;
       }
       return true;
    }
};
