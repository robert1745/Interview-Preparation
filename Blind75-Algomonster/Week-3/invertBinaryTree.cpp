
//  * Definition for a binary tree node.
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

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // Approach-1 : Using top down approach (Preorder thinking )
        // Swapping is local , no dependency on children

        if (root == nullptr)
            return nullptr;

        // swap(root->left, root->right);

        // invertTree(root->left);
        // invertTree(root->right);

        // return root;

        // Approach-2 : Using bottom-up approach ( Postorder thinking )
        // let children finish , swap at current node , parent treats children as finalised blocks
        TreeNode *leftsubtree = invertTree(root->left);
        TreeNode *rightsubtree = invertTree(root->right);

        root->left = rightsubtree;
        root->right = leftsubtree;

        return root;
    }
};