class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector <int> DP1(n, 1);
	    vector <int> DP2(n, 1);
	    
	    for (int i = 0; i < n; i++) {
	        for (int j = i - 1; j >= 0; j--) {
	            if(nums[j] < nums[i]) {
	                if(1 + DP1[j] > DP1[i]) {
	                    DP1[i] = DP1[j] + 1;
	                }
	            }
	        }
	    }
	    for (int i = n - 1; i >= 0; i--) {
	        for (int j = i; j < n; j++) {
	            if(nums[j] < nums[i]) {
	                if(DP2[j] + 1 > DP2[i]) {
	                    DP2[i] = 1 + DP2[j];
	                }
	            }
	        }
	    }
	    int Ans = 1;
	    for (int i = 0; i < n; i++) {
	        Ans = max(Ans, DP1[i] + DP2[i] - 1);
	    }
	    return Ans;
	}
};
