#include <bits/stdc++.h>
using namespace std;

// Brute force approach  
// Intuition: For each index i, multiply all elements except nums[i].  
// Time complexity: O(n^2) (two loops).  
// Space complexity: O(1) (ignoring output).  
class SolutionBrute {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    product *= nums[j];
                }
            }
            ans[i] = product;
        }
        return ans;
    }
};


// Optimal approach (Prefix + Suffix)  
// Intuition: Instead of recomputing products for each index,  
// build prefix products (before i) and suffix products (after i), then multiply them.  
// Time complexity: O(n) (two passes).  
// Space complexity: O(1) (output array not counted).  
class SolutionOptimal {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: Prefix pass
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Suffix pass
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
