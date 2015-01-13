"""
Utopian tree goes through 2 cycles of growth a YEAR.

First cycle in spring: doubles in height

Second cycle in summer: height increases by 1

Tree is planted onset of spring with height 1.

Find the height of tree after N growth cycles.
"""

def growthAfterCycles(lst):
    out = []

    for cycle in lst:
        height = 1

        if cycle == 0:
            out.append(height)
        else:
            for run in range(cycle):
                if run % 2 == 0:
                    height += height
                else:
                    height += 1

            out.append(height)
    return out

if __name__ == '__main__':
    r1, r2, r3, r4 = growthAfterCycles([3,4,0,1])

    print(r1 == 6)
    print(r2 == 7)
    print(r3 == 1)
    print(r4 == 2)
