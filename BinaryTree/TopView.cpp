struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    map <int, int> M;
    vector<int> topView(Node *root)
    {
        queue <pair <Node*, int>> Q;
        Q.push({root, 0});
        while (!Q.empty()) {
            auto Cur_Node = Q.front();
            Q.pop();
            if(M.count(Cur_Node.second) == 0) {
                M[Cur_Node.second] = (Cur_Node.first -> data); 
            }
            if(Cur_Node.first -> left != NULL) Q.push({Cur_Node.first -> left, Cur_Node.second - 1});
            if(Cur_Node.first -> right != NULL) Q.push({Cur_Node.first -> right, Cur_Node.second + 1});
        }
        vector <int> R;
        for (auto val : M) {
            R.push_back(val.second);
        }
        return R;
    }

};
