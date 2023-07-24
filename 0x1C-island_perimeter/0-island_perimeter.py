#!/usr/bin/python3
"""
Island perimeter module
"""


def island_perimeter(grid):
    """ Return the perimeter of the island:
        - 0 is water
        - 1 is land
    """
    perimeter = 0
    for i in range(0, len(grid)):
        for j in range(0, len(grid[i])):
            if grid[i][j] == 1:
                if (i + 1 > len(grid) - 1):
                    perimeter += 1
                elif (grid[i + 1][j] == 0):
                    perimeter += 1
            
            if grid[i][j] == 1:
                if (i - 1 < 0):
                    perimeter += 1
                elif (grid[i - 1][j] == 0):
                    perimeter += 1
            
            if grid[i][j] == 1:
                if (j + 1 > len(grid[i]) - 1):
                    perimeter += 1
                elif (grid[i][j + 1] == 0):
                    perimeter += 1
            
            if grid[i][j] == 1:
                if (j - 1< 0):
                    perimeter += 1
                elif grid[i][j - 1] == 0:
                    perimeter += 1
    return perimeter
