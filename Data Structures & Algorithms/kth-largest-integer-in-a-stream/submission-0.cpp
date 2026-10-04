class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            heap_.push(nums[i]);
            if(heap_.size() > k){
                heap_.pop();
            }
        }
    }
    
    int add(int val) {
        heap_.push(val);
        int res;
        if(heap_.size() > k){
            heap_.pop();
        }
        return heap_.top();
    }
private:
    priority_queue<int,vector<int>, greater<int>>heap_;
    int k;
};
