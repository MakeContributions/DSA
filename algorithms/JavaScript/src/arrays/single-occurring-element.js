// Problem: Given an array of integers,
// every element appears twice except for one. Find that single one.
// Space Complexity: O(1)
// Time Complexity: O(n)

function singleOccurringElement(arr) {
  let result = 0;
  for (const el of arr) {
    result ^= el;
  }
  return result;
}

const arr = [2, 5, 7, 3, 1, 8, 8, 9, 4, 2, 7, 1, 4, 9, 5];
console.log(singleOccurringElement(arr));

// Input: [2, 5, 7, 3, 1, 8, 8, 9, 4, 2, 7, 1, 4, 9, 5]
// Output: 3
