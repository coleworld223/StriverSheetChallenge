class Solution {
public:
    bool F = 1;
    vector <int> V;
    vector <int> C;
    bool D(int u, int col, vector <int> adj[]) {
        V[u] = 1;
        C[u] = col;
        for (int v : adj[u]) {
            if(V[v] == 0) {
                if(D(v, 1 - col, adj) == false)return false;
            }
            else{
                if(C[u] == C[v]) {
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int N, vector<int>adj[]){
	    V.resize(N, 0);
	    C.resize(N, -1);
	    for (int i = 0; i < N; i++) {
	        if(V[i] == 0) {
	            if(D(i, 0, adj) == false) return false; 
	        }
	    }
	    return true;
	}

};
