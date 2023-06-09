class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()) {
          int S = Q.size();
          vector <int> T;
          for (int i = 0; i < S; i++) {
            auto C = Q.front();
            Q.pop();
            T.push_back(C -> val);
            if(C -> left != NULL) Q.push(C -> left);
            if(C -> right != NULL) Q.push(C -> right);
          }
          bool chk = 1;
          for (int i = 0; i < T.size() / 2; i++) {
            if(T[i] != T[(int) T.size() - i - 1])chk = 0;
          }
          if(!chk)return chk;
        }
        return true;
    }
};
