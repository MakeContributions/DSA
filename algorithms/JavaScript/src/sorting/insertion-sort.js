function insertionSort(array) {
  // start with index 1 because only one element is already sorted
  for (let i = 1; i < array.length; i++) {
    const key = array[i];
    let j = i - 1;
    // decrement j until array[j] is not less or equal to key
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
  return array;
}

// output : [1,2,3,4,4,5,6,7,8,10]
console.log(insertionSort([4, 5, 6, 7, 8, 10, 1, 2, 3, 4]));
