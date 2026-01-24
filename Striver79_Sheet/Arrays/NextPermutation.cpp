#include <bits/stdc++.h>
using namespace std;

// Intitution/Algorithm :
// Find the rightmost dip → increase it slightly → make the rest smallest
/*

    1.Find first decreasing element from right (pivot)
    - Starting from end, find first i where nums[i] < nums[i+1]
    - If none exists, array is in descending order → reverse whole array

    2.Find element to swap with pivot
    - In suffix after pivot, find smallest element that's > pivot
    - Since suffix is descending, can find from right: first element > pivot

    3.Swap pivot with that element

    4.Reverse the suffix (after pivot position)
    - Makes suffix ascending (smallest possible arrangement)

*/
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: find pivot
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }

    // Step 2: find next greater and swap
    if (i >= 0) {
      int j = n - 1;
      while (nums[j] <= nums[i]) {
        j--;
      }
      swap(nums[i], nums[j]);
    }

    // Step 3: reverse suffix
    reverse(nums.begin() + i + 1, nums.end());
  }
};
