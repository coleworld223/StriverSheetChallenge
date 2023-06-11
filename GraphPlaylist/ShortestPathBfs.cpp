class Solution {
  public:
    vector <vector <int>> A;
    vector <int> V;
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        V.resize(N, -1);
        A.resize(N);
        for (int i = 0; i < M; i++) {
            A[edges[i][0]].push_back(edges[i][1]);
            A[edges[i][1]].push_back(edges[i][0]);
        }
        queue <int> Q;
        Q.push(src);
        V[src] = 0;
        while(!Q.empty()) {
            int C = Q.front();
            Q.pop();
            for (int v : A[C]) {
                if(V[v] == -1) {
                    Q.push(v);
                    V[v] = V[C] + 1;
                }
            }
        }
        return V;
    }
};
