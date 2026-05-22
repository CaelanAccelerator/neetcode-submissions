class Solution {
public:
    string minWindow(string s, string t) {
    if (t.empty() || t.size() > s.size()) return "";
    unordered_map<char,int> need, win;
    for (char c : t) need[c]++;
    int need_kinds = need.size();     
    int have = 0;                     

    int l = 0, bestL = 0, bestLen = INT_MAX;
    for (int r = 0; r < (int)s.size(); r++) {
        char c = s[r];
        win[c]++;
        
        if (need.count(c) && win[c] == need[c]) have++;

        while (have == need_kinds) {                 
            if (r - l + 1 < bestLen) { bestLen = r - l + 1; bestL = l; }
            char d = s[l];
            win[d]--;
           
            if (need.count(d) && win[d] < need[d]) have--;
            l++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
}

    
};
