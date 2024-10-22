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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZag;
        
        if (root == nullptr) {
            return zigZag; // Return an empty vector if the root is null
        }

        queue<TreeNode *> q;
        q.push(root);

        bool dir = false; // false means left-to-right, true means right-to-left
        
        while (!q.empty())
        {
            vector<int> level;
            int n = q.size();
             
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            if (dir) {
                reverse(level.begin(), level.end()); // Reverse the level if direction is right-to-left
            }

            zigZag.push_back(level);

            dir = !dir; // Toggle direction after processing the whole level
        }

        return zigZag;
    }
};
