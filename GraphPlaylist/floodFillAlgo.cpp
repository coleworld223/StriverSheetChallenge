class Solution {
public:
    bool F(int x, int y, int N, int M) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    vector<vector<int>> floodFill(vector<vector<int>>&I, int sr, int sc, int newColor) {
         int N = I.size();
         int M = I[0].size();
         vector <vector <int>> R = I;
         vector <vector <int>> V(N, vector <int> (M, 0));
         vector <pair <int, int>> MM = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}; 
         queue <pair <int, int>> Q;
         Q.push({sr, sc});
         int Oc = I[sr][sc];
         R[sr][sc] = newColor;
         V[sr][sc] = 1;
         while(!Q.empty()) {
             int x = Q.front().first;
             int y = Q.front().second;
             Q.pop();
             for (auto dr : MM) {
                 int nx = x + dr.first;
                 int ny = y + dr.second;
                 if(F(nx, ny, N, M) && R[nx][ny] == Oc && V[nx][ny] == 0) {
                     R[nx][ny] = newColor;
                     V[nx][ny] = 1;
                     Q.push({nx, ny});
                 }
             }
         }
         return R;
    }
};
