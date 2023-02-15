#!/usr/bin/python3
""" Module for validate utf-8 """


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding """
    for d in data:
        if not isinstance(d, int):
            return False
    try:
        bytes(data)
        return True
    except ValueError:
        return False
