class Solution{
public:	
	int findMaxSum(vector<int>&arr, int n) {
	    vector <vector <long long>> DP(n, vector <long long> (2, 0));
	    DP[0][0] = 0;
	    DP[0][1] = arr[0];
	    
	    for (int i = 1; i < n; i++) {
	        DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]);
	        DP[i][1] = max(DP[i - 1][0] + arr[i], DP[i][1]);
	    }
	    return max(DP[n - 1][0], DP[n - 1][1]);
	}
};
