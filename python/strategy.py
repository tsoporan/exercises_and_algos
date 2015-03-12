"""
Strategy pattern in Python.

Useful for when you want to select behaviour at run-time. 
"""

# Concrete classes should implement this "interface"
class Strategy(object):
    def run(self, a, b):
        raise NotImplementedError()

# "Tasks" implement the interface.
class TaskA(Strategy):
    def run(self, a, b):
        print("Running task A with", a, b)

class TaskB(Strategy):
    def run(self, a, b):
        print("Running task B with", a, b)

class TaskC(Strategy):
    def run(self, a, b):
        print("Running task C with", a, b)

# Context holds the current strategy and knows how to execute it.
class Context(object):
    def __init__(self, strategy):
        self.strategy = strategy

    def execute_strategy(self, a, b):
        self.strategy.run(a, b)


if __name__ == '__main__':
    context = Context(TaskA());
    print(context.execute_strategy(3, 4))
    
    context = Context(TaskB());
    print(context.execute_strategy('a', 'b'))
    
    context = Context(TaskC());
    print(context.execute_strategy(1.6, 3.14))
