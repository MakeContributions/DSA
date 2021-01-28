
/* In this We will learn how to search for an item in Sorted array using Binary Search .*/

function binarySearch( arr , item ){
 let low = 0 ; // First Pointer 
 let high = arr.length - 1  ; // Second Pointer 
 while(low <= high)          // Loop Until low is less than high
 {
    let mid =  parseInt(( low + high )/2) ;  // calculate Mid
    if( arr[mid] < item )       
    {
      low = mid + 1 ;  // Ignore Left Half i.e. items before middle element .
    }
    else if( arr[mid] > item )
    {
      high = mid - 1 ; // Ignore Right Half i.e. items after middle element .
    }
    else {
      return mid ;    // Item Found 
    }
 }
return -1 ; // If item is not Found 
}
