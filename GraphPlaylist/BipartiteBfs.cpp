class Solution {
public:
    bool F = 1;
    vector <int> V;
    vector <int> C;
    void B(int u, int col, vector <int> adj[]) {
        queue <pair <int, int>> Q;
        Q.push({u, col});
        V[u] = 1;
        while(!Q.empty()) {
            int C_Node = Q.front().first;
            int Color = Q.front().second;
            Q.pop();
            for (int v : adj[C_Node]) {
                if(V[v] == 0) {
                    Q.push({v, 1 - Color});
                    C[v] = 1 - Color;
                    V[v] = 1;
                }
                else{
                    if(C[v] == C[C_Node])F = 0;
                }
            }
        }
    }
	bool isBipartite(int N, vector<int>adj[]){
	    V.resize(N, 0);
	    C.resize(N, -1);
	    for (int i = 0; i < N; i++) {
	        if(V[i] == 0) {
	            B(i, 0, adj);
	        }
	    }
	    return F;
	}

};
