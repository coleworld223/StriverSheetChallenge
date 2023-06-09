class Solution
{
    public:
    map <int, int> M;
    vector<int> rightView(Node *root)
    {
       queue <pair <Node*, int>> Q;
       Q.push({root, 0});
       while(!Q.empty()) {
           auto C = Q.front();
           Q.pop();
           M[C.second] = (C.first -> data);
           if(C.first -> left != NULL) Q.push({C.first -> left, C.second + 1});
           if(C.first -> right != NULL) Q.push({C.first -> right, C.second + 1});
       }
       vector <int> R;
       for (auto val : M) {
           R.push_back(val.second);
       }
       return R;
    }
};
