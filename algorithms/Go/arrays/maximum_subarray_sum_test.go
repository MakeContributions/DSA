package arrays

import "testing"

func TestMaximumSubarraySum(t *testing.T) {
	sampleArray := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	want := 6
	if got := maximumSubarraySum(sampleArray); want != got {
		t.Errorf("want %v , got %v", want, got)
	}
}
