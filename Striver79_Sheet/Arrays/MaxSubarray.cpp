#include <bits/stdc++.h>
using namespace std;

// Intuition / Algorithm:
/*
    1. While traversing the array, a subarray is useful only if its sum is
   positive. A negative sum will only reduce any future subarray.

    2. For each index, decide whether to:
       - start a new subarray from the current element, or
       - extend the previous subarray.

    3. Keep track of the maximum subarray sum seen so far.

    4. The maximum value encountered during this process is the answer.
*/

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    if (n == 0)
      return 0;

    int curr_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < n; i++) {
      curr_sum = max(nums[i], curr_sum + nums[i]);
      max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
  }
};