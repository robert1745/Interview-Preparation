#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
private:
    int maxSum;

    // Bottom-up DFS: returns maximum path sum starting from current node
    // going downward (to be used by parent)
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;

        // 1. First, get information FROM CHILDREN (bottom-up)
        int leftGain = dfs(node->left);   // What's best in left subtree?
        int rightGain = dfs(node->right); // What's best in right subtree?

        // Only take positive contributions (negative means we skip that side)
        leftGain = max(leftGain, 0);
        rightGain = max(rightGain, 0);

        // 2. Now we have complete information from below
        // Compute the best path THROUGH current node
        int pathThroughNode = node->val + leftGain + rightGain;

        // Update global maximum (this could be the answer)
        maxSum = max(maxSum, pathThroughNode);

        // 3. Return to parent: best path starting from this node
        // (can only extend one side upward)
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        maxSum = INT_MIN;
        dfs(root); // Start bottom-up traversal
        return maxSum;
    }
};