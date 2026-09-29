class Solution {
    bool sameTree(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return (root1->val == root2->val) &&
               sameTree(root1->left, root2->left) &&
               sameTree(root1->right, root2->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        // Base case: if root is null, it cannot contain subRoot
        if (!root) return false;

        // If the tree rooted at 'root' matches, return true
        if (sameTree(root, subRoot)) return true;

        // Otherwise, search both left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};