class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        ans = 0

        def bfs(i,j):
            if (i,j) in visited or grid[i][j] == "0":
                return 0
            dq = deque()
            dq.append((i,j))
            while dq:
                x, y = dq.popleft()
                if (x,y) in visited:
                    continue
                if 0 <= x < len(grid) and 0 <= y < len(grid[0]):
                    visited.add((x,y))
                    if grid[x][y] == "0":
                        continue
                    for dx, dy in ((1,0), (-1,0), (0,1), (0, -1)):
                        dq.append((x + dx, y + dy))
            return 1

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                temp = bfs(i,j)
                ans += temp

        return ans

