class Solution {
public:
    bool helper(TreeNode* root1, TreeNode* root2) {
        // Base case: both nodes are null
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        // One of the nodes is null, the other is not
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        
        // Check if current nodes are equal
        if (root1->val != root2->val) {
            return false;
        }
        
        // Check both children without swapping
        bool noSwap = helper(root1->left, root2->left) && helper(root1->right, root2->right);
        // Check both children with swapping
        bool swap = helper(root1->left, root2->right) && helper(root1->right, root2->left);
        
        return noSwap || swap; // Return true if either configuration is valid
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }
};
