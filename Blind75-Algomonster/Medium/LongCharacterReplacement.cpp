#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------
// Brute force approach
// Intuition: Try every possible substring s[i..j].
// For each substring, count the frequency of each character.
// The substring is valid if (length - maxFrequency <= k).
// Track the maximum valid substring length.
// Time complexity: O(n^3)  (O(n^2) substrings * O(n) to count).
// Space complexity: O(26) ~ O(1).
// -------------------------------------------------------
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> freq(26, 0);
                for (int p = i; p <= j; p++) {
                    freq[s[p] - 'A']++;
                }
                int maxFreq = *max_element(freq.begin(), freq.end());
                int len = j - i + 1;
                if (len - maxFreq <= k) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};

// -------------------------------------------------------
// Optimal approach (Sliding Window)
// Intuition:
// - Maintain a sliding window [left..right].
// - Track frequency of each char inside the window.
// - Track the maximum frequency (maxFreq) seen in the window.
// - If (windowSize - maxFreq > k), it means we need more than k changes
//   → shrink window from the left.
// - Otherwise, expand the window and update max length.
// Time complexity: O(n) (each char processed at most twice).
// Space complexity: O(26) ~ O(1).
// -------------------------------------------------------
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowSize = right - left + 1;
            if (windowSize - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
