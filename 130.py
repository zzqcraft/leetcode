class Solution:
    def captured(self, board: List[List[str]], x: int, y :int) -> None:
        
        if board[x][y] != 'O':
            return
    
        board[x][y] = 'C'
        
        if x > 0:
            self.captured(board, x - 1, y)
        if y > 0:
            self.captured(board, x, y - 1)
        if x + 1 < len(board):
            self.captured(board, x + 1, y)
        if y + 1 < len(board[0]):
            self.captured(board, x, y + 1)            
            
        
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        for i in range(len(board)):
            for j in [0, len(board[0]) - 1]:
                if board[i][j] == 'O':
                    self.captured(board, i, j)
        
        for j in range(len(board[0])):
            for i in [0, len(board) - 1]:
                if board[i][j] == 'O':
                    self.captured(board, i, j)
        
        for i in range(len(board)):
            for j in range(len(board[0])): 
                if board[i][j] == 'C':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
