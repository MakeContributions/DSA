"""
Input: Start and finish time of n jobs
Output: Schedule with maximum number of non overlapping jobs
The Strategy: At each step choose the job with earliest finish time
Algorithm Type: Greedy
Time Complexity: O(n*log(n))
"""

def get_opt_schedule(jobs): # Returns the job_id's in the optimal schedule
  opt_schedule = []
  sorted_jobs = sorted(jobs, key=lambda j: j[2])
  n = len(sorted_jobs)
  opt_schedule.append(sorted_jobs[0][0])
  for i in range(1, n):
    if sorted_jobs[i][1] >= jobs[opt_schedule[-1]][2]:
      opt_schedule.append(sorted_jobs[i][0])
  return opt_schedule

jobs = [
  [0, 2, 8], # [job_id, start_time, finish_time]
  [1, 6, 10],
  [2, 1, 3],
  [3, 4, 7],
  [4, 3, 6],
  [5, 1, 2],
  [6, 8, 10],
  [7, 10, 15],
  [8, 12, 16],
  [9, 14, 16]
]

opt_schedule = get_opt_schedule(jobs)
print(opt_schedule)
