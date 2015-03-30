// Singly LinkedList example in JS.

var LinkedList = function() {
  this.head = null;
};

LinkedList.prototype.push = function(val) {

  // Attach first node.
  if (!this.head) {
    this.head = {
      val: val,
      next: null
    };
  }

  else {
    // Continue until we are the end and attach node.
    var current = this.head;
    while(current.next) {
      current = current.next;
    }

    // Attach to end.
    current.next = {
      val : val,
      next: null
    }
  }
}

LinkedList.prototype.print = function() {
  console.log('>> Printing LinkedList');
  var current = this.head;
  while (current.next) {
    console.log('-- Node', current.val);
    current = current.next;
  }
  console.log('-- Node', current.val);
}


LinkedList.prototype.remove = function(val) {
  // Removing constitutes of finding the target Node,
  // removing it and linking the previous node with the target next node (if exists)

  var current = this.head,
      prev;

  while(current.val !== val) {
    prev = current;
    current = current.next;
  }

  // Stopped at target.
  if (current.next) {
    prev.next = current.next;
  } else {
    prev.next = null;
  }

}

var list = new LinkedList();

list.push(5);
list.push(6);
list.push(3);
list.push(2);
list.push(1);

list.print();

list.remove(3);
list.print();

list.remove(1);
list.print();
