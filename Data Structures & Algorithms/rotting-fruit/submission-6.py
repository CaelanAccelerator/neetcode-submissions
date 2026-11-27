class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        dq = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    dq.append((i,j))
        
        round = -1
        while dq:
            for _ in range(len(dq)):
                x, y = dq.popleft()
                if grid[x][y] == 0:
                    continue
                for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                    r = x + dx
                    c = y + dy
                    if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] == 1:
                        dq.append((r, c))
                        grid[r][c] = 2
            round += 1

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1
        
        return max(0,round)
                