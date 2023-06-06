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
//preOrder is {root, left, right}
class Solution {
public:
    vector <int> R;
    void preOrder(TreeNode* node) {
      if(node == NULL) return;
      R.push_back(node -> val);
      preOrder(node -> left);
      preOrder(node -> right);
      return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return R;
    }
};
