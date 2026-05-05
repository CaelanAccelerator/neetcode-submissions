class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i,j = 0,len(numbers) - 1
        while(i != j):
            tsum = numbers[i] + numbers[j]

            if tsum > target:
                j -= 1
                continue
            
            if tsum < target:
                i += 1
                continue
            
            return [i+1,j+1]
        return [i+1,j+1]
            
        
            