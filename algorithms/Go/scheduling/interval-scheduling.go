/*
	Input: Start and finish time of n jobs
	Output: Schedule with maximum number of non overlapping jobs
	The Strategy: At each step choose the job with earliest finish time
	Algorithm Type: Greedy
	Time Complexity: O(n*log(n))
*/
package scheduling

import (
	"fmt"
	"sort"
)

func getOptSchedule(jobs [][]int) []int {
	var optSchedule []int
	sortedJobs := append([][]int(nil), jobs...)
	sort.SliceStable(sortedJobs, func(i, j int) bool {
		return sortedJobs[i][2] < sortedJobs[j][2]
	})
	n := len(sortedJobs)
	optSchedule = append(optSchedule, sortedJobs[0][0])
	for i := 1; i < n; i++ {
		last := optSchedule[len(optSchedule)-1]
		if sortedJobs[i][1] >= jobs[last][2] {
			optSchedule = append(optSchedule, sortedJobs[i][0])
		}
	}
	return optSchedule
}

func RunIntervalScheduling() {
	jobs := [][]int{
		{0, 2, 8}, // [job_id, start_time, finish_time]
		{1, 6, 10},
		{2, 1, 3},
		{3, 4, 7},
		{4, 3, 6},
		{5, 1, 2},
		{6, 8, 10},
		{7, 10, 15},
		{8, 12, 16},
		{9, 14, 16},
	}
	optSchedule := getOptSchedule(jobs)
	fmt.Println(optSchedule)
}
