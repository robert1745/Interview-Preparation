#include<bits/stdc++.h>
using namespace std;

// Brute force approach 
// Intuition: Check every possible pair to see if their sum equals the target.  
// Time complexity: O(n^2), since we use two nested loops to check all pairs.  
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};


// Optimal approach  
// Intuition: Use a hashmap to store visited numbers and check in O(1) if the complement exists.  
// Time complexity: O(n), as each element is processed once with O(1) average lookup/insert.  
// unordered_map -> O(1) average lookup/insert (hashing)
// map (ordered) -> O(log n) lookup/insert (balanced BST)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if (mp.find(x) != mp.end()) {
                ans.push_back(mp[x]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};