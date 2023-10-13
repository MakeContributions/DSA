const countingSortNegative = (arr, n, place) => {
    let max = Math.max(...arr);
    let min = Math.min(...arr);
    let range = max - min + 1;
    let count = new Array(range).fill(0);
    let output = new Array(n).fill(0);
    
    //Store the frequency
    for (let i = 0; i < n; i++) {
      const num = Math.floor(arr[i] / place) % 10;
      count[num - min]++; 
    } 
   
    //Accumulate the frequency
    for (let i = 1; i < count.length; i++) { 
      count[i] += count[i - 1]; 
    } 
    
    //Sort based on frequency
    for (let i = n - 1; i >= 0; i--) { 
      const num = Math.floor(arr[i] / place) % 10;
      output[count[num - min] - 1] = arr[i]; 
      count[num - min]--; 
    } 
    
    //Copy the output array
    for (let i = 0; i < n; i++){
      arr[i] = output[i];
    }
  }
  
  const radixSort = (arr, size = arr.length) => {
    //Get the max element
    let max = Math.max(...arr);
    
    //Sort the array using counting sort
    for(let i = 1; parseInt(max / i) > 0; i *= 10){
      countingSortNegative(arr, size, i);
    }
  }
  
  const arr = [121, -432, 564, 23, -1, 45, 788];
  radixSort(arr);
  console.log(arr);