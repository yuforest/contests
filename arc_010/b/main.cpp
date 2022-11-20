// ここは競プロではサボりがちです
#include <bits/stdc++.h>
using namespace std;

// デバッグ用マクロです。詳しくは https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 節操ないですが、競プロでは便利です。
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

map<int, int> mp;
long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
// #include <atcoder/all>
// using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

#define yes "Yes"
#define no "No"

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int ans[2010];


ll id(ll month, ll day) {
  ll days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  ll sum_days = 0;
  rep(i, month-1) {
    sum_days += days[i];
  }
  sum_days += day;
  return sum_days-1;
}

int main() {
  ll N;
  cin >> N;
  vl m(N);
  vl d(N);
  rep(i, N) {
    string date;
    cin >> date;
    string delimiter = "/";
    string month = date.substr(0, date.find(delimiter));
    string day = date.substr(date.find(delimiter)+1, date.size());
    m[i] = stoll(month);
    d[i] = stoll(day);
  }
  vector<int> v(N);
	iota(v.begin(), v.end(), 0);
  sort(v.begin(), v.end(), [&](int i, int j) {
    if (m[i] == m[j]) {
      return d[i] < d[j];
    } else {
      return m[i] < m[j];
    }
  });
  debug(v);
  debug(m);
  debug(d);
  ll current = 0;
  vb calendar(366, false);
  rep(i, 366) {
    if (i % 7 == 0) {
      calendar[i] = true;
    }
    if (i % 7 == 6) {
      calendar[i] = true;
    }
  }
  rep(j, N) {
    ll date_id = id(m[j], d[j]);
    if (calendar[date_id]) {
      while(calendar[date_id]) date_id++;
    }
    calendar[date_id] = true;
  }
  ll ans = 0;
  ll tmp = 0;
  rep(i, 366) {
    if (calendar[i]) {
      tmp++;
    } else {
      chmax(ans, tmp);
      tmp = 0;
    }
  }
  chmax(ans, tmp);
  debug(calendar);
  cout << ans << endl;
}


