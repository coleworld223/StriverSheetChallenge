class Solution {
  public:
    vector <vector <int>> D;
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int T) {
        D.resize(n, vector <int> (n, 1e9));
        for (int i = 0; i < edges.size(); i++) {
            D[edges[i][0]][edges[i][1]] = edges[i][2];
            D[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int i = 0; i < n; i++) D[i][i] = 0;
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        
        int Ans = -1;
        int C_min = 1e9;
        for (int i = 0; i < n; i++) {
            int C = 0;
            for (int j = 0; j < n; j++) {
                if(D[i][j] <= T) {
                    C++;
                }
            }
            if(C <= C_min) {
                Ans = i;
                C_min = C;
            }
        }
        return Ans;
    }    
};
