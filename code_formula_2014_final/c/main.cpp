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
const ll INF = ll(1e18);

// int main() {
//   string line;
//   getline(cin, line);
//   int index = 0;
//   vs S;
//   int N = line.size();
//   while(index < N) {
//     if (line[index] == ' ') {
//       index++;
//       continue;
//     }
//     if (line[index] != '@') {
//       index++;
//       continue;
//     }
//     if (line[index] == '@' && index != N-1 && line[index+1] == '@') {
//       index++;
//       continue;
//     }

//     debug(index);
//     string tmp = "";
//     do {
//       tmp += line[index];
//       index++;
//     } while(line[index] != ' ' && line[index] != '@' && index < N);
//     S.push_back(tmp);
//   }
//   debug(S);
//   set<string> st;
//   rep(i, S.size()) {
//     string tmp = S[i].substr(1, S[i].size()-1);
//     if (!tmp.empty()) st.insert(tmp);
//   }
//   for(auto s: st) {
//     cout << s << endl;
//   }
// }

int main() {
  char c = ' ';
  set<string> namelist;
  while (c != '\n'){
    debug(c);
    if (c == '@'){
      string S;
      while ('a' <= (c = getchar()) && c <= 'z') S += c;
      if (S != "") namelist.insert(S);
    } else c = getchar();
  }
  for (string name: namelist) cout << name << endl;
}