/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool validate(TreeNode* root, TreeNode* leftP, TreeNode* rightP){
        if(!root) return true;
        
        if ((leftP && root->val <= leftP->val) || 
            (rightP && root->val >= rightP->val)) {
            return false;
        }

        return validate(root->left, leftP, root) &&
               validate(root->right, root, rightP);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};
