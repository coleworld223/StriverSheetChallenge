class Solution{

  public:
    vector <vector <int>> DP;
	int minDifference(int arr[], int n)  {
	    int S = 0;
	    for (int i = 0; i < n; i++) S += arr[i];
	    DP.resize(n + 1, vector <int> (S + 1, 0));
	    DP[0][0] = 1;
	    for (int i = 1; i <= n; i++) {
	        DP[i][0] = 1;
	        for (int j = 1; j <= S; j++) {
	            if(j - arr[i - 1] >= 0) {
	                if(DP[i - 1][j - arr[i - 1]]) DP[i][j] = 1;
	            }
	            if(DP[i - 1][j]) DP[i][j] = 1;
	        }
	    }
	    
	    int Ans = 1e9;
	    for (int i = 0; i <= S; i++) {
	        if(DP[n][i]) {
	            Ans = min(Ans, abs(S - i - i));
	        }
	    }
	    return Ans;
	} 
};
