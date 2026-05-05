class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        lMin = prices[0]
        for i in range(len(prices)):
            res = max(prices[i] - lMin, res)
            lMin = min(lMin, prices[i])
        return res