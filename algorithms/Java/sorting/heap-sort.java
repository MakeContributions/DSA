
import java.util.Scanner;
public class HeapSort 
{ 
	public void sort(int array[]) 
		{

    int n = array.length; 
    for (int i = n / 2 - 1; i >= 0; i--) 
			heapify(array, n, i); 
      for (int i = n-1; i >= 0; i--) 
		{ 
			
			int temp = array[0]; 
			array[0] = array[i]; 
			array[i] = temp; 

			 
			heapify(array, i, 0); 
		} 
	} 


	void heapify(int array[], int n, int i) 
	{ 
		int largest = i;  
		int l = 2*i + 1; 
		int r = 2*i + 2;
   
  if (l < n && array[l] > array[largest]) 
			largest = l; 
if (r < n && array[r] > array[largest]) 
			largest = r; 

		
		if (largest != i) 
		{ 
			int swap = array[i]; 
			array[i] = array[largest]; 
			array[largest] = swap; 

			 
			heapify(array, n, largest); 
		} 
	} 
  public static void main(String args[]) 
	{ 
		 
		System.out.println("enter the array size");
   Scanner inputobj = new Scanner(System.in);
                 int s = inputobj.nextInt();
                  int array[] = new int[s];
                 System.out.println("enter " + s + "elements of array");
                           for(int k=0;k<s;k++)
{
int e  = inputobj.nextInt();
array[k] = e;
}
	HeapSort ob = new HeapSort(); 
		ob.sort(array); 

		System.out.println("Sorted array is"); 

		for (int i=0; i<s; ++i) 
			System.out.print(array[i]+" "); 
		System.out.println();
		
	} 
} 