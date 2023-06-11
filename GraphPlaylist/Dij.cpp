class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector <int> vis(V, 1e9);
        set <pair <int, int>> st;
        st.insert({0, S});
        vis[S] = 0; 
        
        while(!st.empty()){
            auto C = (*(st.begin()));
            st.erase(st.begin());
            // cout << C.second << " " << C.first << endl;
            for (auto u : adj[C.second]) {
                if(vis[u[0]] > C.first + u[1]) {
                    st.insert({C.first + u[1], u[0]});
                    vis[u[0]] = C.first + u[1];
                }
            }
            // P(vis);
        }
        return vis;
    }
};
