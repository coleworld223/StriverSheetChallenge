#include<bits/stdc++.h>
using namespace std;

#define    ff        first
#define    ss        second
#define    ll        long long
#define    w(t)      ll t; cin >> t; while(t--)
#define    out       cout << "Case #";
/*------------------------------------------------------------------------------------------------------
  kavi time kavi paisa kam roz k chonchle . . .
*/

//This is test code from my codeforces submissions just to check and test if i can add a cpp code in this repo and it is working fine
void solve(){
  ll n, m;
  cin >> n >> m;

  vector <vector <ll>> v(n + 1, vector <ll> (m + 1));

  if(n % 2 == 0 ||  m % 2 == 0){
    if(m % 2 == 0){
      ll at = 1;
      for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= m; j++){
          cout << at << " ";
          at++;
        }
        cout << endl;
      }
    }
    else{
      ll at = 1;
      for (ll j = 1; j <= m; j++){
        for (ll i = 1; i <= n; i++){
          v[i][j] = at++;
        }
      }
      for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
          cout << v[i][j] << " ";
        }
        cout << endl;
      }
    }

  }
  else{
    ll at1 = 1;
    for (ll i = 1; i <= n; i++){
      for (ll j = 1; j <= m; j++){
        v[i][j] = at1++;
      }
    }

    ll at = n;
    ll at2 = n / 2;

    vector <vector <ll>> ans;
    vector <ll> temp;
    ans.push_back(temp);

    while(at2 >= 1){
      ans.push_back(v[at]);
      ans.push_back(v[at2]);
      at--;
      at2--;
    }
    ans.push_back(v[n / 2 + 1]);
    for (ll i = 1; i <= n; i++){
      for (ll j = 1; j <= m; j++){
        cout << ans[i][j] <<  " ";
      }
      cout << endl;
    }

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
