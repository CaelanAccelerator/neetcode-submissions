class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](vector<int>& v, vector<int>& u){
            return (v[0] * v[0] + v[1] * v[1]) > (u[0] * u[0] + u[1] * u[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(compare);
        for (auto& elem : points) {
            q.push(elem);
        }
        
        vector<vector<int>> ans;
        while(k--){
            ans.emplace_back(q.top());
            q.pop();
        }
        return ans;
    }
};
