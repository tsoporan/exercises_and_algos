"""
An example of the Observer pattern in Python.

A Subject keeps track of its observers and has a method of notifying them.
"""


class Subject(object):
  def __init__(self):
    self.observers = []	
	
  def register_observer(self, observer):
     self.observers.append(observer)

  def unregister_observer(self, observer):
     self.observers.remove(observer)

  def notify_observers(self, *args, **kwargs):
     for obs in self.observers:
       obs.notify(*args, **kwargs)
	

class Observer(object):

   def __init__(self, name):
     self.name = name

   def notify(self, *args, **kwargs):
     print("Called with args: %s %s" % (args, kwargs)) 	

   def __repr__(self):
     return 'Observer: %s' % self.name
	
if __name__ == '__main__':
  sub = Subject()
  obs1 = Observer('1');
  obs2 = Observer('2');
  obs3 = Observer('3');

  sub.register_observer(obs1)
  sub.register_observer(obs2)

  print(sub.observers, len(sub.observers) == 2)

  sub.unregister_observer(obs2)

  print(sub.observers, len(sub.observers) == 1)

  sub.register_observer(obs3)

  sub.notify_observers('notifying!')
