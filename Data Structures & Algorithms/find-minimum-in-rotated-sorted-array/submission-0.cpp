class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums[0] <= nums[nums.size()/2] && nums[nums.size()/2] <= nums[nums.size()-1])
         return nums[0];
        return nums[fmHelper(nums,0,nums.size()-1)];
    }
    int fmHelper(vector<int> &nums, int l, int r){
        if(l == r)
            return l;
        int mid = (l + r) /2;
        if(mid < nums.size()-1 && mid > 0 && nums[mid] < nums[mid - 1])
            return mid;
        if(nums[mid] < nums[r])
            return fmHelper(nums,l,mid -1);
        return fmHelper(nums,mid+1,r);
    }
};
