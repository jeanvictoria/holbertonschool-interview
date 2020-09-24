#!/usr/bin/python3
"""validUTF8"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    :param data:
    :return: True if data is a valid UTF-8 encoding, else return False
    """

    byte = 0
    for n in data:
        mask = 1 << 7
        if not byte:
            while mask & n:
                byte += 1
                mask >>= 1
            if not byte:
                continue
            if byte == 1 or byte > 4:
                return False
        else:
            if n >> 6 != 0b10:
                return False
        byte -= 1
    return byte == 0
