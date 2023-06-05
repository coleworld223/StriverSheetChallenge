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

void solve(){
  ll n;
  cin >> n;

  vector <ll> v(n);
  for (ll i = 0; i < n; i++){
    cin >> v[i];
  }
  for (auto val : v){
    cout << v[i] << " ";
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
