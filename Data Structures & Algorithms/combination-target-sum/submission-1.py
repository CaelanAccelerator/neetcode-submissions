class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        choice = []

        def dfs(i, s):
            if s > target or i >= len(nums):
                return
            if s == target:
                ans.append(choice.copy())
                return
            choice.append(nums[i])
            dfs(i, s + nums[i])
            choice.pop()
            dfs(i + 1, s)

        dfs(0,0)
        return ans
            
        