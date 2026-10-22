class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        m = {}
        for num in nums:
            if num not in m:
                m[num] = 1
            else:
                return True
        return False
