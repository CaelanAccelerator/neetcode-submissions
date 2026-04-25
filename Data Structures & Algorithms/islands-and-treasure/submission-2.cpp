class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[0].size();j++){
                if(grid[i][j] == 0)
                    dfs(grid,i,j,-1);
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
};
