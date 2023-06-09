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
    multiset <pair <int, pair <int, int>>> T;
    vector <vector <int>> R;
    void F(TreeNode* Node, int R, int C) {
      if(Node == NULL) return;
      T.insert({C, {R, Node -> val}});
      if(Node -> left != NULL) F(Node -> left, R + 1, C - 1);
      if(Node -> right != NULL) F(Node -> right, R + 1, C + 1);
      return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return R;
        F(root, 0, 0);
        int Off = abs((*T.begin()).first);
        int Last = -1;
        for (auto val : T) {
          int x = (val).first + Off;
          if(x != Last) {
            vector <int> Temp;
            R.push_back(Temp);
            Last = x;
          }
          R[Last].push_back(val.second.second);
        }
        return R;
    }
};
