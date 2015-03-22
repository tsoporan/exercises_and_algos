// Playing around with new es6 generators.
// Use: node --harmony es6-yield.js to run.


function* multiYield(n) {

  // Whenever there is a yield, think of it as a pause
  // yields can output, calling generator next can input into the yield

  var a = n * (yield (n + 1));

  var b = yield(10);

  return a + b;
}

var gen = multiYield(5);

var first = gen.next()
console.log('first', first);
console.log(first.value == 6);

var second = gen.next(20);
console.log('second', second);
console.log(second.value == 10);

var third = gen.next(5);
console.log(third);

// After the last yield, we return the value!
// At this point a = 100, b = 5, a+b = 105
console.log(third.value == 105 );
