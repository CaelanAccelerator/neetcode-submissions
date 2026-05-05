class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,j = 0,0
        dc = defaultdict(int)
        maxLen = 0
        while j < len(s):    
            while dc[s[j]] > 0:
                dc[s[i]] -= 1
                i += 1
            maxLen = max(maxLen, j - i + 1)
            dc[s[j]] += 1
            j += 1
        
        return maxLen
            