class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector <int> DP(V + 1, 1e9);
	    DP[0] = 0;
	    for (int i = 1; i <= V; i++) {
	        for (int j = 0; j < M; j++) {
	            if(i - coins[j] >= 0) {
	               if(DP[i - coins[j]] != 1e9) 
	                   DP[i] = min(DP[i], DP[i - coins[j]] + 1);
	            }
	        }
	    }
	    
	    return DP[V] == 1e9 ? -1 : DP[V];
	} 
	  
};
