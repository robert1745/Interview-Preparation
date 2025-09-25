#include <bits/stdc++.h>
using namespace std;

// Brute force approach  
// Intuition: Try every possible subarray, calculate its sum, and keep track of the maximum.  
// Time complexity: O(n^2) in worst case (two loops).  
// Space complexity: O(1).  
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};


// Optimal approach (Kadane’s Algorithm)  
// Intuition: At each step, decide whether to extend the current subarray or start fresh from nums[i].  
// Keep track of the global maximum sum.  
// Time complexity: O(n) (single pass).  
// Space complexity: O(1).  
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int num : nums) {
            currSum = max(num, currSum + num);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
