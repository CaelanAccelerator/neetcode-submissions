class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l,r = 0,0
        ls = [0] * 26
        ans = 0
        while r < len(s):
            ls[ord(s[r]) - ord('A')]+=1
            while r - l + 1 - max(ls)> k:
                ls[ord(s[l]) - ord('A')]-=1
                l+=1
            ans = max(ans, r-l+1)
            print(r,l)
            r+=1
        return ans