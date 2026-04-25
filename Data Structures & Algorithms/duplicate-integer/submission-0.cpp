class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> contains;
        for(auto &elem : nums){
            if(contains[elem] > 0)
                return true;
            ++contains[elem];
        }
        return false;
    }
};