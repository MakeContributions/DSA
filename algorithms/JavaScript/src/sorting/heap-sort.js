function heapSort(arr){
    let arrayLength = arr.length;

    // make a max heap
    for (let index = Math.floor(arrayLength / 2)  - 1; index > -1; index--) {
        heapify(arr,arrayLength,index);
    }

    // put largest element begining of the array and extract it
    for (let index = arrayLength  - 1; index >= 0; index--) {
        let temp = arr[index];
        arr[index] = arr[0];
        arr[0] = temp;

        heapify(arr,index,0); // make max heap from rest of the array
    }

    return arr;
}

// making max heap function
function heapify(arr,arrayLength,index){
    let largest = index;
        left = 2 * index + 1;
        right = 2 * index + 2;
        needToSwap = false; 

    // if right is exist and it is bigger than root
    // make largest as right
    if(right < arrayLength && arr[largest] < arr[right]){
        largest = right;
        needToSwap = true;
    }

    // if left is exist and it is bigger than root
    // make largest as left
    if(left < arrayLength && arr[largest] < arr[left]){
        largest = left;
        needToSwap = true;
    }

    // swap
    if(needToSwap){
        let i = arr[index];
        arr[index] = arr[largest];
        arr[largest] = i;
        heapify(arr,arrayLength,largest);
    }
}

console.log(heapSort([100,99,999,1000,499,800,89,88,87,86,85,84,83,82,81,998,878,498,398,789,198,298,397,599,988]));