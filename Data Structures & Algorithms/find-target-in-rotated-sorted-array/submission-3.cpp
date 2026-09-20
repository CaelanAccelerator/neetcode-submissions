class Solution {
public:
    int search(vector<int>& nums, int target) {
        return sRec(nums,target,0,nums.size()-1);
    }

    int sRec(vector<int>& nums, int target, int l, int r){
        cout<<"l : "<<l<<" r : "<<r<<endl;
        if(l > r)return -1;

        bool a,b,c;
        int mid = (l + r)/2;
        if(nums[mid] == target) return mid;

        a = target >= nums[l];
        b = target > nums[mid];
        c = target > nums[r];

        if(nums[mid] < nums[r] && nums[l] > nums[r]){
            cout<<"b1";
            if((a && b && c) || (!a && !b && !c)){
                return sRec(nums,target,l,mid - 1);
            }else{
                return sRec(nums,target,mid + 1, r);
            }   
        }
        else if(nums[mid] > nums[l] && nums[l] > nums[r]){
            cout<<"b2";
            if(a && !b && c){
                return sRec(nums,target,l,mid - 1);
            }else{
                return sRec(nums,target,mid + 1, r);
            }
        }else if(nums[l] < nums[r]){
            cout<<"b3";
            if(nums[mid] > target){
                return sRec(nums,target,l,mid - 1);
            }else{
                return sRec(nums,target,mid + 1, r);
            }
        }else{
            if(nums[mid] > target){
                return sRec(nums,target,mid + 1, r);
            }else{
                return sRec(nums,target,l,mid - 1);
            }
        }
    }
};


