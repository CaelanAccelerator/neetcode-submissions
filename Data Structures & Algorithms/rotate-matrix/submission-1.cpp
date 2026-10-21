class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        int rotate = matrix.size()/2;
        for (int i = 0; i < rotate; i++) {
            for (int j = i; j < n; j++) {
                int col = i, row = j;
                int temp = matrix[row][col];
                for (int k = 0; k < 4; k++) {
                    int t1 = matrix[col][n - row + i];
                    matrix[col][n - row + i] = temp;
                    temp = t1;
                    int t = col;
                    col = n - row + i;
                    row = t;
                }
            }
            n-=1;
        }
    }
};
