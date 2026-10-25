class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = [0]*26
        for t in tasks:
            count[ord(t) - ord('A')] += 1
        count.sort()

        idle = (count[25] - 1) * n
        for i in range(24, -1, -1):
            idle -= min(count[i],count[25] - 1)

        return max(len(tasks) + idle, len(tasks))
