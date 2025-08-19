#include<bits/stdc++.h>
using namespace std;

/*
Intuition:
-----------
Two words are anagrams if they contain the same characters in the same frequency,
just arranged differently. For example, "eat", "tea", and "ate" are anagrams.

So the idea is:
1. Sort each string. Anagrams will have the same sorted form.
   - Example: "eat" -> "aet", "tea" -> "aet", "ate" -> "aet"
2. Use this sorted string as a key in a hashmap, grouping together words with
   the same key.
3. Collect the grouped values as the result.

Approach:
-----------
1. Create an unordered_map<string, vector<string>>.
2. For each word:
   - Sort it -> use it as a key.
   - Append the original word to that key’s vector.
3. Finally, extract all values from the map into a result vector.

Time Complexity:
----------------
- Sorting each word: O(L log L), where L is the average length of a string.
- For N words, total: O(N * L log L).
- Collecting results: O(N).
Overall: O(N * L log L).

Space Complexity:
-----------------
- Storing all words in the hashmap: O(N * L).
- Extra space for keys: O(N * L).
Overall: O(N * L).
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // Sorted string as key
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};