"""
Determine which word has the greatest number of repeated letters.

ex. "This is bestest day ever!" returns "bestest" as it has: 2 e's, 2 s' and 2 t's while "ever" only has 2 e's.

Notes:
    -order matters in the case where there is more than 1 word with the same amount of repeated letters first one
    takes precedence.

"""

def letter_count(s):

    split_str = s.split(' ')

    word_counts = []

    if split_str:
        for word in split_str:

            letters = []
            repeated = 0

            for char in word:
                if char in letters:
                    repeated += 1
                else:
                    letters.append(char)

            word_counts.append((word, repeated))

        highest = 0
        current_word  = ''

        for word, count in word_counts:
            if count > highest:
                highest = count
                current_word = word

        if highest == 0:
            return -1

        return current_word
    return -1

print(letter_count("This is the bestest day ever!") == 'bestest')
print(letter_count("Today, is the greatest day ever!") == 'greatest')
print(letter_count("greet ever soop") == 'greet')
print(letter_count("greet ever sooop") == 'sooop')
print(letter_count("greet ever soopp") == 'soopp')
print(letter_count('abc') == -1)
print(letter_count('') == -1)
