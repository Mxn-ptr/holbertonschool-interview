#!/usr/bin/python3
""" Module for validate utf-8 """


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding """
    number_bytes = 0

    for number in data:
        binary = format(number, '#010b')[-8:]

        if number_bytes == 0:
            for bit in binary:
                if bit == '0':
                    break
                number_bytes += 1

            if number_bytes == 0:
                continue

            if number_bytes == 1 or number_bytes > 4:
                return False

        else:
            if not (binary[0] == '1' and binary[1] == '0'):
                return False

        number_bytes -= 1

    return number_bytes == 0
