class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for (auto& stone : stones) {
            q.push(stone);
        }
        while (q.size() > 1) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            int res = abs(first - second);
            if(res != 0){
                q.push(res);
            }
        }
        if (q.empty()) {
            return 0;
        }
        return q.top();
    }
    priority_queue<int,vector<int>> q;
};
