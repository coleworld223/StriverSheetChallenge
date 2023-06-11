class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    vector <vector <int>> A(N);
	    vector <int> V(N);
	    for (int i = 0; i < p.size(); i++) {
	        A[p[i].first].push_back(p[i].second);
	    }
	    
	    vector <int> In(N);
	    for (int i = 0; i < N; i++) {
	        for (int u : A[i]) {
	            In[u]++;
	        }
	    }
	    
	    queue <int> Q;
	    vector <int> R;
	    for (int i = 0; i < N; i++) {
	        if(In[i] == 0) {
	            Q.push(i);
	            V[i] = 1;
	        }
	    }
	    
	    while(!Q.empty()) {
	        int C = Q.front();
	        Q.pop();
	        R.push_back(C);
	        for (int u : A[C]) {
	            if(V[u])continue;
	            In[u]--;
	            if(In[u] == 0) {
	                V[u] = 1;
	                Q.push(u);
	            }
	        }
	    }
	    return (R.size() == N);
	}
};
