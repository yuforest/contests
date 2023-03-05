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

int main() {
  ll N;
  string S, T;
  cin >> N >> S >> T;
  string S2 = S;
  string T2 = T;
  sort(S2.begin(), S2.end());
  sort(T2.begin(), T2.end());
  if (S2 != T2) {
    cout << -1 << endl;
    return 0;
  }
  // 二部探索を行う、計算量O(NlogN)で解ける
  int l=-1,r=N+1;
  while (l+1<r){
    int mid=(l+r) / 2;
    debug(mid);
    // jは0
    int i=mid,j=0,cnt=0;
    while (i<N && j<N){
      // 文字が同じならどちらも進める
      if (S[i]==T[j]){
        i++;
        j++;
        cnt++;
      }
      // そうでなければjだけ進める
      else{
        j++;
      }
    }
    debug(cnt);
    // このときmid回以内で一致させることができる
    // Sのmid以降で文字がTと同じ個数が、midも含むmid以降の文字数と同じ時
    // つまりmid以降の文字列はTの部分列となっている必要がある
    if (cnt==N-mid){
      r=mid;
    }
    // このときmid回以上の操作が必要がある
    else{
      l=mid;
    }
  }
  cout<<r<<endl;
  return 0;
}