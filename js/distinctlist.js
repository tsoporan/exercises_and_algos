// Given a list (arr) determine the total number of duplicates. [3,4,5,5,5,6] should output 2.

function distinctList(arr) {

  // Store as object keys to avoid duplicates.
  var obj = {}, distinctArr, item, idx, num;

  for (var i = 0; i < arr.length; i++) {
    num = arr[i];
    obj[num] = true;
  }

  // Keys are strings, convert back to numbers.
  distinctArr = Object.keys(obj).map(function(i) { return Number(i) });

  for (var i = 0; i < distinctArr.length; i++) {
    item = distinctArr[i];
    idx  = arr.indexOf(item);

    if (idx > -1) {
      arr.splice(idx, 1);
    }
  }

  return arr.length;

}

console.log(distinctList([3, 4, 5, 5, 5, 6]) === 2)
console.log(distinctList([3, 3, 4, 5, 5, 5, 6]) === 3)
console.log(distinctList([3, 4, 4, 5 , 5, 6, 6]) === 3)
console.log(distinctList([3, 3]) === 1)

