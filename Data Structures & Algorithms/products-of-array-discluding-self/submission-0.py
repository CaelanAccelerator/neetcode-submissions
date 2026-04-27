class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        suffix = nums.copy()
        prefix = nums
        
        pre = 1
        for i in range(len(prefix)):
            temp = prefix[i]
            prefix[i] = pre
            pre = temp * pre
            print(temp)
            print(pre)
            print("num ", prefix[i])
        print(prefix)

        suf = 1
        for i in range(len(suffix) - 1, -1, -1):
            temp = suffix[i]
            suffix[i] = suf
            suf = temp * suf
        print(suffix)

        for i in range(0, len(prefix), 1):
            prefix[i] = prefix[i] * suffix[i]
        
        return prefix