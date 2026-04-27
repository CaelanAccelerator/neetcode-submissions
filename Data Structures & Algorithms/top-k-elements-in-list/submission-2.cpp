class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int size = nums.size() + 1;
        vector<vector<int>> counter(size);
        unordered_map<int,int> map;
        for(auto &n:nums){
            map[n]++;
        }
        for(auto &[num, freq] :map){
            counter[freq].push_back(num);
        }

        vector<int> ans;
        ans.reserve(k);
        for(int i = size - 1; i >= 0; i--){
            for(auto &elem : counter[i]){
                ans.push_back(elem);
                if(ans.size() == k)
                return ans;
            }
        }
        return ans;
    }
};
