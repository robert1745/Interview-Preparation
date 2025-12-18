#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------
// Brute force approach
// Intuition: The minimum element in any array can be found
// by scanning through all elements and picking the smallest.
// Time complexity: O(n).
// Space complexity: O(1).
// -------------------------------------------------------
class SolutionBrute {
public:
    int findMin(vector<int>& nums) {
        int minVal = nums[0];
        for (int num : nums) {
            minVal = min(minVal, num);
        }
        return minVal;
    }
};

// -------------------------------------------------------
// Optimal approach (Binary Search)
// Intuition:
// - The array is sorted but rotated, so it has two sorted halves.
// - The minimum element is the "inflection point" (where the order breaks).
// - Use binary search:
//   • If nums[mid] > nums[right], the minimum is in the right half.
//   • Otherwise, the minimum is in the left half (including mid).
// Keep shrinking the search space until left == right.
// Time complexity: O(log n).
// Space complexity: O(1).
// -------------------------------------------------------
class SolutionOptimal {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // minimum must be in right half
                left = mid + 1;
            } else {
                // minimum is in left half (including mid)
                right = mid;
            }
        }
        return nums[left]; // left == right, pointing to minimum
    }
};
