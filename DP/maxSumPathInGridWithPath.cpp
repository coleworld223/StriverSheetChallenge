#include<bits/stdc++.h>
using namespace std;


#define    ff        first
#define    ss        second
#define    ll        long long
#define    w(t)      ll t; cin >> t; while(t--)
#define    out       cout << "Case #";
/*------------------------------------------------------------------------------------------------------

*/

void solve() {
  ll n, m;
  cin >> n >> m;

  vector <vector <int>> G(n, vector <int> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> G[i][j];
    }
  }

  vector <vector <pair <int, pair <int, int>>>> DP(n, vector <pair <int, pair <int, int>>> (m, {0, {0, 0}}));
  DP[0][0].ff = G[0][0];
  DP[0][0].ss = {-1, -1};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(i - 1 >= 0) {
        if(DP[i - 1][j].ff + G[i][j] > DP[i][j].ff) {
          DP[i][j] = {DP[i - 1][j].ff + G[i][j], {i - 1, j}};
        }
      }
      if(j - 1 >= 0) {
        if(DP[i][j - 1].ff + G[i][j] > DP[i][j].ff) {
          DP[i][j] = {DP[i][j - 1].ff + G[i][j], {i, j - 1}};
        }
      }
    }
  }

  cout << DP[n - 1][m - 1].ff << endl;

  pair <int, int> A = {n - 1, m - 1};
  pair <int, int> B = {-1, -1};

  vector <ll> Ans;
  
  while(A != B) {
    Ans.push_back(G[A.first][A.second]);
    A = DP[A.first][A.second].ss;
  }

  reverse(Ans.begin(), Ans.end());
  for (auto val : Ans) {
    cout << val << " ";
  }
  cout << endl;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  // w(t){
  //   solve();
  // }
  solve();
  return 0;
}
