#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// -------------------------------------------------------
// Brute force approach  
// Intuition: Use a hash set to keep track of visited nodes.  
// If we ever see the same node again, there’s a cycle.  
// Otherwise, if we reach NULL, no cycle exists.  
// Time complexity: O(n) (each node visited once).  
// Space complexity: O(n) (storing visited nodes).  
// -------------------------------------------------------
class SolutionBrute {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* curr = head;
        while (curr != nullptr) {
            if (visited.count(curr)) {
                return true;  // cycle found
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};

// -------------------------------------------------------
// Optimal approach (Floyd’s Cycle Detection / Tortoise and Hare)  
// Intuition: Use two pointers moving at different speeds.  
// - Slow moves 1 step at a time, fast moves 2 steps.  
// - If there’s a cycle, they will eventually meet.  
// - If there’s no cycle, fast will reach NULL.  
// Time complexity: O(n) (at most 2 passes).  
// Space complexity: O(1) (only pointers).  
// -------------------------------------------------------
class SolutionOptimal {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // move by 1
            fast = fast->next->next;    // move by 2
            if (slow == fast) return true; // cycle detected
        }
        return false;  // reached NULL → no cycle
    }
};
