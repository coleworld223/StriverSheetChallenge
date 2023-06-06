class Solution {
public:
    using ll = long long;
    bool F(int L, int n, int k, vector <int> &S) {
        int CT = 1;
        int P = S[0];
        for (int i = 1; i < n; i++) {
            if(S[i] - P >= L) {
                CT ++;
                P = S[i]; 
            }
        }
        return (CT >= k);
    }
    int solve(int n, int k, vector<int> &stalls) {
        ll L = 1;
        ll H = 1e9;
        sort(stalls.begin(), stalls.end());
        while(H - L > 1) {
            ll M = L + (H - L) / 2;
            if(F(M, n, k, stalls))L = M;
            else H = M;
        }
        if(F(H, n, k, stalls))return H;
        else return L;
    }
};
