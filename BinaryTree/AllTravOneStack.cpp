using Vi = vector <int> ;
    void C(TreeNode* root, Vi &Pr, Vi &In, Vi &Po) {
      if(root == NULL) return;
      stack <pair <TreeNode*, int>> S;
      S.push({root, 1});
      while(!S.empty()) {
        auto N = S.top();
        S.pop();
        if(N.second == 1) {
          //Pre
          S.push({N.first, N.second + 1});
          Pr.push_back(N.first -> val);
          if(N.first -> left != NULL) {
            S.push({N.first -> left, 1});
          }
        }
        else if(N.second == 2) {
          //In
          S.push({N.first, N.second + 1});
          In.push_back(N.first -> val);
          if(N.first -> right != NULL) {
            S.push({N.first -> right, 1});
          }
        }
        else {
          //Post
          Po.push_back(N.first -> val);
        }
      }
      return;
    }
