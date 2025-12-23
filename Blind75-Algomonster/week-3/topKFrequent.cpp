#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // App-1 : using hash+sort : nlogn or mlogm
        // int n = nums.size();

        // Building map : O(n) , if collision : O(n^2)
        // unordered_map<int, int> mp;
        // for (auto& x : nums)
        //     mp[x]++;

        // copying map into vector : O(m)
        // vector<pair<int, int>> freq(mp.begin(), mp.end());

        // nlogn
        // sort(freq.begin(), freq.end(),
        //      [](auto& a, auto& b) { return a.second > b.second; });

        // vector<int> ans;
        // for (int i = 0; i < k; i++) {
        //     ans.push_back(freq[i].first);
        // }

        // return ans;

        // App-2 : Using hashmap + heap : nlogn + klogn = nlogn
        // unordered_map<int, int> mp;
        // for (int it : nums)
        //     mp[it]++;

        // priority_queue<pair<int, int>> pq;
        // for (auto& it : mp) {
        //     pq.push({it.second, it.first});
        // }

        // vector<int> ans;
        // while (k--) {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }

        // return ans;



        // App-3 :Bucket sort : O(n)

        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto& p : mp)
            bucket[p.second].push_back(p.first);

        vector<int> ans;
        for (int freq = n; freq >= 0 && ans.size() < k; freq--) {
            for (int x : bucket[freq]) {
                ans.push_back(x);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};