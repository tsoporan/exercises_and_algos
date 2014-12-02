""" Caesar ciper: http://en.wikipedia.org/wiki/Caesar_cipher"""

import string

lower = string.lowercase

def caesar_shift(s, n, mod=26):
    """ Shift chars in s by n. """

    out = ''

    for c in s:
        idx = ((lower.index(c) + n) % mod)
        out += lower[idx]

    return out

print(caesar_shift('abc', 3) == 'def')
print(caesar_shift('abc', 23) == 'xyz')
