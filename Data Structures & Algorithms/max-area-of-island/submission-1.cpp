class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans{0};
        for(size_t i{0}; i<grid.size();i++){
            for(size_t j{0}; j<grid[0].size();j++){
                ans = max(ans, getArea(grid,i,j));
            }
        }
        return ans;
    }

    int getArea(vector<vector<int>>&grid, size_t i, size_t j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        if(grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + getArea(grid,i,j-1) + getArea(grid,i,j+1) + getArea(grid,i - 1,j) + getArea(grid,i + 1,j);
    }
};
