function reverseString(str) {
  if (str === '') { // base case
    return '';
  } else {
    return reverseString(str.substr(1)) + str.charAt(0);
  }
}

// example usage
console.log(reverseString('hello')); // outputs 'olleh'
