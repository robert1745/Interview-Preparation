#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------
// Brute force approach
// Intuition: Try every possible substring s[i..j].
// For each substring, check if all characters are unique using a set.
// Track the maximum length among valid substrings.
// Time complexity: O(n^3)  (O(n^2) substrings * O(n) check for uniqueness).
// Space complexity: O(n) for the set.
// -------------------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_set<char> seen;
                bool isUnique = true;
                for (int k = i; k <= j; k++) {
                    if (seen.count(s[k])) {
                        isUnique = false;
                        break;
                    }
                    seen.insert(s[k]);
                }
                if (isUnique) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

// -------------------------------------------------------
// Optimal approach (Sliding Window + HashMap)
// Intuition:
// - Use two pointers (left, right) to maintain a window of unique chars.
// - Use a map to store the last index of each character.
// - When a duplicate is found, move `left` to `max(left, lastIndex[char] + 1)`.
// - Update max length at each step.
// Time complexity: O(n) (each char visited once).
// Space complexity: O(min(n, 128)) ~ O(n) for map/set.
// -------------------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1); // ASCII map
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (lastIndex[c] >= left) {
                // duplicate found inside current window
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
