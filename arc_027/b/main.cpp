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
#include <atcoder/all>
using namespace atcoder;

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

// int main() {
//   ll N;
//   string S1, S2;
//   cin >> N >> S1 >> S2;
//   map<char, bool> mp;
//   rep(i, N) {
//     if (isDigit(S1[i]) || isDigit(S2[i])) {
//       if (!isDigit(S1[i])) mp[S1[i]] = true;
//       if (!isDigit(S2[i])) mp[S2[i]] = true;
//     }
//   }
//   ll ans = 1;
//   // 通り数を求める
//   rep(i, N) {
//     // 数字の時は一通りに定まる
//     if (isDigit(S1[i]) || isDigit(S2[i])) continue;
//     // どちらも文字でも他で数字として決まっているものは一通りに定まる
//     if (mp.count(S1[i]) || mp.count(S2[i])) continue;
//     if (i == 0) ans *= 9;
//     else ans *= 10;
//     // 今使った文字が他の箇所で出てきてもそれは一通りに定まる
//     mp[S1[i]] = true;
//     mp[S2[i]] = true;
//     // 今決まった文字と同じと見做されるものがあればそれも一通りに定まる
//     rep3(j, i+1, N) {
//       // どちらも文字
//       if (!isDigit(S1[j]) && !isDigit(S2[j])) {
//         if (S1[i] == S1[j] || S2[i] == S1[j]) mp[S2[j]] = true;
//         if (S1[i] == S2[j] || S2[i] == S2[j]) mp[S1[j]] = true;
//       }
//     }
//     debug(mp);
//   }
//   cout << ans << endl;
//   return 0;
// }

int main(){
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;

  dsu d(100);
  // 数字は全てこの頂点とつなげる
  int num = 99;
  // int val = 'A';
  // int val2 = 'Z';
  // int val3 = '0';
  // int val4 = '9';
  // debug(val);
  // debug(val2);
  // debug(val3);
  // debug(val4);
  // 全探索
  rep(i,n){
    // どちらかが数字なら
    if(isdigit(s[i])||isdigit(t[i])){
      d.merge(s[i], num);
      d.merge(t[i], num);
    } else{
      // どちらも文字の場合は2つの文字をつなげておく
      d.merge(s[i],t[i]);
    }
  }
  debug(d.groups());
  ll ans=1;
  rep(i,n){
    // 今見ている文字が数字でない時は
    if(d.same(num,s[i])==false){
      // 通り数を掛ける
      if(i==0)ans*=9;
      else ans*=10;
      // 今の文字を数字として確定させる
      d.merge(s[i],num);
    }
  }
  cout << ans << endl;
  return 0;
}
