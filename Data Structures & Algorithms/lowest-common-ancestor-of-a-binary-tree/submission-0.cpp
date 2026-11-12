/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p) return p;
        else if(root==q) return q;
        
        TreeNode* lefty=lowestCommonAncestor(root->left, p, q);
        TreeNode* righty=lowestCommonAncestor(root->right, p, q);

        if(lefty!=NULL || righty!=NULL){
            if(lefty==NULL) return righty;
            else if(righty==NULL) return lefty;
            else return root;
        }
        else return NULL;
    }
};