#include<bits/stdc++.h>
using namespace std;

// Intitution : 

/*
- The array should be a permutation of numbers from 1 to n.
- Because:
    - One number A appears twice
    - One number B is missing
- Comparing the array with the ideal range 1..n will expose the mismatch.

Why XOR?
- XOR cancels identical numbers (x ^ x = 0)
- XOR does not overflow
- Order doesn’t matter
- Uses O(1) extra space

If we XOR:
- all elements of nums
- all numbers from 1 to n

All correct numbers cancel out, leaving:
- xor_all = A ^ B


Now we just need to separate A and B.

Since A ≠ B, they differ in at least one bit.
That differing bit can be used to split numbers into two groups
so that A and B land in different buckets.

*/


// Algorithm : 
/*

1. Compute xor_all = xor(nums) ^ xor(1..n) → gives A ^ B
2. Find the rightmost set bit in xor_all
3. Partition numbers into two groups based on this bit:
    - Group 1: bit is set
    - Group 2: bit is not set

4. XOR separately:
    - elements of nums
    - numbers from 1..n

5. You’ll get two values {x, y} = {A, B} (unordered)
6. Scan the array once:
    - the one that appears → duplicate A
    - the other → missing B

*/


vector<int> findDuplicateAndMissing(const vector<int>& nums) {
    int n = nums.size();
    int xor_all = 0;

    // XOR all elements in nums and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xor_all ^= nums[i];
        xor_all ^= (i + 1);
    }

    // Rightmost set bit
    int diff_bit = xor_all & (-xor_all);

    int x = 0, y = 0;

    // Partition nums
    for (int val : nums) {
        if (val & diff_bit)
            x ^= val;
        else
            y ^= val;
    }

    // Partition range 1..n
    for (int i = 1; i <= n; i++) {
        if (i & diff_bit)
            x ^= i;
        else
            y ^= i;
    }

    // Determine which is duplicate
    for (int val : nums) {
        if (val == x)
            return {x, y};  // x = duplicate, y = missing
    }

    return {y, x};          // y = duplicate, x = missing
}
