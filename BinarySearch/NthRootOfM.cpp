int NthRoot(int n, int m) {
  auto mul = [](int x, int n) -> long long{
    long long ret = 1;
    for (int i = 1; i <= n; i++) {
      ret *= x * 1ll;
    }
    return ret;
  };
  int lo = 1;
  int hi = 1;
  while(mul(hi, n) <= m) {
    hi *= 2;
  }

  while(hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if(mul(mid, n) > m) hi = mid;
    else lo = mid;
  }
  if(mul(lo, n) == m)return lo;
  else if(mul(hi, n) == m) return hi;
  else return -1;
}
