function binarySearch(value, list) {
    let first = 0;    //left endpoint
    let last = list.length - 1;   //right endpoint
    let position = -1;  // After looping if the search item is not found, we will return -1
    let found = false;  // When item is found we set its value to true
    let middle;
 
    while (found === false && first <= last) {
        middle = Math.floor((first + last)/2);
        if (list[middle] == value) { // If the element is present at the middle itself
            found = true;
            position = middle;
        } else if (list[middle] > value) {  //if in lower half
            last = middle - 1;
        } else {  //in in upper half
            first = middle + 1;
        }
    }
    return position;
}

console.log(binarySearch(6,[2, 6, 8]));         //expected output = 1
console.log(binarySearch(10,[2, 3, 10, 14]));   //expected output = 2
console.log(binarySearch(1,[2, 6, 8]));         //expected output = -1