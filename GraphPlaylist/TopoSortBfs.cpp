class Solution
{
	public:
	
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    vector <int> V(N, 0);
	    vector <int> In(N, 0);
	    for (int i = 0; i < N; i++) {
	        for (int v : adj[i]) {
	            In[v]++;
	        }
	    }
	    queue <int> Q;
	    for (int i = 0; i < N; i++) {
	        if(In[i] == 0) {
	            Q.push(i);
	            V[i] = 1;
	        }
	    }
	    vector <int> R;
	    while(!Q.empty()) {
	        int C = Q.front();
	        Q.pop();
	        R.push_back(C);
	        for (int v : adj[C]) {
	            if(V[v])continue;
	            In[v]--;
	            if(In[v] == 0) {
	                V[v] = 1;
	                Q.push(v);
	            }
	        }
	    }
	    return R;
	}
};
