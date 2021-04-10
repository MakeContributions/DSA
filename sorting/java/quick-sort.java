// Java program for implement Quick Sort
//Note: Rightmost element in the array is chosen as pivot
class QuickSortBack
{
	private int[] arr;
	public QuickSortBack()
	{
		arr = new int[]{222,64,545,99,12,35,1,87,33,945,77}; // Array to be sorted

	}

	//Function to swap two Array elements
	public void swap(int index1 , int index2)
	{
		int x = arr[index1];                             //first value in temporary variable x
		arr[index1] = arr[index2];  
		arr[index2] = x;

	}

	//Function to print the Array
	public void displayArray()
	{
		for (int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}

	// Function to partition the Array 
	public int partitionFn(int left,int right,int pivot)
	{
		int leftptr = left -1;
		int rightptr = right;
		while (true)
		{
			while (arr[++leftptr]<pivot);                  //Find bigger item than pivot
			while (rightptr>0 && arr[--rightptr]>pivot);   //Find smaller item

			if (leftptr>=rightptr)                           //if index numbers cross,partition is done
				break;
			else
				swap(leftptr,rightptr);                      //swap elements

		}
		swap(leftptr,right);                                 //restore pivot element
	return leftptr;                                          //return pivot location
	}

	//Recursive quicksort function
	public void recQuickSort(int left,int right)
	{
		if (right-left <= 0)                                 // already sorted if size is 1
			return;
		else
		{
			int pivot = arr[right];                          //choosing pivot as rightmost(end) element of Array
			int partition = partitionFn(left,right,pivot);
			recQuickSort(left,partition-1);                  //Sort left
			recQuickSort(partition+1,right);                 //Sort right

		}
	}

	//function called in main
	public void quickSort()
	{
		recQuickSort(0,arr.length-1);
	}
}

class QuickSort
{	
	//Driver code to test above
	public static void main(String[] args) {
		
		QuickSortBack ob = new QuickSortBack();
		ob.displayArray();                         //display array before sort
		ob.quickSort();							   //call quickSort
		ob.displayArray();
	}
}
