// Linear Search JavaScript Version: searches for a
// specific item in an array and returns the index of the item.

function linearSearch(arr, x) {
  // Loop through the array
  for (let i = 0; i < arr.length; i++) {
    // Checks if the item in the array = search item.
    // If yes, return the index. If not, move to next item.
    if (arr[i] === x) {
      return i;
    }
  }
  // After looping if the search item is not found, return -1.
  return -1;
}

// Log to the console and have fun!
console.log(linearSearch([2, 5, 8], 5));
console.log(linearSearch([2, 6, 9, 15], 2));
console.log(linearSearch([2, 3, 4, 10], 8));
