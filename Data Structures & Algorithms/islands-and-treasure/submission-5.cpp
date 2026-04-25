class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[0].size();j++){
                if(grid[i][j] == 0)
                    bfs(grid,i,j);
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int val){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        if(grid[i][j] == -1) return;
        if(grid[i][j] <= val + 1 && val != -1) return;

        grid[i][j] = val + 1;
        dfs(grid, i+1, j, val + 1);
        dfs(grid, i-1, j, val + 1);
        dfs(grid, i, j+1, val + 1);
        dfs(grid, i, j-1, val + 1);
    }

    void bfs(vector<vector<int>>& grid, int i, int j){
        vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                            {0, 1}, {0, -1}};
        queue<pair<int,int>> q;
        vector<vector<bool>> updated;
        updated.assign(grid.size(), vector<bool>(grid[0].size(),false));

        q.push({i,j});
        
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            if(updated[row][col] == false){
                updated[row][col] = true;
                for(auto& dir : directions){
                    int i = row + dir[0];
                    int j = col + dir[1];
                    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
                        continue;
                    if(grid[i][j] == -1)
                        continue;
                    grid[i][j] = grid[row][col] + 1 < grid[i][j] ?  grid[row][col] + 1 : grid[i][j];
                    q.push({i,j});
                    // std::cout<<i<<" "<<j<<std::endl;
                }
            }
        }
    }
};
