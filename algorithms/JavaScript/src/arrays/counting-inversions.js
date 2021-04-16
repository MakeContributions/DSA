// Algorithm Type: Divide & Conquer
// Time Complexity: O(n*log(n))

function countingSplit(arr, left, right) {
  let splitInversion = 0;
  let leftIndex = 0;
  let rightIndex = 0;
  const size = arr.length;
  const leftSize = left.length;
  const rightSize = right.length;
  for (let i = 0; i < size; i++) {
    if (leftIndex != leftSize && rightIndex != rightSize) {
      if (right[rightIndex] <= left[leftIndex]) {
        arr[i] = right[rightIndex];
        rightIndex++;
        splitInversion += leftSize - leftIndex;
      } else {
        arr[i] = left[leftIndex];
        leftIndex++;
      }
    } else if (leftIndex == leftSize) {
      arr[i] = right[rightIndex];
      rightIndex++;
    } else if (rightIndex == rightSize) {
      arr[i] = left[leftIndex];
      leftIndex++;
    }
  }
  return splitInversion;
}

function countingInversions(arr) {
  const size = arr.length;
  let result = 0;
  if (size !== 1) {
    const mid = parseInt(size / 2);
    const left = arr.slice(0, mid);
    const right = arr.slice(mid, size);
    const leftInversion = countingInversions(left);
    const rightInversion = countingInversions(right);
    const splitInversion = countingSplit(arr, left, right);
    result = leftInversion + rightInversion + splitInversion;
  }

  return result;
}


const arr = [8, 2, 1, 5, 7, 3, 9, 2, 0, 1];

console.log(countingInversions(arr));
