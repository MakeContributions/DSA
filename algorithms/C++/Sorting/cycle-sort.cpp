//                                                          ***Cycle Sort***
// This sorting algorithm is best suited for situations where memory write or swap operations are costly. 
// it is In-place and not stable 

#include<bits/stdc++.h> 
using namespace std; 

void cycleSort(int arr[], int size) 
{ 
    for(int cyclestart=0;cyclestart<size-1;cyclestart++){
        int item=arr[cyclestart];
        int pos=cyclestart;
        for(int i=cyclestart+1;i<size;i++)  //count total no of item less then curr item in an array
            if(arr[i]<item)               
                pos++;                
        swap(item,arr[pos]);   //swap item to it's correct position
        
        while(pos!=cyclestart){       // now we have to find the index of prev item which is presnt at pos and we keep doing this till pos!=cyclestart
            pos=cyclestart;
            for(int i=cyclestart+1;i<size;i++)
                if(arr[i]<item)
                    pos++;
            swap(item,arr[pos]);
        }
    }
} 
  
int main() 
{ 
    int arr[] = { 20,40,10,50,30 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    cycleSort(arr, size); 
   
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
        
    return 0; 
} 
/*
Time Complexity : O(n2) 
Worst Case : O(n2) 
Average Case: O(n2) 
Best Case : O(n2)

                                                           Explanation:-
														     
    
	int arr[] = { 20,40,10,50,30};
	int size= 5;
	
	  iteration 1:
	    cyclestart=0;
		item = 20;
		pos = 0;
		     for(int i=cyclestart+1;i<size;i++)           //count total no of item less then 20 in a array to find correct index of 20 in array 
                 if(arr[i]<item)
                     pos++; 
             pos=1                                       //index of 20 is 1(pos) in a array
	         swap(item,arr[pos]);                        //swap 20(item) with item present at index pos i.e 40.
	         
	         item=40;
	         pos=1;
	                                                     //Now we have to count item less then 40 in array and swap that item with updated pos
	              pos=3
		          swap(40,arr[3])                        // swap 40 with 50
		          
	         item=50;
	         pos=3                                       
			                                             //Now we have to count item less then 50 in array and swap that item with updated pos
			      pos=4
				  swap(50,arr[4])                        //swap 50 with 30  
				  
			 item=30;
			 pos=4;	                          
		                                                 //Now we have to count item less then 30 in array and swap that item with updated pos
		          pos=2;
				  swap(30,arr[2])                        //swap 30 with 10
				  
			 item=10;
			 pos=2;
			                                             //Now we have to count item less then 10 in array and swap that item with updated pos
			      pos=0;
				  swap(10,arr[0])                        //place 10 at 0index 
			
	pos=cyclestart while-loop terminate	
	
	Updated array after iterative 1 array = {10,20,30,40,50};
	
	
	iteration 2:
	        
	        cyclestart=1;
		    item = 20;
		    pos = 1;
		          for(int i=cyclestart+1;i<size;i++)         //count total no of item less then 20 in a array to find correct index of 20 in array 
                      if(arr[i]<item
                         pos++; 
            pos=1                                      
	        swap(item,arr[pos]); 
	pos=cyclestart while-loop terminate	
	
	iteration 3:
	        
	        cyclestart=2;
		    item = 30;
		    pos = 2;
		          for(int i=cyclestart+1;i<size;i++)           //count total no of item less then 30 in a array to find correct index of 20 in array 
                      if(arr[i]<item)
                         pos++; 
            pos=2                                      
	        swap(item,arr[pos]); 
	pos=cyclestart while-loop terminate	
	
	iteration 4:
	        
	        cyclestart=3;
		    item = 40;
		    pos = 3;
		          for(int i=cyclestart+1;i<size;i++)             //count total no of item less then 40 in a array to find correct index of 20 in array 
                      if(arr[i]<item)
                         pos++; 
            pos=3                                      
	        swap(item,arr[pos]); 
	pos=cyclestart while-loop terminate		                                                       
*/


