#include <bits/stdc++.h>
using namespace std;

// Intuition / Algorithm:
/*
    1. Unlike sum, product can flip sign due to negative numbers.

    2. At each index, track:
       - max product ending here
       - min product ending here

    3. A negative number can turn the minimum product into maximum.

    4. For each element, update max and min using:
       current value, value * previous max, value * previous min.

    5. The global maximum over all positions is the answer.
*/

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      int x = nums[i];

      // store before overwriting
      int prevMax = maxProd;
      int prevMin = minProd;

      maxProd = max({x, x * prevMax, x * prevMin});
      minProd = min({x, x * prevMax, x * prevMin});

      result = max(result, maxProd);
    }

    return result;
  }
};
