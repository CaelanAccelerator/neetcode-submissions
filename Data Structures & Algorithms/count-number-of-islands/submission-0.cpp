class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans {0};
        for(size_t i = 0; i < grid.size(); i++){
            for(size_t j = 0; j < grid[0].size(); j++){                
                ans += detectAndMark(grid, i, j);
            }
        }
        return ans;
    }
private:
    int detectAndMark(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0)
            return 0;
        if(grid[i][j] == '0' || grid[i][j] == '2') return 0;
        if(grid[i][j] == '1'){
            grid[i][j] = '2';
            detectAndMark(grid, i + 1, j);
            detectAndMark(grid, i - 1, j);
            detectAndMark(grid, i, j + 1);
            detectAndMark(grid, i, j - 1);
            return 1;
        }
    }
};
