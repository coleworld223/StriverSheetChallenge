class Solution
{
	public:
	stack <int> S;
	vector <int> vis;
	void D(int u, vector <int> adj[]) {
	    vis[u] = 1;
	    for (int v : adj[u]) {
	        if(vis[v] == 0) {
	            D(v, adj);
	        }
	    }
	    S.push(u);
	} 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vis.resize(V, 0);
	    for (int i = 0; i < V; i++) {
	        if(vis[i] == 0) {
	            D(i, adj);
	        }
	    }
	    vector <int> T;
	    while(!S.empty()) {
	        T.push_back(S.top());
	        S.pop();
	    }
	    return T;
	}
};
