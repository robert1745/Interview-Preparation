#include <bits/stdc++.h>
using namespace std;

// Brute force approach  
// Intuition: Keep removing valid "()", "{}", "[]" pairs until no more changes happen.  
// If string becomes empty → valid.  
// Time complexity: O(n^2) in worst case.  
// Space complexity: O(1).  
class SolutionBrute {
public:
    bool isValid(string s) {
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i + 1 < s.size(); i++) {
                if ((s[i] == '(' && s[i+1] == ')') ||
                    (s[i] == '{' && s[i+1] == '}') ||
                    (s[i] == '[' && s[i+1] == ']')) {
                    s.erase(i, 2);
                    changed = true;
                    break; // restart scan after modification
                }
            }
        }
        return s.empty();
    }
};


// Optimal approach (Stack)  
// Intuition: Push opening brackets onto a stack, and whenever a closing bracket comes, 
// check if it matches the top.  
// Time complexity: O(n)  
// Space complexity: O(n)  
class SolutionOptimal {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
