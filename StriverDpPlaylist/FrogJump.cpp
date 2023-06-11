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
  ll n, k;
  cin >> n >> k;

  vector <ll> h(n);
  for (ll i = 0; i < n; i++) {
    cin >> h[i];
  }

  vector <ll> DP(n, 1e12);
  //min Cost to reach ith stone
  DP[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if(i - j >= 0) {
        DP[i] = min(DP[i], DP[i - j] + abs(h[i] - h[i - j]));
      }
    }
  }
  cout << DP[n - 1] << endl;
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
