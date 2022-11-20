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
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define fore(i, a) for (auto &i : a)

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b)
{
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b)
{
  return ((a > b) ? (a = b, true) : (false));
}

vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};

// 図を正方形状に切り抜いた配列を返す
vector<string> trim(vector<string> X) {
  int64_t N = static_cast<int64_t>(X.size());
  int64_t min_r = 1LL << 60;
  int64_t max_r = 0;
  int64_t min_c = 1LL << 60;
  int64_t max_c = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (X.at(i).at(j) == '#') {
        min_r = min(min_r, i);
        max_r = max(max_r, i);
        min_c = min(min_c, j);
        max_c = max(max_c, j);
      }
    }
  }
  vector<string> trimed_X;
  for (int64_t i = min_r; i <= max_r; i++) {
    trimed_X.push_back(X.at(i).substr(min_c, max_c - min_c + 1));
  }

  return trimed_X;
}

vector<string> rotate(vector<string> X) {
  int64_t H = static_cast<int64_t>(X.size());
  int64_t W = static_cast<int64_t>(X.at(0).size());
  // 今度は高さがWになる
  vector<string> x(W);
  // 右に90度回転させている
  for (int64_t i = 0; i < W; i++) {
    for (int64_t j = H - 1; j >= 0; j--) {
      x.at(i).push_back(X.at(j).at(i));
    }
  }

  return x;
}

bool is_same_diagram(vector<string> S, vector<string> T) {
  // それぞれの幅と高さが同じで要素も同じならtrue
  if (S.size() == T.size() && S.at(0).size() == T.at(0).size())
  {
    bool ok = true;
    for (size_t i = 0; i < S.size(); i++) {
      for (size_t j = 0; j < S.at(0).size(); j++) {
        if (S.at(i).at(j) != T.at(i).at(j)) ok = false;
      }
    }
    return ok;
  } else {
    return false;
  }
}

int main() {
  int64_t N;
  cin >> N;

  if (N == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  vector<string> S(N);
  for (auto& s : S) {
    cin >> s;
  }
  vector<string> T(N);
  for (auto& t : T) {
    cin >> t;
  }

  auto s = trim(S);
  auto t = trim(T);

  bool ok = false;
  // そのままか90度回転させた時に図形の幅と高さが一致する必要がある
  // そうでない時は同じ図形とは言えない
  if ((s.size() == t.size() && s.at(0).size() == t.at(0).size())
      || (s.size() == t.at(0).size() && s.at(0).size() == t.size())) {
    // 4回回転して揃えば良い
    for (int64_t i = 0; i < 4; i++) {
      t = rotate(t);
      if (is_same_diagram(s, t)) ok = true;
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}