"""
How many removals to keep consecutive letters different.

ex. AAAA -> 3
    ABA  -> 0
    A    -> 0
    ABBA -> 1
    AAABBB -> 4
"""

def toRemove(word):

    prev = ''
    remove = 0

    for char in word:
        if char == prev:
            remove += 1

        prev = char

    return remove

if __name__ == '__main__':
    print(toRemove('AAAA') == 3)
    print(toRemove('ABA') == 0)
    print(toRemove('A') == 0)
    print(toRemove('AAABBB') == 4)
