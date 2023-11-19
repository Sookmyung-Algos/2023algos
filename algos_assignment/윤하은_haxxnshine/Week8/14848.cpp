#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#include "bits/stdc++.h"
#include "ext/rope"
 
using namespace std;
using namespace __gnu_cxx;
 
using ll = long long;
using pii = pair<int, int>;
 
int n, k;
vector<int> v;
int ans;
 
void solve()
{
  cin >> n >> k;
  ans = n;
  v.resize(k);
 
  for (int i = 0; i < k; i++)
  {
    cin >> v[i];
    if (v[i] == 1)
    {
      cout << 0;
      return;
    }
  }
 
  int mask = (1 << k) - 1;
  while (mask)
  {
    int cnt = __builtin_popcount(mask);
    ll val = 1;
    for (int i = 0; i < k; i++)
    {
      if (mask & (1 << i))
      {
        val = lcm(val, v[i]);
      }
    }
 
    if (cnt & 1) ans -= n / val;
    else ans += n / val;
    --mask;
  }
  cout << ans;
}
 
int main()
{
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
 
  solve();
}
