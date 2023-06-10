// User function Template for C++

class Solution{
public:
    vector <vector <int>> V;
    vector <pair <int, int>> MM = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool F(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    void D(int R, int C, vector <vector <char>> &mat) {
        V[R][C] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (auto dr : MM) {
            int nr = R + dr.first;
            int nc = C + dr.second;
            if(F(nr, nc, n, m) && mat[nr][nc] == 'O' && V[nr][nc] == 0) {
                D(nr, nc, mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        V.resize(n, vector <int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if(mat[i][j] == 'O'){
                        D(i, j, mat);
                    }
                }
            }
        }
        vector <vector <char>> R = mat;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(R[i][j] == 'O' && V[i][j] == 0) {
                    R[i][j] = 'X';
                }
            }
        }
        return R;
        
    }
};
