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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> visited;
        visited.push(root);
        vector<int> level;
        while(!visited.empty()){
            level.clear();
            int n=visited.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=visited.front();
                visited.pop();
                level.push_back(temp->val);
                if(temp->right) visited.push(temp->right);
                if(temp->left) visited.push(temp->left);
            }
            ans.push_back(level[0]);
        }
        return ans;
    }
};
