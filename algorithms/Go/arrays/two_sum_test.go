package arrays

import (
	"testing"
)

func TestTwoSum(t *testing.T) {

	arr := []int{2, 7, 11, 15, 1, 13, 18}
	elem := 26

	want := []int{2, 3}

	if got := twoSum(arr, elem); got == nil || got[0] != want[0] && got[1] != want[1] {
		if got == nil {
			t.Errorf("got no indexes")
		}
		t.Errorf("want indexes [%d,%d] and got indexes [%d,%d]", want[0], want[1], got[0], got[1])
	}
}

func TestTwoSumEfficient(t *testing.T) {

	arr := []int{2, 7, 11, 15, 1, 13, 18}
	elem := 26

	want := []int{2, 3}

	if got := twoSumEfficient(arr, elem); got == nil || got[0] != want[0] && got[1] != want[1] {
		if got == nil {
			t.Errorf("got no indexes")
		}
		t.Errorf("want indexes [%d,%d] and got indexes [%d,%d]", want[0], want[1], got[0], got[1])
	}
}
