//Java program for implementation of Merge Sort
import java.util.*;

class MergeSortApp
{
	private int[] arr;
	public MergeSortApp()
	{		
		arr = new int[]{12,54,222,54622,10,169,30}; //Array to sort
	}

    //Function to display/Print Array
	public void printArray()
	{
	for (int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+ " ");
		}
		System.out.println();
	}

	//Function called by main()	
	public  void mergesort()
	{
		int[] wr = new int[arr.length];  //Provides workspace
		recMergeSort(wr,0,wr.length-1);
	}

	//Recursive function to divide array in halves	
	public void recMergeSort(int[] wr,int lowBound,int uppBound)
	{
	if (lowBound == uppBound) 
		return;
	else
	{
		int mid = (lowBound+uppBound)/2; //find midpoint
		recMergeSort(wr,lowBound,mid);   //Sort low half
		recMergeSort(wr,mid+1,uppBound); // Sort high half
		merge(wr,lowBound,mid+1,uppBound); //merge them
	}
	}

	//Function to merge sorted Arrays	
	public  void merge(int[] wr,int lowptr,int highptr, int uppBound)
	{
	
			int j=0;
			int lowBound = lowptr;
			int mid = highptr-1;
			int n = uppBound-lowBound+1;

	while (lowptr<=mid && highptr<=uppBound)
	{		if (arr[lowptr]<arr[highptr])
				wr[j++] = arr[lowptr++];
			else
				wr[j++]	= arr[highptr++];
	}
	while (lowptr<=mid)
		wr[j++] = arr[lowptr++];

	while(highptr<=uppBound)
		wr[j++] = arr[highptr++];


	for (j=0;j<n;j++)
		arr[lowBound+j] = wr[j];
	}
}	

class MergeSort 
{		//Driver code to test above code
		public static void main(String[] args) 
		{
				MergeSortApp ob = new MergeSortApp(); //creates object
				ob.printArray();	//Displays Array before sorting
				ob.mergesort();
				ob.printArray();
		}
}
