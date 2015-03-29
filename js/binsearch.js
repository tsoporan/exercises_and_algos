// Example binary search.


var search = function(list, value) {
  var min = 0;
  var max = list.length - 1;
  var mid;

  while(min <= max) {
    mid = Math.floor((max+min) / 2);

    if (list[mid] === value) {
      return mid;
    } else if (list[mid] < value) {
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }
  return -1;
}


var list = [1,2,3,4,5,6];
var value = 1;

console.log("Searching for " + value);
console.log("Found at index", search(list, value));

value = 4;

console.log("Searching for " + value);
console.log("Found at index", search(list, value));

value = 7;

console.log("Searching for " + value);
console.log("Found at index", search(list, value));


