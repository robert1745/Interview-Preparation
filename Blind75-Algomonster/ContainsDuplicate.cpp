#include<bits/stdc++.h>
using namespace std;

// Brute force approach 
// Intuition: Compare every pair of elements to check for duplicates.  
// Time complexity: O(n^2), due to nested loops.  
// Space complexity: O(1).  
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};


// Optimal approach (HashSet) 
// Intuition: Use a hash set to track seen elements; if one reappears, it's a duplicate.  
// Time complexity: O(n) average (each insert/lookup O(1)).  
// Space complexity: O(n) for the set.  
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            if (st.find(num) != st.end()) return true;
            st.insert(num);
        }
        return false;
    }
};


// Sorting approach  
// Intuition: Sort the array and check if any adjacent elements are equal.  
// Time complexity: O(n log n) due to sorting.  
// Space complexity: O(1) (if in-place sort like std::sort is used).  
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};
