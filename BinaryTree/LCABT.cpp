/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector <TreeNode*> Path;
    bool D(TreeNode* Root, TreeNode* Find) {
      if(Root -> val == Find -> val) {
        Path.push_back(Root);
        return true;
      }
      Path.push_back(Root);
      if(Root -> left != NULL) {
        if (D(Root -> left, Find)) {
          return true;
        }
      }
      if(Root -> right != NULL) {
        if (D(Root -> right, Find)) {
          return true;
        }
      }
      Path.pop_back();
      return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode*> Path1, Path2;
        D(root, p);
        Path1 = Path;
        Path.clear();
        D(root, q);
        Path2 = Path;
        Path.clear();
        for (auto ele : Path1) {
          cout << ele -> val << " ";
        }
        cout << endl;
        for (auto ele : Path2) {
          cout << ele -> val << " ";
        }
        cout << endl;
        //Find Last Common;
        map <int, int> Mp;
        for (int i = 0; i < Path1.size(); i++) {
          Mp[Path1[i] -> val] = 1;
        }
        TreeNode* Ans = root;
        for (int i = 0; i < Path2.size(); i++) {
          if(Mp[Path2[i] -> val] == 1) {
            Ans = Path2[i];
          }
        }
        return Ans;
    }
};
