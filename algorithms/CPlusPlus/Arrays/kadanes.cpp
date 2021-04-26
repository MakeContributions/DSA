//kadanes algo
int maxSubarraySum(int arr[], int size)

{
    int max_ending_here = 0, max_so_far = INT_MIN;
    for (int i = 0; i < size; i++) {
       
        // include current element to previous subarray only
        // when it can add to a bigger number than itself.
        if (arr[i] <= max_ending_here + arr[i]) {
            max_ending_here += arr[i];
        }
       
        // Else start the max subarry from current element
        else {
            max_ending_here = arr[i];
        }
        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }
    return max_so_far;
} 