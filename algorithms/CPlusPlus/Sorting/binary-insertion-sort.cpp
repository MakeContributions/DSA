#include <iostream>
#include <vector>

/**
 * In normal insertion sort there will be "i" comparisons
 * for every i'th iteration. 
 * 	Minimum comparison : 1
 * 	Maximum comparison : O(i) for every i'th iteration
 *
 * In binary insertion sort there will be only log(i) comparisons
 * for every i'th iteration
 * 	Minimum comparison: 1
 * 	Maximum comparison: O(log(i)) for every i'th iteration
 *  
 * Still the total time complexity of the algorithm remains the same
 * because of the swap in each iteration
 *
 * Time Complexity of binary insertion sort: O(n^2)
 */

int binary_search(std::vector<int>& arr, int item, int left, int right){
	/**
	 * Binary Search Algorithm
	 *
	 * @params: `arr` array with the elements
	 * @params: `size` size of the array
	 *
	 * Time complexity: O(log(n))
	 */
	int mid = 0;
	while(left <= right){
		mid = left + (right - left) / 2;
		if(arr[mid] == item) { return mid + 1; }
		if(arr[mid] < item ) { left = mid + 1; }
		else		     { right = mid - 1; } 		
	}
	if(item > arr[left]) {  return left + 1; }
	else { return left; }
}

void insertion_sort(std::vector<int>& arr, int size){
	/*
	 * Insertion Sort Algorithm
	 *
	 * @params: `arr` array with the elements
	 * @params: `size` size of the array
	 *
	 * Time complexity: O(n^2)
	 */

	for(int i=1; i<size; i++){
		int index = i;
		int item = arr[i];
		int loc = binary_search(arr, item, 0, i-1);
		while(index-1 >= loc){
			arr[index] = arr[index-1];
			index--;
		}
		arr[index] = item;
	}
}

int main(){
	// I/O operation
	//-----------------------------------------------
	int N;
	std::cout << "Enter total number of elements: ";
	std::cin >> N;
	std::vector<int> arr(N);
	
	std::cout << "Enter the elements: " << std::endl;
	for(auto& i: arr){ std::cin >> i; }
	//-------------------------------------------------
	
	insertion_sort(arr, N);
	for(const auto& i: arr){ std::cout << i << " "; }
} 
