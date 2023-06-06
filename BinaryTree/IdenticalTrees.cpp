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
 //we will find all the traversals
 //{pre, in, post} in one go using one stack
class Solution {
public:
    bool F = 1;
    void Pre(TreeNode* N1, TreeNode*  N2) {
      if(N1 == NULL || N2 == NULL){
        if(N1 != N2)F = 0;
        return;
      }
      if(N1 -> val != N2 -> val)F = 0;
      Pre(N1 -> left, N2 -> left);
      Pre(N1 -> right, N2 -> right);
      return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
      Pre(p, q);
      return F;
    }
};
