import unittest
from merge_sort import merge_sort as ms
from bubble_sort import bubbleSort as bs
from insertion_sort import insertion_sort
from heap_sort import heap_sort as hs

class TestSorting(unittest.TestCase):

	# Merge-Sort test cases
	def test1(self):
		test_list = [5,4,8,6,2,7]
		self.assertEquals(ms(test_list),[2,4,5,6,7,8])
		
	def test2(self):
		test_list = [-1,5,3,10,0,-8]
		self.assertEquals(ms(test_list), [-8,-1,0,3,5,10])
		
	def test3(self):
		test_list = [-4,-10,-2,-7,-1,-6]
		self.assertEquals(ms(test_list),[-10,-7,-6,-4,-2,-1])
	
	# Bubble-Sort test cases	
	def test4(self):
		test_list = [5,4,8,6,2,7]
		self.assertEquals(bs(test_list),[2,4,5,6,7,8])
		
	def test5(self):
		test_list = [-1,5,3,10,0,-8]
		self.assertEquals(bs(test_list), [-8,-1,0,3,5,10])
		
	def test6(self):
		test_list = [-4,-10,-2,-7,-1,-6]
		self.assertEquals(bs(test_list),[-10,-7,-6,-4,-2,-1])
		
	# Insertion-Sort test cases
	def test7(self):
		test_list = [5,4,8,6,2,7]
		insertion_sort(test_list)
		self.assertEquals(test_list,[2,4,5,6,7,8])
		
	def test8(self):
		test_list = [-1,5,3,10,0,-8]
		insertion_sort(test_list)
		self.assertEquals(test_list, [-8,-1,0,3,5,10])
		
	def test9(self):
		test_list = [-4,-10,-2,-7,-1,-6]
		insertion_sort(test_list)
		self.assertEquals(test_list,[-10,-7,-6,-4,-2,-1])
		
	# Heap-Sort test cases
	def test10(self):
		test_list = [5,4,8,6,2,7]
		self.assertEquals(hs(test_list),[2,4,5,6,7,8])
		
	def test11(self):
		test_list = [-1,5,3,10,0,-8]
		self.assertEquals(hs(test_list), [-8,-1,0,3,5,10])
		
	def test12(self):
		test_list = [-4,-10,-2,-7,-1,-6]
		self.assertEquals(hs(test_list),[-10,-7,-6,-4,-2,-1])
		
		
if __name__ == '__main__':
    unittest.main()
