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
  var current = this.head;
  while (current.next) {
    console.log('-- Node', current.val);
    current = current.next;
  }
  console.log('-- Node', current.val);
}

var list = new LinkedList();

list.push(5);
list.push(6);
list.push(3);
list.push(2);
list.push(1);

list.print();
