class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        for i in range(len(board)):
            dc = defaultdict(int)
            for j in range(len(board)):
                num = board[i][j]
                if num == ".":
                    continue
                if dc[num] == 1:
                    return False
                dc[num]+=1
        
        for i in range(len(board)):
            dc = defaultdict(int)
            for j in range(len(board)):
                num = board[j][i]
                if num == ".":
                    continue
                if dc[num] == 1:
                    return False
                dc[num]+=1
        return self.checkBox(board,0,0)

    def checkBox(self, board: List[List[str]], startR: int, startC: int):
        if startR > 6 or startC > 6:
            return True
        
        dc = defaultdict(int)
        for i in range(startR, startR+3, 1):
            for j in range(startC, startC+3, 1):
                num = board[i][j]
                if num == ".":
                    continue
                if dc[num] == 1:
                    return False
                dc[num]+=1
        return True and self.checkBox(board, startR+3, startC) and self.checkBox(board, startR, startC+3)

