#include<bits/stdc++.h>
using namespace std;

// Brute force approach  
// Intuition: Try all pairs (buy on day i, sell on day j > i) and track maximum profit.  
// Time complexity: O(n^2), since we check every possible pair.  
// Space complexity: O(1).  
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }
};


// Optimal approach  
// Intuition: Keep track of the minimum price seen so far and update max profit at each step.  
// Time complexity: O(n), as we scan once.  
// Space complexity: O(1).  
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};
