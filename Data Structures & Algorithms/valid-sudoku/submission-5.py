class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        for i in range(len(board)):
            s = set()
            for j in range(len(board)):
                num = board[i][j]
                if num == ".":
                    continue
                if num in s:
                    return False
                s.add(num)
        
        for i in range(len(board)):
            s = set()
            for j in range(len(board)):
                num = board[j][i]
                if num == ".":
                    continue
                if num in s:
                    return False
                s.add(num)

        for i in range(0,9,3):
            for j in range(0,9,3):
                s = set()
                for r in range(i, i+3, 1):
                    for c in range(j, j+3, 1):
                        num = board[r][c]
                        if num == ".":
                            continue
                        if num in s:
                            return False
                        s.add(num)
        return True
