#!/usr/bin/python3
""" Module for the task 0 """


def minOperations(n):
    """ method that calculates the fewest number of operations
    to result in exactly n H characters in the file """
    if not n or not isinstance(n, int) or n <= 1:
        return 0
    i = 0
    string = "H"
    while (len(string) != n):
        if ((n % len(string)) == 0):
            string_cpy = string
            i += 1
        string = string + string_cpy
        i += 1
    return i + 1
