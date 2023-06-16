class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int N = arr.size();
        vector <vector <int>> DP(N, vector <int> (max(sum, arr[0]) + 1, 0));
        DP[0][arr[0]] = 1;
        DP[0][0] = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= sum; j++) {
                if(j - arr[i] >= 0) {
                    if(DP[i - 1][j - arr[i]]) DP[i][j] = 1;
                }
                if(DP[i - 1][j]) DP[i][j] = 1;
            }
        }
        return DP[N - 1][sum];
    }
};
