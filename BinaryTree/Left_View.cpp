vector<int> leftView(Node *root)
{
   vector <int> R;
   if(root == NULL) return R;
   map <int, int> M;
   queue <pair <Node*, int>> Q;
   Q.push({root, 0});
   while(!Q.empty()) {
       auto C = Q.front();
       Q.pop();
       if(M.count(C.second) == 0) {
           M[C.second] = (C.first -> data);
       }
       if(C.first -> left != NULL) Q.push({C.first -> left, C.second + 1});
       if(C.first -> right != NULL) Q.push({C.first -> right, C.second + 1});
   }
   
   for (auto val : M) {
       R.push_back(val.second);
   }
   return R;
}
