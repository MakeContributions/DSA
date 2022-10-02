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




ListNode* mergeLists(ListNode* a, ListNode* b){
        if(a == NULL)   return b;
        if(b == NULL)   return a;
        ListNode* temp = new ListNode(0);
        ListNode* res = temp;
        while(a!=NULL && b!=NULL){
            if(a->val < b->val){
                temp->next=a;
                a=a->next;
                temp=temp->next;
            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }
        if(a)   temp->next = a;
        if(b)   temp->next = b;
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        for(int i=lists.size()-1;i>0;i--){
            lists[i-1] = mergeLists(lists[i-1],lists[i]);
        }
        return lists[0];
    }
