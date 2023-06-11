class Solution {
  public:
    vector<int> eventualSafeNodes(int N, vector<int> adj[]) {
        vector <int> V(N);
        vector  <int> In(N);
        vector <vector <int>> A (N);
        for (int i = 0; i < N; i++) {
            for (int u : adj[i]){
                A[u].push_back(i);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int u : A[i]) In[u]++;
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
                    Q.push(u);
                    V[u] = 1;
                }
            }
        }
        sort(R.begin(), R.end());
        return R;
    }
};
