"""
Unsigned 32-bit ints, flip them.
"""

def flipBits(lst):
    mask = 0xFFFFFFFF

    out = []

    for i in lst:
        out.append(
            ~i & mask
        )

    return out

if __name__ == '__main__':
    lst = [
        2147483647,
        1,
        0
    ]
    results = flipBits(lst)

    print(results[0] == 2147483648)
    print(results[1] == 4294967294)
    print(results[2] == 4294967295)


