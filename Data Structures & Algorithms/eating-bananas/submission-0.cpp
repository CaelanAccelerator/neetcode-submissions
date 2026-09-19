class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // upper is the max, lower is the celi(sum/h)
        int sum = 0;
        int maxi = 0;
        for(auto& pile: piles){
            sum += pile;
            maxi = max(maxi,pile);
        }
        int min = (sum - 1)/h + 1;
        
        int mid = (min + maxi)/2;
        

        return findMid(piles,h,maxi,min);
    }

    

    int findMid(vector<int>& piles, int h,int max, int min){
        if(max == min)return max;
        int mid = (max + min)/2;

        if(tryFinish(piles,h,mid) == true){
            return findMid(piles,h,mid,min);
        }else{
            return findMid(piles,h,max,mid + 1);
        }
    }

    bool tryFinish(vector<int>& piles, int h, int k){

        for(auto p : piles){
            h -= (p-1)/k + 1;
        }
        return h >= 0;
    }
};
