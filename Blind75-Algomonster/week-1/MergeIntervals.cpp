#include<bits/stdc++.h>
using namespace std;

/* ==================== BRUTE FORCE ====================

    Intuition:
    - First, sort the intervals by their start time.
    - Then, for each interval, check against all previously included intervals 
      to see if it overlaps. If so, merge them.
    - This requires nested iterations (O(n^2)).

    Approach:
    1. Sort intervals by start time.
    2. Maintain a result vector.
    3. For each interval, check with all intervals already in the result:
        - If overlaps, merge them by updating start & end.
        - Else, insert as new.
    
    Time Complexity: O(n^2)   (nested merging check for each interval)
    Space Complexity: O(n)    (for storing merged result)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // sort by start time
        vector<vector<int>> res;

        for (auto curr : intervals) {
            bool merged = false;
            for (auto &prev : res) {
                if (!(curr[0] > prev[1] || curr[1] < prev[0])) { 
                    prev[0] = min(prev[0], curr[0]);
                    prev[1] = max(prev[1], curr[1]);
                    merged = true;
                    break;
                }
            }
            if (!merged) {
                res.push_back(curr);
            }
        }
        return res;
    }
};


/* ==================== OPTIMIZED ====================

    Intuition:
    - After sorting, overlapping intervals will be adjacent.
    - We can merge intervals in a single pass.
    - This reduces the nested checking to linear scan.

    Approach:
    1. Sort intervals by start time.
    2. Initialize result with the first interval.
    3. Iterate through remaining intervals:
        - If overlap with last interval in result, merge them.
        - Else, push as new interval.
    
    Time Complexity: O(n log n)   (sorting dominates, linear scan afterwards)
    Space Complexity: O(n)        (for storing merged result)
*/
class OptimizedSolution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) { 
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};