class Solution{
    public:
    vector <vector <int>> A;
    vector <int> V;
    string findOrder(string dict[], int N, int K) {
        V.resize(K);
        A.resize(K);
        
        for (int i = 0; i < N - 1; i++) {
            int x1 = dict[i].size();
            int x2 = dict[i + 1].size();
            for (int j = 0; j < min(x1, x2); j++) {
                if(dict[i][j] != dict[i + 1][j]) {
                    A[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                    break;
                }
            }
        }
        queue <int> Q;
        vector <int> R;
        vector <int> In(K);
        for (int i = 0; i < K; i++) {
            for (auto u : A[i]) In[u]++;
        }
        for (int i = 0; i < K; i++) {
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
        string ans = "";
        for (int i = 0; i < R.size(); i++) {
            ans.push_back(R[i] + 'a');
        }
        return ans;
    }
};
