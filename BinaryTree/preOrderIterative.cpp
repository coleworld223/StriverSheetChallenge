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
    vector <int> R;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return R;
        stack <TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
          auto node = st.top();
          st.pop();
          R.push_back(node -> val);
          if(node -> right != NULL) st.push(node -> right);
          if(node -> left != NULL) st.push(node -> left);
        }
        return R;
    }
};
