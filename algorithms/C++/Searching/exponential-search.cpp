/*
Exponential search involves two steps, first to find the range within
which the element is found and searching inside that range using
binary search.
*/

#include <iostream>
#include <vector>

int binary_search(std::vector<int> arr, int item, int low, int high){
	int mid;
	while(low <= high){
		mid = low + (high - low)/2;
		if(arr[mid] == item){ return mid; }
		else if(arr[mid] < item){ low = mid + 1; }
		else{ high = mid - 1;}
	}
	return -1;
}

int exponential_search(std::vector<int> arr, int item){
	int k = 1;
	int size = arr.size() - 1;
	while(k < size && arr[k] <= item){ k *= 2; }
	return binary_search(arr, item, k/2, std::min(k, size));
}

int main(){
	std::vector<int> arr;
	for(int i=1; i<30; i+=2){ arr.push_back(i); }
	for(int i=0; i<arr.size(); i++){ std::cout << arr[i] << " "; }
	std::cout << std::endl;

	int index = exponential_search(arr, 15);
	std::cout << "Index of 15: " << index << std::endl;

	/*
		Output:
		1 3 5 7 9 11 13 15 17 19 21 23 25 27 29
		Index of 15: 7

		Time Complexity: O(log(n))
	*/

	return 0;
}
