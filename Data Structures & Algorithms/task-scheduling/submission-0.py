class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        ls = [0] * 26
        for t in tasks:
            ls[ord(t) - ord('A')]+=1
        ls.sort()
        maxf = ls[25]
        idle = (maxf - 1) * n
        for i in range(24,-1,-1):
            idle -= min(maxf - 1, ls[i])
        return max(0,idle) + len(tasks)

