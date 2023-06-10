class Solution 
{
    public:
    vector <vector <int>> V;
    vector <pair <int, int>> MM = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool F(int x, int y, int N, int M) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        V.resize(N, vector <int> (M, -1));
        queue <pair <int, int>> Q;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++) {
                if(grid[i][j] == 2) {
                    Q.push({i, j});
                    V[i][j] = 0;
                }
            }
        }
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for (auto dr : MM) {
                int nx = x + dr.first;
                int ny = y + dr.second;
                if(F(nx, ny, N, M) && grid[nx][ny] == 1 && V[nx][ny] == -1) {
                    Q.push({nx, ny});
                    V[nx][ny] = V[x][y] + 1;
                }
            }
        }
        int Ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(grid[i][j] == 1 && V[i][j] == -1) {
                    return -1;
                }
                Ans = max(Ans, V[i][j]);
            }
        }
        return Ans;
    }
};
