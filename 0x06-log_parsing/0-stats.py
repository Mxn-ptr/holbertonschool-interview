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
            split_line = line.split()
            size = int(split_line[-1])
            status = int(split_line[-2])
            count += 1
            if status in codes.keys():
                total_size += size
                codes[status] += 1

            if count % 10 == 0:
                print_line()
    except KeyboardInterrupt:
        print_line()
    print_line()
