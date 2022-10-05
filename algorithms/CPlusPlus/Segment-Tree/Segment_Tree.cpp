/**
 * @file Segment_Tree.cpp
 * @author Motasim (@motasimmakki)
 * @brief Implementation of Segment Tree
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Header File
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Main Template
/**
 * @brief Defination of SGT class
 */
class SGT {
    // Data members of SGT class.
	vector<int> tree, lazy;
	int n = 0;
public:
    /**
     * @brief Construct a new SGT object
     * 
     * @param n 
     */
	SGT(int n) {
		n *= 4;
		tree.resize(n, 1e9);
		lazy.resize(n, 0);
	}
    /**
     * @brief To build up the Segment Tree with the given array.
     * 
     * @param arr 
     * @param idx 
     * @param low 
     * @param high 
     * @return int 
     */
	int build(vector<int> arr, int idx, int low, int high) {
		if(low == high)
			return tree[idx] = arr[low];
		int mid = (low + high) >> 1;
		return tree[idx] = max(	
			build(arr, 2*idx+1, low, mid), 
			build(arr, 2*idx+2, mid + 1, high)
		);
	}
	/**
	 * @brief To add up a value to a particular index, 'idx' in a SGT.
	 * 
	 * @param idx 
	 * @param point 
	 * @param value 
	 * @param low 
	 * @param high 
	 * @return int 
	 */
	int pointUpdate(int idx, int point, int value, int low, int high) {
		if(high == point)
			return tree[idx] += value;
		int mid = (low + high) >> 1;
		if(point <= mid) {
			tree[idx] = max(
				pointUpdate(2*idx+1, point, value, low, mid),
				tree[2*idx+2]
			);
		} else {
			tree[idx] = max(
				tree[2*idx+1],
				pointUpdate(2*idx+2, point, value, mid + 1, high)
			);
		}
		return tree[idx];
	}
	/**
	 * @brief To add up the value from leftRange to rightRange inclusively.
	 * 
	 * @param idx 
	 * @param value 
	 * @param leftRange 
	 * @param rightRange 
	 * @param low 
	 * @param high 
	 */
	void rangeUpdate(int idx, int value, int leftRange, int rightRange, int low, int high) {
		// Pending Update.
		if(lazy[idx] != 0) {
			tree[idx] += (high - low + 1) * lazy[idx];
			if(low != high) {
				lazy[2*idx+1] += lazy[idx];
				lazy[2*idx+2] += lazy[idx];
			}
			lazy[idx] = 0;
		}
		if(leftRange > high || rightRange < low || low > high)
			return;
		if(low >= leftRange && high <= rightRange) {
			tree[idx] += (high - low + 1) * value;
			if(low != high) {
				lazy[2*idx+1] += value;
				lazy[2*idx+2] += value;
			}
			return;
		}
		int mid = (low + high) >> 1;
		rangeUpdate(2*idx+1, value, leftRange, rightRange, low, mid);
		rangeUpdate(2*idx+2, value, leftRange, rightRange, mid + 1, high);
		tree[idx] = tree[2*idx+1] + tree[2*idx+2];
	}
	/**
	 * @brief To get the sum from leftRange to rightRange inclusively.
	 * 
	 * @param idx 
	 * @param leftRange 
	 * @param rightRange 
	 * @param low 
	 * @param high 
	 * @return int 
	 */
	int queryLazySum(int idx, int leftRange, int rightRange, int low, int high) {
		// Pending Update.
		if(lazy[idx] != 0) {
			tree[idx] += (high - low + 1) * lazy[idx];
			if(low != high) {
				lazy[2*idx+1] += lazy[idx];
				lazy[2*idx+2] += lazy[idx];
			}
			lazy[idx] = 0;
		}
		if(leftRange > high || rightRange < low || low > high)
			return 0;
		if(low >= leftRange && high <= rightRange) {
			return tree[idx];
		}
		int mid = (low + high) >> 1;
		return queryLazySum(2*idx+1, leftRange, rightRange, low, mid) +
				queryLazySum(2*idx+2, leftRange, rightRange, mid + 1, high);
	}
    /**
     * @brief To get the max in range from leftRange to rightRange inclusively.
     * 
     * @param idx 
     * @param leftRange 
     * @param rightRange 
     * @param low 
     * @param high 
     * @return int 
     */
	int queryMax(int idx, int leftRange, int rightRange, int low, int high) {
		if(leftRange <= low && rightRange >= high)
			return tree[idx]; 
		if(leftRange > high || rightRange < low)
			return INT_MIN;
		int mid = (low + high) >> 1;
		return max(
			queryMax(2*idx+1, leftRange, rightRange, low, mid), 
			queryMax(2*idx+2, leftRange, rightRange, mid + 1, high)
		);
	}
};

// For Testing Purpose
int main() {
	// Given Array.
	// vector<int> arr{1, 3, 5, 7, 9, 11};
	vector<int> arr{2, 3, 1, 4, 2, 5, 2, 3, 1, 5};
	int n = arr.size();

	// SGT Construction.
	SGT sgt(n);
	sgt.build(arr, 0, 0, n-1);
	cout<< "=> "<< sgt.queryLazySum(0, 1, 7, 0, n-1)<< endl;

	// Point Update.
	// rootIndex, indexToUpdate, valueToAdd, startIdx, endIdx.
	sgt.pointUpdate(0, 3, 15, 0, n-1);

	// Range Max Query.	
	// rootIndex, fromRange, toRange, startIdx, endIdx.
	cout<< sgt.queryMax(0, 1, 4, 0, n-1)<< endl;
	// cout<< sgt.queryMax(0, 3, 8, 0, n-1)<< endl;

	// Range Update.
	// rootIndex, valueToAdd, fromRange, toRange, startIdx, endIdx.
	sgt.rangeUpdate(0, 10, 2, 6, 0, n-1);

	// Range Sum Query.
	// rootIndex, fromRange, toRange, startIdx, endIdx.
	cout<< sgt.queryLazySum(0, 3, 6, 0, n-1)<< endl;

	return 0;
    // End of main function.
}

/**
 * Time Complexity: 
 * O(log n) [for any query in range]
 *              OR
 * O(n log n) [for n query in range]
 * 
 * Space Complexity: 
 * O(n) [for builing up the Segment Tree]
 */