#include <bits/stdc++.h>
using namespace std;

// Brute force approach  
// Intuition: Try every triplet (i, j, k) and check if nums[i] + nums[j] + nums[k] == 0.  
// Use a set to avoid duplicate triplets.  
// Time complexity: O(n^3) (three loops).  
// Space complexity: O(n) (for storing unique triplets).  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        st.insert(triplet);
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


// Optimal approach (Sorting + Two Pointers)  
// Intuition: Sort the array. For each nums[i],  
// use two pointers (left, right) to find pairs that sum to -nums[i].  
// Skip duplicates for i, left, and right.  
// Time complexity: O(n^2).  
// Space complexity: O(1) (ignoring output).  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate i
 
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // skip duplicates for left and right
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
