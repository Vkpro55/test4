class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;

        queue<TreeNode*> q;
        q.push(root);

        int sum = root->val;

        while (!q.empty()) {
            int size = q.size();
            int currLevSum = 0;

            while (size--) {
               TreeNode* currNode = q.front(); q.pop();

               int remSum = sum - currNode->val; // level sum - current node's value
               
               // Check if the current node has a sibling value in the map
               if (mp.find(currNode) != mp.end()) {
                  remSum -= mp[currNode];  // Subtract sibling's value if exists
               }

               // Replace the current node's value with the computed sum
               currNode->val = remSum;

               // If there's a left child
               if (currNode->left != nullptr) {
                  q.push(currNode->left);
                  currLevSum += currNode->left->val;

                  // If there's also a right child, map left to right's value
                  if (currNode->right != nullptr) {
                     mp[currNode->left] = currNode->right->val;  // Using correct map name (mp)
                  }
               }

               // If there's a right child
               if (currNode->right != nullptr) {
                  q.push(currNode->right);
                  currLevSum += currNode->right->val;

                  // If there's also a left child, map right to left's value
                  if (currNode->left != nullptr) {  // Make sure left is not null before accessing
                     mp[currNode->right] = currNode->left->val;  // Fix here
                  }
               }
            }
            
            sum = currLevSum;
        }

        return root;
    }
};