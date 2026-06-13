class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        counter = Counter()

        for i in range(len(s1)):
            counter[s1[i]] += 1
            counter[s2[i]] -= 1

        diff = 0
        for k,v in counter.items():
            if v != 0:
                print("character " + k + " count is different")
                diff += 1
        
        l,r = 0,len(s1) - 1
        while r < len(s2) - 1:
            print(diff)
            if diff == 0:
                return True

            if counter[s2[l]] == 0:
                diff += 1
            counter[s2[l]] += 1
            print(s2[l] + " is moved out")
            if counter[s2[l]] == 0:
                diff -= 1

            l += 1
            r += 1
            if counter[s2[r]] == 0:
                diff += 1
            counter[s2[r]] -= 1
            print(s2[r] + " is moved in")
            if counter[s2[r]] == 0:
                diff -= 1
            print(s2[l:r+1])
        return diff == 0