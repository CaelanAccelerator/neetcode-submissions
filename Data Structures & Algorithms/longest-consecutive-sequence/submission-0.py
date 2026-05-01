class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        longest, length = 0,1
        for elem in nums:
            if elem - 1 not in s:
                length = 1
                while length + elem in s:
                    length += 1
                longest = max(longest, length)
        return longest
                
