#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// Intuition: Sort both strings and check if they become equal.  
// Time complexity: O(n log n), due to sorting.  
// Space complexity: O(1) (if in-place sort).  
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


// Optimal approach
// Intuition: Count frequency of each character and compare.  
// Time complexity: O(n), where n = length of string.  
// Space complexity: O(1), since alphabet size is fixed (26 lowercase letters).  
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
    
        for (char c : t) {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0) return false;
        }
        return true;
    }
};
