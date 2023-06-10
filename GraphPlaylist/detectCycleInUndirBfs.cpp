class Solution {
  public:
    vector <int> V;
    bool Cycle = 0;
    void B(int N, vector <int> A[]) {
        queue <pair <int, int>> Q;
        Q.push({N, -1});
        V[N] = 1;
        while(!Q.empty()) {
            int C = Q.front().first;
            int P = Q.front().second;
            Q.pop();
            for (int v : A[C]) {
                if(V[v] == 0) {
                    V[v] = 1;
                    Q.push({v, C});
                }
                else if(v != P) {
                    Cycle = 1;
                }
            }
        }
        
    }
    bool isCycle(int N, vector<int> adj[]) {
        V.resize(N, 0);
        for (int i = 0; i < N; i++) {
            if(V[i] == 0) {
                B(i, adj);
            }
        }
        return Cycle;
    }
};
