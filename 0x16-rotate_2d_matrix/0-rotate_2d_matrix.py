#!/usr/bin/python3
""" Module function """

def rotate_2d_matrix(matrix):
    """ Rotate the matrix by 90 degrees clockwise """
    length = len(matrix)
    for i in range(length):
        for j in range(i + 1, length):
            tmp = matrix[i][j]
            print("swap: {} et {}".format(matrix[i][j], matrix[j][i]))
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = tmp

    for row in matrix:
        row.reverse()
