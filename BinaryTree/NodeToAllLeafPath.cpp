class Solution {
public:
    string Con(int x) {
      string TT = to_string(x);
      return TT;
    }
    vector <string> Ans;
    void D(TreeNode* Node, string S) {
      if(Node -> left == NULL && Node -> right == NULL) {
        Ans.push_back(S);
        return;
      }
      if(Node -> left != NULL) {
        S += "->";
        string X = Con(Node -> left -> val);
        int Xs = X.size();
        S += X;
        D(Node -> left, S);
        S.erase((int) S.size() - 2 - Xs, 2 + Xs);
      }
      if(Node -> right != NULL) {
        S+= "->";
        string X = Con(Node -> right -> val);
        int Xs = X.size();
        S += X;
        D(Node -> right, S);
        S.erase((int) S.size() - 2 - Xs, 2 + Xs);
      }
      return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string S = "";
        S += Con(root -> val);
        D(root, S);
        return Ans;
    }
};
