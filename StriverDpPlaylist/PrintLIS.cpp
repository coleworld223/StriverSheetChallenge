#include<bits/stdc++.h>
using namespace std;


#define    ff        first
#define    ss        second
#define    ll        long long
#define    w(t)      ll t; cin >> t; while(t--)
#define    out       cout << "Case #";
/*------------------------------------------------------------------------------------------------------

*/

void solve () {
  ll n; cin >> n;
  vector <ll> V(n);
  for (ll i = 0; i < n; i++) cin >> V[i];

  vector <pair <ll, ll>> DP(n);
  //DP[i] = {longest till i, prev}
  DP[0] = {1, 0};

  for (ll i = 1; i < n; i++) {
    DP[i] = {1, i};
    for (ll j = i - 1; j >= 0; j--) {
      if(V[j] < V[i]) {
        if(DP[j].first + 1 > DP[i].first) {
          DP[i] = {DP[j].first + 1, j};
        }
      }
    }
  }

  ll Ans = 1;
  ll idx = 0;
  for (ll i = 0; i < n; i++) {
    if(Ans < DP[i].first) {
      Ans = DP[i].first;
      idx = i;
    }
  }
  
  vector <ll> LIS;
  while(DP[idx].second != idx) {
    LIS.push_back(V[idx]);
    idx = DP[idx].second;
  }

  LIS.push_back(V[idx]);

  cout << Ans << endl;
  reverse(LIS.begin(), LIS.end());
  for (ll i = 0; i < LIS.size(); i++) {
    cout << LIS[i] << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  w(t){
    solve();
  }
  //solve();
  return 0;
}
