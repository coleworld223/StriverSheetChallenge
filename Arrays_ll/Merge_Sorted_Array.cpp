class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; i--) {
          swap(nums1[i], nums1[i + n]);
        }
        int I_1 = m + n - 1 - m + 1;
        int I_2 = 0;
        int At = 0;

        while(I_1 - n < m && I_2 < n) {
          if(nums1[I_1] <= nums2[I_2]) {
            nums1[At++] = nums1[I_1++];
          }
          else{
            nums1[At++] = nums2[I_2++];
          }
        }
        while(I_1 - n < m){
          nums1[At++] = nums1[I_1++];
        }
        while(I_2 < n) {
          nums1[At++] = nums2[I_2++];
        }
        return;
    }
};
