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
    int ANS = 0;
    int H(TreeNode* node) {
      if(node == NULL) return 0;
      int L = H(node -> left);
      int R = H(node -> right);
      ANS = max(ANS, L + R + 1);
      return 1 + max(L, R);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int Hroot = H(root);
        return ANS - 1;
    }
};
