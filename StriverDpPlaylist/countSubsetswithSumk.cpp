class Solution{

	public:
	vector <vector <long long>> DP;
	int perfectSum(int arr[], int n, int sum)
	{
        DP.resize(n + 1, vector <long long> (sum + 5, 0));
        DP[0][0] = 1;
        //DP[i][sum] = DP[i - 1][sum] + DP[i - 1][sum - arr[i]]
        int M = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if(j - arr[i - 1] >= 0) {
                    DP[i][j] += DP[i - 1][j - arr[i - 1]];
                    DP[i][j] %= M;
                }
                DP[i][j] += DP[i - 1][j];
                DP[i][j] %= M;
            }
        }
        return DP[n][sum];
	}
	  
};
