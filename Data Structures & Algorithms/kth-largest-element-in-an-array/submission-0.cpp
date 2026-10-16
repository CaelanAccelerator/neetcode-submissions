class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        for (auto& elem : nums) {
            pq.push(elem);
        }
        while (--k) {
            pq.pop();
        }
        return pq.top();
    }
};
