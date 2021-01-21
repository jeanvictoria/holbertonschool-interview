#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    rotates 2D Matrix 90 degrees
    :param matrix: n X n 2D Matrix
    :return: nothing
    """
    lenMat = len(matrix)

    for r in range(lenMat + lenMat % 2 - 2):
        for c in range(r, lenMat - r - 1):
            tempMatrix = matrix[r][c]
            # rotation of matrix r = rows and c = columns
            # rotate to the right
            matrix[r][c] = matrix[lenMat - c - 1][r]
            matrix[lenMat - c - 1][r] = matrix[lenMat - r - 1][lenMat - c - 1]
            matrix[lenMat - r - 1][lenMat - c - 1] = matrix[c][lenMat - r - 1]
            matrix[c][lenMat - r - 1] = tempMatrix
    if len(matrix) == 2:
        tempMatrix = matrix[0][0]
        matrix[0][0] = matrix[1][0]
        matrix[1][0] = matrix[1][1]
        matrix[1][1] = matrix[0][1]
        matrix[0][1] = tempMatrix
