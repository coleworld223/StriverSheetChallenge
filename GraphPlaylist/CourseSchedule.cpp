class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> p) 
    {
        vector <vector <int>> A(n);
        vector <int> V(n);
        for (int i = 0; i < m; i++) {
            A[p[i][1]].push_back(p[i][0]);
        }
        vector <int> R;
        queue <int> Q;
        vector <int> In(n);
        for (int i = 0; i < n; i++) {
            for (int u : A[i]) In[u]++;
        }
        for (int i = 0; i < n; i++) {
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
        if(R.size() == n) {
            return R;
        }
        else{
            return {};
        }
    }
};
