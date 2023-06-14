class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set <vector <int>> S;
        vector <int> T = {0, 1, -1};
        S.insert(T);
        vector <pair <int, int>> STree;
        vector <int> Vis(V);
        int Ans = 0;
        while(!S.empty()) {
            auto vec = (*S.begin());
            S.erase(S.begin());
            
            if(vec[2] != -1 && !Vis[vec[1]]) {
                STree.push_back({vec[1], vec[2]});
                Ans += vec[0];
            }
            if(Vis[vec[1]])continue;
            Vis[vec[1]] = 1;
            for (auto u : adj[vec[1]]) {
                if(Vis[u[0]] == 0) {
                    vector <int> T = {u[1], u[0], vec[1]};
                    S.insert(T);
                }
            }
        }
        return Ans;
    }
};
