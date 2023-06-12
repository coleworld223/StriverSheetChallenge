class Solution {
  public:
    vector <vector <int>> V;
    vector <pair <int, int>> M = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    bool F(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        n = grid.size();
        m = grid[0].size();
        V.resize(n, vector <int> (m, -1));
        queue <pair <int, int>> Q;
        Q.push(source);
        V[source.first][source.second] = 0;
        while(!Q.empty()) {
            pair <int, int> C = Q.front();
            Q.pop();
            for (auto dr : M) {
                int nx = C.first + dr.first;
                int ny = C.second + dr.second;
                if(F(nx, ny) && grid[nx][ny] == 1 && V[nx][ny] == -1) {
                    V[nx][ny] = V[C.first][C.second] + 1;
                    Q.push({nx, ny});
                }
            }
        }
        return V[destination.first][destination.second];
    }
};
