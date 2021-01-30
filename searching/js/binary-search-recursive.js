//Recursive Method

/*Arguments to Function 

arr - array ( Sorted Only )
low - lower index of array (0)
high - max index of array  (length of array - 1 )
item = Element to be searched .

*/

function binary_recurrence(arr, low, high, item) {
 // Base Case for the termination of Recursion
 
 if(low > high) { 
   return -1 ; //Item is not present in the Array 
  } 
 
 // Calculating Mid Index 
 let mid = Math.floor((low+high)/2) ;

 //Equation Middle Element with the item to be searched 

 if(arr[mid] == item ){  

 // Middle Element equal to the Item 
 // We found Element at the mid Index
 return mid ;

 }
 else if( arr[mid] > item ){
 
 // Item is less than the middle Element 
 // Ignore the Right Half , as right half contains elements greater than middle element and so item too .
 // Make a recursive call to the left Half 
 
 return binary_recurrence(arr,low,mid-1,item); 
 }
 else {
 //Item is greater than the middle Element 
 //Ignore the Left Half ,as left half contains element less than middle element and so item too .
 //Make recursive call to the right Half 
 
 return binary_recurrence(arr,mid+1,high,item);
 
 }

}

console.log(binary_recurrence([1,3,5,7,8,9], 0, 5, 7)); //returns 3 , Found at Index 3 

console.log(binary_recurrence([1,3,5,7,8,9], 0, 5, 10)); //returns -1 , 10 is not present in array
