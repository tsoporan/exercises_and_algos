// Palindrome checker in javascript, of course you could always turn to list reverse and join.

function palindrome(str) {

  // If reversed string is the same as input string, this is a palindrome.
  var rev = '', c;

  for (var i = str.length - 1; i >= 0; i--) {
    c = str[i];
    rev += c;
  }

  return str === rev;

}

console.log(palindrome('abba') === true);
console.log(palindrome('bob')  === true);
console.log(palindrome('abac') === false);
console.log(palindrome('word') === false);
