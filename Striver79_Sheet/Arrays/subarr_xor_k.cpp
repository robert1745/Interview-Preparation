#include<bits/stdc++.h>
using namespace std;


// Intitution : 
/*

We are asked to count subarrays (continuous segments) whose XOR equals k.

A direct brute-force approach checks all subarrays in O(n²), which is too slow.

Sliding window cannot be used because XOR is not monotonic: 
    expanding or shrinking a window does not change the XOR in a predictable direction.

To solve this efficiently, we observe that:

- XOR of a subarray can be computed using prefix XOR
- If prefixXor[i] is the XOR of elements from index 0 to i, then:
    XOR(l..r) = prefixXor[r] ^ prefixXor[l-1]

So for a subarray ending at index r to have XOR k, we need:
    prefixXor[l-1] = prefixXor[r] ^ k


Thus, for each index r, the problem reduces to 
      counting how many times a required prefix XOR has appeared before.

This can be efficiently done using a hashmap.
*/


// Algorithm :
/*
1. Initialize:
    - prefixXor = 0
    - A hashmap freq to store frequency of prefix XORs
    - Set freq[0] = 1 (to handle subarrays starting at index 0)

2. Traverse the array from left to right:

    - Update prefixXor by XORing current element
    - Compute required = prefixXor ^ k
    - If required exists in hashmap, add its frequency to the answer
    - Increment frequency of current prefixXor in hashmap

3. Return the final count
*/

// Just interviewer question : what does hashmap telling here for any index i?

// “At index i, the hashmap tells how many valid starting points exist for subarrays
//  ending at i whose XOR equals k.”

    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int,int>freq;
        freq[0]=1;

        int count=0;
        int pref_xor=0;

        for(int num : nums){
            pref_xor^=num;
            int needed=pref_xor^k;

            if(freq.count(needed))
                count+=freq[needed];

            freq[pref_xor]++;
        }
        return count;
    }
