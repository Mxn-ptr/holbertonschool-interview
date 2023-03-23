#!/usr/bin/python3
"""The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard.
Write a program that solves the N queens problem."""
import sys


def nqueens(n):
    """ Solve the problem """
    col, pos, neg = set(), set(), set()
    board = [["0"] * n for i in range(n)]

    def backtrap(row):
        if n == row:
            solution = []
            for i in range(n):
                for j in range(n):
                    if board[i][j] == "1":
                        solution.append([i, j])
            print(solution)
            solution = []
            return
        for c in range(n):
            if c in col or (row+c) in pos or (row-c) in neg:
                continue
            col.add(c)
            pos.add(row+c)
            neg.add(row-c)
            board[row][c] = "1"
            backtrap(row + 1)
            col.remove(c)
            pos.remove(row+c)
            neg.remove(row-c)
            board[row][c] = "0"

    backtrap(0)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)

    if (not isinstance(n, int)):
        print("N must be a number")
        exit(1)

    if (n < 4):
        print("N must be at least 4")
        exit(1)
    nqueens(n)
