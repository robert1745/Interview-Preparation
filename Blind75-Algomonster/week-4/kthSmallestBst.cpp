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
    int cnt = 0;
    int ans = 0;
    void inorder(TreeNode *root, int k)
    {

        if (!root || cnt >= k)
            return;
        inorder(root->left, k);
        cnt++;

        if (cnt == k)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return ans;
    }
};

// Follow up : If the BST is modified often (i.e., we can do insert and delete operations)
//  and you need to find the kth smallest frequently, how would you optimize?

// What is interviewer checkign with this follow up?
/*
They want to check whether you can:
- Identify the bottleneck in the previous solution
- Choose the right data structure
- Reason about trade-offs

So the follow-up is mainly about design thinking, not grinding code.



*/

// Why the previous solution fails in this scenario
/*
Your inorder approach costs:
- O(n) per query in worst case

If:
- Insert / delete happen often
- kthSmallest() is called many times
➡️ This becomes too slow.

So the interviewer wants:
“Can you maintain order information dynamically?”

*/

// Answer of follow up :
/*

Expected Optimization (Core Idea):

Augment the BST with extra information

At every node, store:
int leftSize; // number of nodes in left subtree

(or more generally, subtreeSize)
- This transforms the BST into an Order Statistic Tree.


How queries work (intuition)

At a node:
Let L = size(left subtree)

Then:
If k == L + 1 → current node is answer
If k <= L → go left
Else → go right with k = k - (L + 1)
Each step eliminates half the tree.

Time:
Query: O(log n)
Insert/Delete: O(log n) (update sizes on path)

What the interviewer expects you to say (IMPORTANT)
Minimum acceptable answer (most interviews)

“We can augment each node with the size of its subtree.
Then kth smallest can be found in O(log n) time by comparing k with left subtree size.
Insert and delete will update sizes along the path.”

*/

// Code : 

//Each node stores size = number of nodes in its subtree.

struct Node {
    int val;
    int size;          // size of subtree rooted at this node
    Node* left;
    Node* right;

    Node(int v) : val(v), size(1), left(nullptr), right(nullptr) {}
};

int getSize(Node *root){
    return root?root->size:0;
}

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    root->size = 1 + getSize(root->left) + getSize(root->right);
    return root;
}

Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return nullptr;

    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    }
    else {
        // node found
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        Node* successor = findMin(root->right);
        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
    }

    root->size = 1 + getSize(root->left) + getSize(root->right);
    return root;
}

int kthSmallest(Node* root, int k) {
    if (!root) return -1;

    int leftSize = getSize(root->left);

    if (k == leftSize + 1)
        return root->val;
    else if (k <= leftSize)
        return kthSmallest(root->left, k);
    else
        return kthSmallest(root->right, k - leftSize - 1);
}


// How red black tree , avl tree is different from order statistic tree?
/*

| Aspect             | Red-Black Tree  | AVL Tree          | Order Statistic Tree |
| ------------------ | --------------- | ----------------- | -------------------- |
| Main goal          | Balance         | Stricter balance  | Rank / kth queries   |
| Balance method     | Color rules     | Height difference | Depends on base tree |
| Extra data stored  | Color           | Height            | Subtree size         |
| Height guarantee   | O(log n)        | Tighter O(log n)  | Only if balanced     |
| kth smallest       | ❌              | ❌                | ✅                   |
| Insert/Delete cost | Fewer rotations | More rotations    | Depends on base      |

Order Statistic Tree is NOT an alternative to RBT or AVL.
It is an augmentation.

In real systems:
OST = Red-Black Tree + subtree sizes
or OST = AVL Tree + subtree sizes

“Red-Black and AVL trees solve balancing; 
 Order Statistic Trees solve rank queries by augmenting a balanced BST with subtree sizes.”
*/