n = int(input("Enter the number of queens to be placed on an nxn chessboard: "))

def isSafe(board, row, col):
    """
    Check if it's safe to place a queen at a given position on the board.

    Args:
    - board (list): The chessboard represented as a 2D list.
    - row (int): The current row being considered.
    - col (int): The current column being considered.

    Returns:
    - bool: True if it's safe to place a queen, False otherwise.
    """
    # Check the row and column
    for i in range(col):
        if board[row][i] == 1 or board[i][col] == 1:
            return False
    
    # Check upper main diagonal
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1
    
    # Check lower secondary diagonal
    i = row
    j = col
    while i < n and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1
        
    # Check main diagonal
    i = row
    j = col
    while i < n and j < n:
        if board[i][j] == 1:
            return False
        i += 1
        j += 1
    
    # Check secondary diagonal
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1
 
    return True

def solve(board, col):
    """
    Solve the N-Queens problem using backtracking.

    Args:
    - board (list): The chessboard represented as a 2D list.
    - col (int): The current column being considered.

    Returns:
    - bool: True if a solution is found, False otherwise.
    """
    if col >= n:
        return True
    
    for i in range(n):
        if isSafe(board, i, col):
            board[i][col] = 1
            if solve(board, col + 1):
                return True
    
        board[i][col] = 0
    return False

def printsol(s, n):
    """
    Print the solution in a readable format.

    Args:
    - s (list): The chessboard with queens placed.
    - n (int): The size of the chessboard.
    """
    for i in range(n):
        for j in range(n):
            if s[i][j] == 1:
                print('Q', end=' ')  # 'Q' represents a queen
            else:
                print('.', end=' ')  # '.' represents an empty cell
        print('\n')

def final_solve():
    """
    Initialize the chessboard and solve the N-Queens problem.
    Print the solution if one exists, otherwise, print a message.
    """
    board = [[0 for i in range(n)] for j in range(n)]
    if solve(board, 0) == False:
        print("No solution exists")
    else:
        printsol(board, n)

# Call the final_solve function to execute the solution
final_solve()