//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    using ll = long long;
    bool C(ll L, int A[], int N, int M) {
        int CT = 1;
        ll G = 0;
        for (int i = 0; i < N; i++) {
            if(G + A[i] > L) {
                CT++;
                G = 0;
            }
            G += A[i];
        }
        return (CT <= M);
    }
    int findPages(int A[], int N, int M) 
    {
        ll T = 0;
        ll MX = 0;
        for (int i = 0; i < N; i++) {
            T += A[i];
            MX = max(MX, 1ll * A[i]);
        }
        if(M > N) return -1;
        ll L = MX;
        ll H = T;
        while(H - L > 1) {
            ll mid = L + (H - L) / 2;
            if(C(mid, A, N, M)) H = mid;
            else L = mid;
        }
        if(C(L, A, N, M))return L;
        else return H;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
