class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target < matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size() - 1]) return false;
        return  searchRow(matrix[findRow(matrix,target,0,matrix.size() - 1)],target,0,matrix[0].size()-1);
    }

    int findRow(vector<vector<int>>& matrix, int target, int s, int e){
        if(s > e)return 0;
        int mid = (s + e)/2;
        
        int rowSize = matrix[0].size() - 1;
        if(target <= matrix[mid][rowSize] && target >= matrix[mid][0]){
            return mid;
        }
        if(target > matrix[mid][rowSize])
            return findRow(matrix,target,mid+1,e);
        else
            return findRow(matrix,target,s,mid - 1);
    }

    bool searchRow(vector<int> &row, int target, int l, int r){
        if(l > r)return false;
        int mid = (l + r)/2;
        if(row[mid] == target)return true;
        if(target > row[mid])return searchRow(row,target, mid+1, r);
        else
            return searchRow(row,target,l,mid-1);
    }
};
