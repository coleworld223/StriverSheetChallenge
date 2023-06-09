struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    multiset <pair <int, pair <int, int>>> T;
    vector <int> R;
    void F(Node* node, int Row, int Col) {
        if(node == NULL) return;
        T.insert({Col, {Row, node -> data}});
        if(node -> left != NULL) F(node -> left, Row + 1, Col - 1);
        if(node -> right != NULL) F(node -> right, Row + 1, Col + 1);
        return;
    }
    vector<int> topView(Node *root)
    {
        if(root == NULL) return R;
        int Last = -1e8;
        F(root, 0, 0);
        for (auto val : T) {
            if(val.first != Last) {
                Last = val.first;
                R.push_back(val.second.second);
            }
        }
        return R;
    }

};
