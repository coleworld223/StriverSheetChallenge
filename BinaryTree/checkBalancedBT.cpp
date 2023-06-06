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
    bool F = 1;
    int H(TreeNode* node) {
      //returns the height of subtree
      if(node == NULL) return 0;
      int L = H(node -> left);
      int R = H(node -> right);
      if(abs(L - R) > 1)F = 0;
      return 1 + max(L, R);
    }
    bool isBalanced(TreeNode* root) {
      int Hroot = H(root);
      return F;
    }
};
