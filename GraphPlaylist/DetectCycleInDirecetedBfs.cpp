class Solution {
  public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector <int> V(N, 0);
        vector <int> In(N, 0);
        
        for (int i = 0; i < N; i++) {
            for (int v : adj[i]) {
                In[v]++;
            }
        }
        queue <int> Q;
        vector <int> R;
        for (int i = 0; i < N; i++) {
            if(In[i] == 0) {
                V[i] = 1;
                Q.push(i);
            }
        }
        while(!Q.empty()) {
            int C = Q.front();
            Q.pop();
            R.push_back(C);
            for (int u : adj[C]) {
                if(V[u] == 1)continue;
                In[u]--;
                if(In[u] == 0) {
                    Q.push(u);
                    V[u] = 1;
                }
            }
        }
        return (R.size() != N);
    }
};
