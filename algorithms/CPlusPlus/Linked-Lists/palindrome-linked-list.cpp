#include <bits/stdc++.h>
using namespace std;

// TC = O(N)
// SC = O(1)

// Given the head of a singly linked list, return true if it is a palindrome
// or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false


// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        vector<int> ans;
        ListNode* temp = head;
        while (temp) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = ans.size() - 1;
        while (i < j) {
            if (ans[i] != ans[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(1);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Create an instance of the Solution class
    Solution solution;

    // Call the isPalindrome function and print the result
    bool isPalin = solution.isPalindrome(head);
    cout << "Is the linked list a palindrome? " << (isPalin ? "Yes" : "No") << endl;

    // Clean up the linked list memory
    ListNode* temp = head;
    while (temp) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}