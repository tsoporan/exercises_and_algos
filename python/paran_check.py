"""
Check if the string has balanced parantheses.

ex. ( how are ( you ) doing )  = True
    how ( are you ) ) doing )  = False
    { [ how ( are ) ] you  }   = True
"""

def check_parantheses(s):
    """
    Count approach.
    """
    count = 0

    for char in s:
        if char == '(':
            count += 1
        if char == ')':
            count -= 1

    if count == 0:
        return True
    return False

def check_stack_parantheses(s):
    """
    Stack approach.
    """
    stack = []

    for char in s:
        if char == '(':
            stack.append('(')
        if char == ')':
            if len(stack):
                stack.pop()
            else:
                return False

    if len(stack) == 0:
        return True
    return False

def check_multi_parantheses(s):
    """
    Multiple parantheses stack approach.
    """
    stack = []
    last = ''

    for c in s:
        if c in ['(', '[', '{']:
            stack.append(c)

        if len(stack):
            last = stack[-1]

        if c in [')', ']', '}']:
            if len(stack) == 0:
                return False

            if c == ')' and last == '(':
                stack.pop()
            elif c == ']' and last == '[':
                stack.pop()
            elif c == '}' and last == '{':
                stack.pop()

    if not stack:
        return True

    return False


if __name__ == '__main__':
    print check_parantheses('( how are ( you ) doing )') == True #True
    print check_parantheses('( how are) ( you ) doing )') == False# False
    print check_parantheses('(())') == True #True
    print check_parantheses('()))') == False #False

    check_parantheses = check_multi_parantheses

    print check_parantheses('({[]})') == True#True
    print check_parantheses('{()}') == True #True
    print check_parantheses('[]()') == True  #True
    print check_parantheses('{[]()}') == True #True
    print check_parantheses('[]()}') == False #False
    print check_parantheses('[(])') == False #False
    print check_parantheses('({[])') == False #False
    print check_parantheses('{()') == False #False
    print check_parantheses('{(){') == False#False
    print check_parantheses('(])[(])([)') == False #False
