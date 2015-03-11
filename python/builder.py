"""
Builder pattern in Python.

Good for avoiding the use of many constructors when creating objects with many parameter combinatons.

Example: A car with various options, the options can be composed and returned as one final Car instead 
of multiple car constructors for each option.
"""

class Builder(object):
    def task(self):
        raise NotImplementedError()

class Builder1(Builder):
    def __init__(self):
        self.btype = 1

    def task(self):
        return 'Builder 1 running'

class Builder2(Builder):
    def __init__(self):
        self.btype = 2

    def task(self):
        return 'Builder 2 running'

class Director(object):
    def createBuilder(self, btype):

        self.btype = btype

        builder = None

        if btype == 1:
            builder = Builder1()
        else:
            builder = Builder2()

        print(builder.task())

        return builder

if __name__ == '__main__':

    director = Director();
    builder = director.createBuilder(1);

    assert builder.btype == 1

    print("builder", builder)
