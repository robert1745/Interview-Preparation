#include<bits/stdc++.h>
using namespace std;

// Intitution

/*
- Preorder gives the root order (next unused element is always root).
- Inorder gives the structure (elements left/right of root form subtrees).
- Move preorder pointer once per node, never back.

So the whole problem becomes:
“Take the next preorder element and fit it into the correct inorder segment.”

*/


// Algorithm 

/*
1. Map each inorder value → index.
2. Maintain a global preorder index preIdx.
3. Recursively build tree using inorder range (left, right).
4. Base case: left > right → no subtree.
5. Root = preorder[preIdx++].
6. Split inorder at root index.
7. Build left subtree first, then right.
8. Return root.

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution {

    TreeNode* helper(unordered_map<int, int>& mp, const vector<int>& preorder,
                     int& preIdx, int left, int right) {
        if (left > right)
            return nullptr;

        int val = preorder[preIdx++];

        TreeNode* root = new TreeNode(val);
        int inorderIdx = mp[val];

        root->left = helper(mp, preorder, preIdx, left, inorderIdx - 1);
        root->right = helper(mp, preorder, preIdx, inorderIdx + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = helper(mp, preorder, preIdx, 0, inorder.size() - 1);
        return root;
    }
};