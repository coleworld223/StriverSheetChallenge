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

//inOrder is {left , root, right}
class Solution {
public:
    vector <int> R;
    void inOrder(TreeNode* node) {
      if(node == NULL) return;
      inOrder(node -> left);
      R.push_back(node -> val);
      inOrder(node -> right);
      return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return R;
    }
};
