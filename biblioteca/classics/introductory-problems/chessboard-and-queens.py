count = 0

def solve():
    board = []
    for _ in range(8):
        board.append(list(input()))

    eight_queens(0, board)

def in_board(i, j):
    return 0 <= i <= 7 and 0 <= j <= 7

def attacks_another_queen(i, j, board):
    for k in range(i+1):
        if board[k][j] == 'Q':
            return True

        if in_board(i-k, j-k) and board[i-k][j-k] == 'Q':
            return True

        if in_board(i-k, j+k) and board[i-k][j+k] == 'Q':
            return True

    return False

def eight_queens(i, board):
    global count

    if i == 8:
        count += 1
        return

    for j in range(8):
        if board[i][j] == '*':
            continue

        if attacks_another_queen(i, j, board):
            continue

        board[i][j] = 'Q'
        eight_queens(i+1, board)
        board[i][j] = '.'

solve()
print(count)
