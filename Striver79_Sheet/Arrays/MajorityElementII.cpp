#include <bits/stdc++.h>
using namespace std;

// Intuition / Algorithm:

// Proof (General Case):
/*
    Claim:
    There can be at most (k − 1) elements in an array of size n
    that appear more than ⌊n / k⌋ times.

    Proof by contradiction:

    Assume the opposite — that there are k distinct elements,
    each appearing more than ⌊n / k⌋ times.

    Since frequencies are integers, each such element appears
    at least (⌊n / k⌋ + 1) times.

    Therefore, the total number of elements would be:
        k × (⌊n / k⌋ + 1)

    But:
        ⌊n / k⌋ + 1 > n / k

    So:
        k × (⌊n / k⌋ + 1) > k × (n / k) = n

    This is impossible because the array contains only n elements.

    Hence, our assumption is false.

    Conclusion:
    There can be at most (k − 1) elements that appear
    more than ⌊n / k⌋ times.
*/

// Algorithm:
/*
    1. An element appearing more than ⌊n/3⌋ times can be at most two in number.

    2. Use a cancellation approach (Boyer–Moore):
       - Maintain two candidates and their counts.
       - Same numbers increase count.
       - Different numbers cancel existing counts.

    3. After one pass, only potential candidates remain.

    4. Do a second pass to verify which candidates actually
       appear more than ⌊n/3⌋ times.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {

    int countA = 0, countB = 0;
    int candidateA = 0, candidateB = 0;
    int n = nums.size();

    // Phase 1: Find potential majority candidates
    for (int x : nums) {
      if (countA == 0 && candidateB != x) {
        candidateA = x;
        countA = 1;
      } else if (countB == 0 && candidateA != x) {
        candidateB = x;
        countB = 1;
      } else if (x == candidateA) {
        countA++;
      } else if (x == candidateB) {
        countB++;
      } else {
        // Cancel out three different elements
        countA--;
        countB--;
      }
    }

    // Phase 2: Verify the actual counts
    countA = 0;
    countB = 0;
    for (int x : nums) {
      if (x == candidateA)
        countA++;
      else if (x == candidateB)
        countB++;
    }

    vector<int> result;
    if (countA > n / 3)
      result.push_back(candidateA);
    if (countB > n / 3)
      result.push_back(candidateB);

    return result;
  }
};
