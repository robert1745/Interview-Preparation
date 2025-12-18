#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ------------------------------------------------------
// Brute force approach
// Intuition: Store all nodes in a vector, find the (size - n)-th node and delete it.
// Time complexity: O(L), where L is the length of the list.
// Space complexity: O(L), since we store all nodes in a vector.
// ------------------------------------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int idx = nodes.size() - n;

        if (idx == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* prev = nodes[idx - 1];
        ListNode* toDelete = nodes[idx];
        prev->next = toDelete->next;
        delete toDelete;

        return head;
    }
};

// ------------------------------------------------------
// Better approach (two-pass length calculation)
// Intuition: First pass → find length. Second pass → reach (length-n)-th node and delete next.
// Time complexity: O(L), where L is the length of the list.
// Space complexity: O(1), only using variables.
// ------------------------------------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;

        while (curr) {
            length++;
            curr = curr->next;
        }

        int idx = length - n;
        if (idx == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        curr = head;
        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }

        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;

        return head;
    }
};

// ------------------------------------------------------
// Optimal approach (one-pass two-pointer)
// Intuition: Use fast and slow pointers. Move fast n+1 steps, then move both until fast reaches end.
//            Slow will be just before the node to delete.
// Time complexity: O(L), traverses the list once.
// Space complexity: O(1).
// ------------------------------------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;
    }
};
