#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Brute force approach  
// Intuition: Store all node values in an array, then rewrite the linked list in reverse order.  
// Time complexity: O(n) for traversal + O(n) for rewriting = O(n).  
// Space complexity: O(n), since we use an extra array to store values.  
class SolutionBrute {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> vals;
        ListNode* temp = head;

        // Step 1: store all values
        while (temp) {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: rewrite values in reverse
        temp = head;
        for (int i = vals.size() - 1; i >= 0; i--) {
            temp->val = vals[i];
            temp = temp->next;
        }

        return head;
    }
};


// Optimal approach (Iterative)  
// Intuition: Reverse the pointers as we traverse, instead of using extra space.  
// Maintain three pointers: prev, curr, next.  
// Time complexity: O(n), since each node is visited once.  
// Space complexity: O(1), no extra data structures.  
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // store next
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev forward
            curr = nextNode;                 // move curr forward
        }
        return prev; // new head
    }
};


// Recursive approach (Clean but uses stack space)  
// Intuition: Reverse the rest of the list and attach current node at the end.  
// Time complexity: O(n).  
// Space complexity: O(n) due to recursive stack.  
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
