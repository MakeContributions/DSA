function count_split_inv(arr, left, right) {
  let split_inv, lidx, ridx;
  split_inv = ridx = lidx = 0;
  let size = arr.length;
  let lsize = left.length;
  let rsize = right.length;
  for (let i = 0; i < size; i++) {
    if (lidx != lsize && ridx != rsize) {
      if (right[ridx] <= left[lidx]) {
        arr[i] = right[ridx];
        ridx++;
        split_inv += lsize - lidx;
      } else {
        arr[i] = left[lidx];
        lidx++;
      }
    } else if (lidx == lsize) {
      arr[i] = right[ridx];
      ridx++;
    } else if (ridx == rsize) {
      arr[i] = left[lidx];
      lidx++;
    }
  }
  return split_inv;
}

function count_inversions(arr) {
  let size = arr.length;
  if (size == 1) {
    return 0;
  }
  let mid = parseInt(size / 2);
  let left = arr.slice(0, mid);
  let right = arr.slice(mid, size);
  let left_inv = count_inversions(left);
  let right_inv = count_inversions(right);
  let split_inv = count_split_inv(arr, left, right);

  return left_inv + right_inv + split_inv;
}

let fs = require("fs");
var arr = fs.readFileSync("inp.txt", "utf8").split("\n");
for (i in arr) {
  arr[i] = parseInt(arr[i]);
}

console.log(count_inversions(arr));
