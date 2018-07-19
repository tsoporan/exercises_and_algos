"""
Examples of Binary Search
"""


def binsearch(target, numbers):
    """
    Iteratively search for target in numbers
    """

    if not numbers:
        return False

    floor = -1
    ceil = len(numbers)

    while floor + 1 < ceil:
        half = (ceil - floor) // 2

        guess_index = floor + half

        guessed = numbers[guess_index]

        if guessed == target:
            return True

        if guessed < target:
            floor = guess_index
        else:
            ceil = guess_index

    return False


if __name__ == '__main__':
    assert binsearch(3, [1, 3, 8, 10, 20]) is True
    assert binsearch(2, [1, 3, 8, 10, 20]) is False
    assert binsearch(3, []) is False
    assert binsearch(1.5, [0.5, 1.5, 2]) is True
