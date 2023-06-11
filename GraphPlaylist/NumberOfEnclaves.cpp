class Solution {
  public:
    vector <vector <int>> V;
    vector <pair <int, int>> MM = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int N, M;
    bool F(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        N = grid.size();
        M = grid[0].size();
        V.resize(N, vector <int> (M, 0));
        queue <pair <int, int>> Q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(i == 0 || j == 0 || i == N - 1 || j == M - 1) {
                    if(grid[i][j] == 1) {
                        Q.push({i, j});
                        V[i][j] = 1;
                    }
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
                if(F(nx, ny) && grid[nx][ny] == 1 && V[nx][ny] == 0) {
                    V[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
        int c = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(grid[i][j] == 1 && V[i][j] == 0)c++;
            }
        }
        return c;
    }
};
