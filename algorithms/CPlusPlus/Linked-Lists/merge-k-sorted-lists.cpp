// Problem Statement
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/

/* Algorithm Explained with Complexity
During 1st iteration, we merge two lists(every list is N) into one, this will make K down to K / 2.

During 2nd iteration, we merge two lists(every list is 2N) into one, this will make K / 2 down to k /4.

During 3rd iteration, we merge two lists(every list is 4N) into one, this will make K / 4 down to k /8.

And so forth...

I think when we merge two lists, the complexity is O(list1.length) + O(list2.length).

So the total complexity is:

(2N) * (K / 2) + 
(4N) * (K / 4) + 
(8N) * (K / 8) + 
.............. + 
(2^logK*N) * (K / (2 ^logK)) 

= logK*KN
*/




ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
