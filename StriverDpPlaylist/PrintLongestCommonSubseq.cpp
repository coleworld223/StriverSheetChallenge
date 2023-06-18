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

  string s, t;
  cin >> s >> t;

  vector <vector <ll>> DP(n + 1, vector <ll> (m + 1, 0));
  vector <vector <pair <ll, ll>>> From(n + 1, vector <pair <ll, ll>> (m + 1, {0, 0}));

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      if(s[i - 1] == t[j - 1]) {
        ll NDP = 1 + DP[i - 1][j - 1];
        if(NDP > DP[i][j]) {
          DP[i][j] = NDP;
          From[i][j] = {i - 1, j - 1};
        }
      }   
      ll NDP1 = DP[i - 1][j];
      ll NDP2 = DP[i][j - 1];
      if(NDP1 > DP[i][j]) {
        From[i][j] = {i - 1, j};
        DP[i][j] = NDP1;
      }
      if(NDP2 > DP[i][j]) {
        From[i][j] = {i, j - 1};
        DP[i][j] = NDP2;
      }
    }
  }

  string Ans = "";
  pair <ll, ll> Mover = {n, m};
  while(Mover.first > 0 && Mover.second > 0) {
    pair <ll, ll> N_Place = From[Mover.first][Mover.second];
    if(N_Place.first - Mover.first == -1 && N_Place.second - Mover.second == -1) {
      Ans += s[Mover.first - 1];
    }
    Mover = N_Place;
  }
  cout << DP[n][m] << endl;
  reverse(Ans.begin(), Ans.end());
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
