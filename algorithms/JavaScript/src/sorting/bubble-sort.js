// Bubble Sorting JavaScript Version

function bubbleSort(arr) {
  // Copy the contents of the input array and store them as a separate variable
  const sorted = [...arr];

  // Loop through the copied array
  for (let i = 0; i < sorted.length; i++) {
    // Checks if an item in the array is
    // greater than the item next to it (index + 1)
    if (sorted[i] > sorted[i + 1]) {
      // If yes, swap them
      sorted.splice(i, 2, sorted[i + 1], sorted[i]);
    }
  }
  // Finally return the sorted array
  return sorted;
}

// Log to the console and have fun
console.log(bubbleSort([23, 34, 25, 12, 54, 11]));
