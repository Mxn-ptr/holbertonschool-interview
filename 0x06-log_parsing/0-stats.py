#!/usr/bin/python3
""" Write a function to print some informations """
import sys


count = 0
total_size = 0
codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def print_line():
    """ Print some information """
    print("File size: {}".format(total_size))
    for code in sorted(codes.keys()):
        if codes[code] > 0:
            print("{}: {}".format(code, codes[code]))


if __name__ == '__main__':
    try:
        for line in sys.stdin:
            count += 1
            try:
                split_line = line.split()
                size = int(split_line[-1])
                total_size += size
                status = int(split_line[-2])
                codes[status] += 1
            except ValueError:
                pass

            if count % 10 == 0:
                print_line()
    except KeyboardInterrupt:
        print_line()
        raise
    print_line()
