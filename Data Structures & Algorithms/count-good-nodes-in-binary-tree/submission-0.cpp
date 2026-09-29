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
    void check(TreeNode* root, int val, int& count){
        if(!root) return;
        if(root->val>=val){
            count++;
        }
        check(root->left, max(val, root->val), count);
        check(root->right, max(val, root->val), count);
        return;
    }
public:
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        check(root, root->val, count);
        return count;
    }
};
