class Solution {
  public:
    vector <vector <pair <int, int>>> A;
    vector <pair <int, int>> V;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        A.resize(n + 1);
        V.resize(n + 1, {1e9, -1});
        for (int i = 0; i < m; i++) {
            A[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            A[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        V[1] = {0, -1};
        set <pair <int, int>> S;
        S.insert({0, 1});
        while(!S.empty()) {
            int C = (*S.begin()).second;
            int d = (*S.begin()).first;
            S.erase(S.begin());
            for (auto Pr : A[C]) {
                int v = Pr.first;
                int dis = Pr.second;
                if(V[v].first > d + dis) {
                    V[v] = {dis + d, C};
                    S.insert({V[v].first, v});
                }
            }
        }
        vector <int> R;
        if(V[n].first == 1e9) {
            R.push_back(-1);
            return R;
        }
        int At = n;
        while(At != -1) {
            R.push_back(At);
            At = V[At].second;
        }
        reverse(R.begin(), R.end());
        return R;
        
    }
};
