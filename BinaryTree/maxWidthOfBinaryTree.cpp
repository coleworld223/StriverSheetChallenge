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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long Ans = 1;
        queue <pair <TreeNode*, long long>> Q;
        Q.push({root, 0LL});
        while(!Q.empty()) {
          int sz = Q.size();
          vector <long long> T;
          int mI = Q.front().second;
          for (int i = 0; i < sz; i++) {
            auto cur = Q.front();
            Q.pop();
            if(cur.first -> left != NULL) Q.push({cur.first -> left, 2ll * (cur.second - mI) + 1});
            if(cur.first -> right != NULL) Q.push({cur.first -> right, 2ll * (cur.second - mI) + 2});
            T.push_back(cur.second - mI);
          }
          for (int i = 0; i < T.size(); i++) {
            cout << T[i] << " ";
          }
          cout << endl;
          Ans = max(Ans, T.back() - T[0] + 1);
        }
        return Ans;
    }
};
