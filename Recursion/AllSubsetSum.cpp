class Solution
{
public:
    vector <int> ans;
    void AllSubset(int i, vector <int> &temp, vector <int> &arr) {
        if(i == arr.size()){
            int sum = 0;
            for (auto ele : temp) sum += ele;
            ans.push_back(sum); return;
        }
        temp.push_back(arr[i]);
        AllSubset(i + 1, temp, arr);
        temp.pop_back();
        AllSubset(i + 1, temp, arr);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector <int> temp;
       AllSubset(0, temp, arr);
       sort(ans.begin(), ans.end());
       return ans;
    }
};
