//majority element in array (defined as element present > size/2)
//approach : moore's voting algorithm
//Time Complexity: O(n). 
//Auxiliary Space: O(1)
 
 function candelem(arr, size) // finds candidiate element from the array
 {
     let maj_index = 0, count = 1;
     let i;
     for (i = 1; i < size; i++) {
         if (arr[maj_index] == arr[i])
             count++;
         else
             count--;

         if (count == 0) {
             maj_index = i;
             count = 1;
         }
     }
     return arr[maj_index];
 }


 function isMaj(arr, size, cand) // to check if the candidate element is really the majority element
 {
     let i, count = 0;
     for (i = 0; i < size; i++) {
         if (arr[i] == cand)
             count++;
     }
     if (count > parseInt(size / 2, 10))
         return true;
     else
         return false;
 }

 function Majority(arr, size)
 {
     
     var cand = candelem(arr, size);

    
     if (isMajority(arr, size, cand))
         console.log(" " + cand + " ");
     else
         console.log("No Majority Element");
 }

  
 var arr = [ 5, 3, 1,5, 5, 2 ]; // array to find majority element
 var size = a.length;

Majority(a, size);

 
