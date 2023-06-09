class Solution {
public:
    bool F(TreeNode* L, TreeNode* R) {
      if(L == NULL || R == NULL) {
        if(L == NULL && R == NULL) return true;
        else return false;
      }
      bool R1 = (L -> val == R -> val);
      bool R2 = F(L -> right, R -> left);
      bool R3 = F(L -> left, R -> right);

      return (R1 && R2 && R3);
    }
    bool isSymmetric(TreeNode* root) {
        // if(root == NULL) return true;
        return F(root -> left, root -> right);
    }
};
