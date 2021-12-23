function selectionSort(array) {
  // loop through all elements except last in array
  for (let i = 0; i < array.length - 1; i++) {
    let minIndex = i;

    // find minimum element index in unsorted array
    for (let j = i + 1; j < array.length; j++) {
      if (array[j] < array[i]) {
        minIndex = j;
      }
    }
    // swap with element at minimum index
    const temp = array[minIndex];
    array[minIndex] = array[i];
    array[i] = temp;
  }

  // return sorted array
  return array;
}

// test
console.log(selectionSort([9, 8, 7, 6, 5, 4, 3, 2, 1, 0]));
