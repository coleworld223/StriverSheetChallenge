class Solution {
  public:
     vector <vector <pair <int, int>>> A;
     vector <int> V;
     stack <int> S;
     void D(int u) {
         V[u] = 1;
         for (auto v : A[u]) {
             if(V[v.first] == 0) {
                 D(v.first);
             }
         }
         S.push(u);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        V.resize(N);
        A.resize(N);
        for (int i = 0; i < M; i++) {
            A[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        for (int i = 0; i < N; i++) {
            if(V[i] == 0) {
                D(i);
            }
        }
        
        vector <int> T;
        while(!S.empty()) {
            T.push_back(S.top());
            S.pop();
        }
        
        V.assign(N, 1e9);
        V[0] = 0;
        for (int i = 0; i < N; i++){
            if(V[T[i]] == 1e9){
                continue;
            }
            for (auto v : A[T[i]]) {
                V[v.first] = min(V[v.first], V[T[i]] + v.second); 
            }
        }
        for (int i = 0; i < N; i++) {
            if(V[i] == 1e9) V[i] = -1;
        }
        return V;
    }
};
