class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        ans = bfs(grid,q);
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(grid[i][j] == 1)
                    ans = -1;
            }
        }

        return ans;
    }
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q){
        if(q.empty()) return 0;
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        const int ROW = grid.size();
        const int COL = grid[0].size();

        int round = -1;
        while(!q.empty()){
            vector<pair<int,int>> rottened;
            while(!q.empty()){
                rottened.emplace_back(q.front());
                q.pop();
            }
            for(auto& elem : rottened){
                auto [i,j] = elem;
                for(auto & dir : directions){
                    int r = i + dir[0];
                    int c = j + dir[1];
                    if(r < 0 || c < 0 || r >= ROW || c >= COL)
                        continue;
                    if(grid[r][c] == 0) 
                        continue;
                    if(grid[r][c] == 2)
                        continue;
                    grid[r][c] = 2;
                    q.push({r,c});
                }
            }
            round++;
        }
        return round;
    }
};
