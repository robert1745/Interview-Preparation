#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------
// Brute force approach
// Intuition: Try every possible pair of lines (i, j).
// - The water stored is limited by the shorter line: min(height[i], height[j])
// - Width is (j - i).
// - Area = min(height[i], height[j]) * (j - i).
// Keep track of the maximum over all pairs.
// Time complexity: O(n^2) (two nested loops).
// Space complexity: O(1).
// -------------------------------------------------------
class SolutionBrute {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int h = min(height[i], height[j]);
                int w = j - i;
                maxWater = max(maxWater, h * w);
            }
        }
        return maxWater;
    }
};

// -------------------------------------------------------
// Optimal approach (Two pointers)
// Intuition: Start with the widest container (left = 0, right = n-1).
// - The area is limited by the shorter line.
// - To possibly find a bigger area, move the pointer at the shorter line inward.
//   (because moving the taller line inward won't help, width decreases, height doesn't increase).
// Keep checking until the two pointers meet.
// Time complexity: O(n) (single pass).
// Space complexity: O(1).
// -------------------------------------------------------
class SolutionOptimal {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);

            // move the smaller line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
