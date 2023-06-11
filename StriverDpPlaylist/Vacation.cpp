#include<bits/stdc++.h>
using namespace std;


#define    ff        first
#define    ss        second
#define    ll        long long
#define    w(t)      ll t; cin >> t; while(t--)
#define    out       cout << "Case #";
/*------------------------------------------------------------------------------------------------------
   kon bola mei gata ni
   mere lund pe bajj
*/

void solve() {
  ll N;
  cin >> N;

  vector <vector <ll>> DP(N, vector <ll> (3, 0));
  vector <vector <ll>> A(N, vector <ll> (3, 0));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < 3; j++) {
      cin >> A[i][j];
    }
  }

  DP[0][0] = A[0][0];
  DP[0][1] = A[0][1];
  DP[0][2] = A[0][2];

  for (ll i = 1; i < N; i++) {
    for (ll j = 0; j < 3; j++) {
      for (ll k = 0; k < 3; k++) {
        if(k == j)continue;
        DP[i][j] = max(DP[i - 1][k] + A[i][j], DP[i][j]);
      }
    }
  }

  ll Ans = max(DP[N - 1][0], max(DP[N - 1][1], DP[N - 1][2]));
  cout << Ans << endl;
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
