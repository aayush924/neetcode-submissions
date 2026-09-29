class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Only record the very first node of this level
                if (i == 0) {
                    ans.push_back(temp->val);
                }

                if (temp->right) q.push(temp->right);
                if (temp->left)  q.push(temp->left);
            }
        }

        return ans;
    }
};