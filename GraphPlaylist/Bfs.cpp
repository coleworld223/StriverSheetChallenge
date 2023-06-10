class Solution {
  public:
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector <int> R;
        queue <int> Q;
        vector <int> vis(V);
        Q.push(0);
        vis[0] = 1;
        
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            R.push_back(cur);
            for (auto child : adj[cur]) {
                if(vis[child] == 0) {
                    Q.push(child);
                    vis[child] = 1;
                }
            }
        }
        return R;
    }
};
