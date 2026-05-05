class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l,r = i+1, len(nums) - 1
            while(l < r):
                tsum = nums[i] + nums[l] + nums[r]
                if tsum > 0:
                    r -= 1
                elif tsum < 0:
                    l += 1
                else:
                    triplet = [nums[i],nums[l],nums[r]]
                    res.append(triplet)
                    l += 1
                    r -= 1
                    while l < r and nums[r] == nums[r+1]:
                        r -= 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                    
        return res