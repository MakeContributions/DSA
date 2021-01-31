function selectionSort(array) {

    // loop through all elements except last in array
    for(let i=0;i<array.length - 1;i++) {
        let min_index = i;

        // find minimum element index in unsorted array
        for(let j=i+1;j<array.length;j++) {
            if(array[j] < array[i]) {
                min_index = j;
            }

            // swap with element at minimum index
            let temp = array[min_index];
            array[min_index] = array[i];
            array[i] = temp;
        }
    }

    // return sorted array
    return array;
}

// test
console.log(selectionSort([9,8,7,6,5,4,3,2,1,0]))
