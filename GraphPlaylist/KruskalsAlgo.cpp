class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	vector <int> P;
	vector <int> Size;
	
	void I(int a){
	    P[a] = a;
	    Size[a] = 1;
	}
	
	int FN(int x) {
	    if(P[x] == x) return x;
	    else return P[x] = FN(P[x]);
	}
	
	void MN(int a, int b) {
	    a = FN(a);
	    b = FN(b);
	    if(Size[a] < Size[b]) swap(a, b);
	    P[b] = a;
	    Size[a] += Size[b];
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        P.resize(V);
        Size.resize(V);
        for (int i = 0; i < V; i++) {
            I(i);
        }
        set <vector <int>> S;
        for (int i = 0; i < V; i++) {
            for (auto u : adj[i]) {
                vector <int> T = {u[1], u[0], i};
                S.insert(T);
            }
        }
        int Ans = 0;
        while(!S.empty()) {
            vector <int> C = (*S.begin());
            S.erase(S.begin());
            int u = C[1];
            int v = C[2];
            u = FN(u);
            v = FN(v);
            
            if(u != v) {
                MN(u, v);
                Ans += C[0];
            }
        }
        return Ans;
    }
};
