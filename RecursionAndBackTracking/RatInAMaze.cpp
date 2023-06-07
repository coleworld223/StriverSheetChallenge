class Solution{
    public:
    bool V(int R, int C, int n) {
        return R >= 0 && C >= 0 && R < n && C < n;
    }
    vector <string> RES;
    void P(int R, int C, vector <vector <int>> &M, int n, string T, vector <vector <int>> &PV) {
        if(R == n - 1 && C == n - 1) {
            RES.push_back(T);
            return;
        }
        // cout << T << endl;
        PV[R][C] = 1;
        
        if(V(R + 1, C, n) && M[R + 1][C] == 1 && !PV[R + 1][C]) {
            T.push_back('D');
            P(R + 1, C, M, n, T, PV);
            T.pop_back();
        }
        if(V(R - 1, C, n) && M[R - 1][C] == 1 && !PV[R - 1][C]) {
            T.push_back('U');
            P(R - 1, C, M, n, T, PV);
            T.pop_back();
        }
        if(V(R, C + 1, n) && M[R][C + 1] == 1 && !PV[R][C + 1]) {
            T.push_back('R');
            P(R, C + 1, M, n, T, PV);
            T.pop_back();
        }
        if(V(R, C - 1, n) && M[R][C - 1] == 1 && !PV[R][C - 1]) {
            T.push_back('L');
            P(R, C - 1, M, n, T, PV);
            T.pop_back();
        }
        PV[R][C] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector <vector <int>> PV(n, vector <int> (n, 0));
        string T = "";
        if(m[0][0] == 0) return RES;
        P(0, 0, m, n, T, PV);
        return RES;
    }
};
