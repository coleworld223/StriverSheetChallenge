/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector <int> R;
    void LB(Node* N) {
        R.push_back(N -> data);
        if(N -> left == NULL)return;
        N = N -> left;
        while(N != NULL) {
            R.push_back(N -> data);
            if(N -> left != NULL) N = N -> left;
            else N = N -> right;
        }
        R.pop_back(); //popped back the last leave
    }
    
    void LN(Node* N) {
        stack <Node*> st;
        vector <Node*> T;
        st.push(N);
        while(!st.empty()) {
            auto N1 = st.top();
            st.pop();
            T.push_back(N1);
            if(N1 -> right != NULL) st.push(N1 -> right);
            if(N1 -> left != NULL) st.push(N1 -> left);
        }
        for (auto ele : T) {
            if(ele -> left == NULL && ele -> right == NULL) {
                R.push_back(ele -> data);
            }
        }
    }
    void RRB(Node* N) {
        auto Root = N;
        if(N -> right == NULL)return;
        else N = N -> right;
        stack <Node*> st;
        while(N != NULL) {
            st.push(N);
            if(N -> right != NULL) N = N -> right;
            else N = N -> left;
        }
        st.pop();
        while(st.size() > 0) {
            R.push_back(st.top() -> data);
            st.pop();
        }
    }
    vector <int> boundary(Node *root)
    {
        if(root == NULL) return R;
        if(root -> left == NULL && root -> right == NULL) {
            R.push_back(root -> data);
            return R;
        }
        LB(root);
        LN(root);
        RRB(root);
        return R;
    }
};
