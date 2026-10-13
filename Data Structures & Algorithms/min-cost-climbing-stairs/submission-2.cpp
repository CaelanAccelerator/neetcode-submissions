class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> ans(cost.size() + 1, INT_MAX);
        ans[0] = 0;
        ans[1] = 0;
        for (int i = 0; i < cost.size(); i++) {
            if(i + 1 >= cost.size()) ans.back() = min(ans.back(), cost[i] + ans[i]);
            else {
                ans[i + 1] = min(ans[i + 1], cost[i] + ans[i]);    
                ans[i + 2] = min(ans[i + 2], cost[i] + ans[i]);
            }       
        }
        return ans.back();
    }
};
