class Solution {
public:
    vector <vector <int>> A;
    vector <int> V;
    int wordLadderLength(string S, string T, vector<string>& W) {
        int N = W.size();
        A.resize(N + 1);
        V.resize(N + 1, 1e9);
        if(S == T)return 0;
        for (int i = 0; i < W.size(); i++) {
            for (int j = i + 1; j < W.size(); j++) {
                int ct = 0;
                for (int it = 0; it < W[i].size(); it++) {
                    if(W[i][it] != W[j][it])ct++;
                }
                if(ct == 1) {
                    A[i].push_back(j);
                    A[j].push_back(i);
                }
            }
            int ct = 0;
            for (int it = 0; it < S.size(); it++) {
                if(S[it] != W[i][it]) {
                    ct++;
                }
            }
            if(ct == 1) {
                A[N].push_back(i);
                A[i].push_back(N);
            }
        }
        V[N] = 1;
        queue <int> Q;
        Q.push(N);
        while (!Q.empty()) {
            int C = Q.front();
            Q.pop();
            for (auto v : A[C]) {
                if(V[v] == 1e9) {
                    Q.push(v);
                    V[v] = V[C] + 1;
                }
            }
        }
        int Ans = 1e9;
        for (int i = 0; i < N; i++) {
            if(W[i] == T) {
                Ans = min(Ans, V[i]);
            }
        }
        return (Ans == 1e9 ? 0 : Ans);
    }
};
