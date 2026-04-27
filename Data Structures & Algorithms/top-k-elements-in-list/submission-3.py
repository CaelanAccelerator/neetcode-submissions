class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ls = [[] for i in range(len(nums) + 1)] 
        counter = defaultdict(int)
        for i in nums:
            counter[i]+=1
        for num, freq in counter.items():
            ls[freq].append(num)
        
        ans = []
        for i in range(len(ls) - 1,-1,-1):
            elems = ls[i]
            for elem in elems:
                ans.append(elem)
                if len(ans) == k:
                    return ans
        return ans

         