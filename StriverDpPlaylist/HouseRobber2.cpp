class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 1)return nums[0];
        vector <vector <int>> DP1 (N, vector <int> (2, 0));
        vector <vector <int>> DP2 (N, vector <int> (2, 0));

        DP1[0][0] = 0;
        DP1[0][1] = 0;
        for (int i = 1; i < N; i++) {
          DP1[i][0] = max(DP1[i - 1][0], DP1[i - 1][1]);
          DP1[i][1] = max(DP1[i - 1][0] + nums[i], DP1[i][1]);
        }

        DP2[0][0] = 0;
        DP2[0][1] = nums[0];
        for (int i = 1; i < N - 1; i++) {
          DP2[i][0] = max(DP2[i - 1][0],  DP2[i - 1][1]);
          DP2[i][1] = max(DP2[i - 1][0] + nums[i], DP2[i][1]);
        }
        DP2[N - 1][0] = max(DP2[N - 2][0], DP2[N - 2][1]);
        DP2[N - 1][1] = max(DP2[N - 2][0], DP2[N - 1][1]);
        int A1 = max(DP1[N - 1][0], DP1[N - 1][1]);
        int A2 = max(DP2[N - 1][0], DP2[N - 1][1]);
        return max(A1, A2);
    }
};
