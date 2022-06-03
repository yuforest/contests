#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 998244353;
struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};

istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }


vector<int> to[200005];
mint dfs(int v) {
  mint res = 1;
  for (int u :to[v]) {
    res *= dfs(u);
  }
  return res + 1;
}
int main()
{
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  set<P> s;
  for (int i = n-1; i >=0; --i) {
    int x = p[i].first, d = p[i].second;
    while (s.size() && s.begin()->first < x+d) {
      to[i].push_back(s.begin()->second);
      s.erase(s.begin());
    }
    mint ans = 1;
    s.emplace(x, i);
  }
  mint ans = 1;
  for(auto x: s) {
    int v = x.second;
    ans *= dfs(v);
  }
  cout << ans.x << endl;

  return 0;
}