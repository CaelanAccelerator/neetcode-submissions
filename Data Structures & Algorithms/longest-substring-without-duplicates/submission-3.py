class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,j = 0,0
        dc = defaultdict(int)
        maxLen = 0
        while j < len(s):    
            if s[j] in dc:
                i = max(dc[s[j]] + 1, i)
            maxLen = max(maxLen, j - i + 1)
            dc[s[j]] = j
            j += 1
        
        return maxLen
            