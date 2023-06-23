# Python implementation of Meta binary search algorithm.
# Meta binary search is a modified form of binary search
# that incrementally constructs the index of the target value
# in the array. Like normal binary search, meta binary search
# takes O(log n) time. This algorithm is designed to reduce
# the number of comparisons needed to search the list for
# a given element. The basic idea behind Meta binary search is
# to start with an initial interval of size n that included the
# entire array. The algorithm then computes a middle element and
# compares it to the target element. If the target is found, the
# search terminates. If the middle element is greater than the
#target element, the algorithm sets the new interval to the left
# half of the previous interval, and if the middle element is less
#than the target element, the new interval is set to the right half
# of the previous interval. However, unlike binary search, Meta
# binary search does not perform a comparison for each iteration
# of the loop.
#
# Instead the algorithm uses a heuristic to determine the size of
# the next interval. it computes the difference between the value of 
# the middle element and the value of the target element, and divides
# the difference by a predetermined constant, usually 2. The result is
# then used as the size of the new interval.
# See <https://www.quora.com/What-is-meta-binary-search> for more
# detail with examples. 

# Function to show the working
# of Meta binary search
import math
def bsearch(A, key_to_search):

	n = len(A)
	# Set number of bits to represent
	lg = int(math.log2(n-1)) + 1;

	# largest array index
	#while ((1 << lg) < n - 1):
		#lg += 1

	pos = 0
	for i in range(lg - 1, -1, -1) :
		if (A[pos] == key_to_search):
			return pos

		# Incrementally construct the
		# index of the target value
		new_pos = pos | (1 << i)

		# find the element in one
		# direction and update position
		if ((new_pos < n) and
			(A[new_pos] <= key_to_search)):
			pos = new_pos

	# if element found return
	# pos otherwise -1
	return (pos if(A[pos] == key_to_search) else -1)

# Driver code
if __name__ == "__main__":

	A = [ -2, 10, 100, 250, 32315 ]
	print( bsearch(A, 10))


