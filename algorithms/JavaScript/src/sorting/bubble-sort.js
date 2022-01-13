// Bubble Sorting JavaScript Version

// Bubble sort is a sorting algorithm in which
// the largest element is moved or bubbled up
// to the end of the array in every iteration

function bubbleSort(arr) {
  // a variable to hold temporary value
  let temp;

  // a boolean flag to skip iterations if
  // the array gets sorted mid way, happens
  // in case of large almost sorted array
  // as shown in the second example call
  // to bubble sort.
  let isNoSwap;

  // the outer loop starts from one end
  // and we decrease the no. of iterations we have
  // to make as after every iteration, the array
  // starts getting sorted from the top end.
  for (let i = arr.length - 1; i > 0; i--) {
    isNoSwap = true;

    // we start the inner loop from 0 to i
    // as after ith index the elements are sorted
    for (let j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        isNoSwap = false;
      }
    }

    // if there hasn't been a swap
    // in the previous iteration
    // the array is sorted
    // so no point going on and on
    // skip the iterations and get out of loop.
    if (isNoSwap) {
      break;
    }
  }
  return arr;
}

// Log to the console and have fun
console.log(bubbleSort([23, 34, 25, 12, 54, 11]));

// example of almost sorted array
console.log(bubbleSort([8, 1, 2, 3, 4, 5, 6, 7]));
