/*
* In this We will learn how to search for an item in
* Sorted array using Binary Search.
*/

function binarySearch(item, arr) {
  let first = 0; // left endpoint or index of first array element
  let last = arr.length - 1; // right endpoint or index of last array element .

  while (first <= last) {
    const middle = Math.floor((first + last) / 2);
    if (arr[middle] == item) {
      // If the element is present at the middle itself
      return middle;
    } else if (arr[middle] > item) {
      // Ignore Right Half i.e. items after middle element .
      last = middle - 1;
    } else {
      // Ignore Right Half i.e. items after middle element .
      first = middle + 1;
    }
  }
  return -1; // Item is not present in Array .
}

// expected output = 1
console.log(binarySearch(6, [2, 6, 8]));
// expected output = 2
console.log(binarySearch(10, [2, 3, 10, 14]));
// expected output = -1
console.log(binarySearch(1, [2, 6, 8]));
