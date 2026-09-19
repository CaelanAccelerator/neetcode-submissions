class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        return searchRec(nums,target,l,r);
    }

    int searchRec(vector<int>& nums, int target, int l, int r) {
        if(l > r)return - 1;
        int mid = (l + r)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            return searchRec(nums, target, mid + 1, r);
        else
            return searchRec(nums, target, l, mid - 1);
    }

};
