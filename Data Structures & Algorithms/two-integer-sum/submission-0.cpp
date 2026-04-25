class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> contain;
        for(size_t i = 0; i < nums.size(); i++){
            if(contain.find(target - nums[i]) != contain.end())
                return{contain[target - nums[i]], i};
            contain[nums[i]] = i;
        }
        return {};
    }
};
