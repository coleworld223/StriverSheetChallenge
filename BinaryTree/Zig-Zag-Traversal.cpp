/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
    	queue <Node*> Q;
    	Q.push(root);
    	
    	vector <int> R;
    	bool It = 1; // Go right
    	while(!Q.empty()) {
    	    int S = Q.size();
    	    vector <int> T;
    	    for (int i = 0; i < S; i++) {
    	        auto Cur_Node = Q.front();
    	        Q.pop();
    	        T.push_back(Cur_Node -> data);
    	        if(Cur_Node -> left != NULL) {
    	            Q.push(Cur_Node -> left);
    	        }
    	        if(Cur_Node -> right != NULL) {
    	            Q.push(Cur_Node -> right);
    	        }
    	    }
    	    if(!It) {
    	        It = 1;
    	        while(!T.empty()) {
    	            R.push_back(T.back()); T.pop_back();
    	        }
    	    }
    	    else{
    	        It = 0;
    	        reverse(T.begin(), T.end());
    	        while(!T.empty()) {
    	            R.push_back(T.back()); T.pop_back();
    	        }
    	    }
    	}
    	return R;
    }
};
