class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        count = {}
        for c in s1:
            count[c] = 1 + count.get(c,0)
        
        l = 0
        for r in range(len(s2)):
            if s2[r] in count:
                count[s2[r]] -= 1

            if (r - l + 1) > len(s1):
                if s2[l] in count:
                    count[s2[l]] += 1
                l+=1
            ok = True
            for v in count.values():
                if v != 0:
                    ok = False
                    break
            if ok:
                return True
        return False
            
