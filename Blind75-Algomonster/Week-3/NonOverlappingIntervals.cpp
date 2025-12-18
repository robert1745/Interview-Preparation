#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] <
                   b[1]; // sort by end time.// earliest finish is important
        });

        int end = intervals[0][1];
        int cnt = 0;

        for (int i = 1; i < n; i++) {

            // non-overlapping
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            }
            // overlapping
            else {
                cnt++;
            }
        }
        return cnt;
    }
};