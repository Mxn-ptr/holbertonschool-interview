#!/usr/bin/python3
""" Module for validate utf-8 """


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding """
    try:
        bytes(data)
        return True
    except ValueError:
        return False
