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
 //postOrder is {left, right, root}
class Solution {
public:
    vector <int> R;
    void postOrder(TreeNode* node) {
      if(node == NULL) return;
      postOrder(node -> left);
      postOrder(node -> right);
      R.push_back(node -> val);
      return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return R;
    }
};
