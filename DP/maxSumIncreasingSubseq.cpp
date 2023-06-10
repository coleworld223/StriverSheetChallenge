class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector <int> DP(n);
	    DP[0] = arr[0];
	    for (int i = 1; i < n; i++) {
	        DP[i] = arr[i];
	        for (int j = 0; j < i; j++) {
	            if(arr[j] < arr[i]) {
	                DP[i] = max(DP[i], DP[j] + arr[i]);
	            }
	        }
	    }
	    return *max_element(DP.begin(), DP.end());
	}  
};
