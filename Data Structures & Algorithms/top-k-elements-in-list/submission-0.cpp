class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(auto&n:nums){
            map[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto &[num, freq] : map){
            minHeap.push({freq,num});
            if(minHeap.size() > k) minHeap.pop();
        }
        
        vector<int> ans;
        while(!minHeap.empty()){
            pair<int,int> p = minHeap.top();
            ans.push_back(p.second);
            minHeap.pop();
        }
        return ans;
    }
};
