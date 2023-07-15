// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];


// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}


int main() {
  unsigned N, T, M;
  cin >> N >> T >> M;
  // hate[i] の j ビットめが 1 ⟹ i 番目の選手と j 番目の選手の相性が悪い (0-indexed)
  vector<unsigned> hate(N);
  for(unsigned i{}, a, b; i < M; ++i){
    cin >> a >> b;
    hate[--b] |= 1U << --a;
  }
  // 再帰関数で計算した値を出力
  cout << [dfs{[N, T, &hate](auto&& f, vector<unsigned>& teams, unsigned now) -> unsigned {
      // 最後の選手まで見て T チームに分かれていれば OK
      if(now == N) return size(teams) == T;
      unsigned ans{};
      // すでにあるチームに now 番目の選手を追加する
      for(auto&& team : teams)
          // チームに now 番目の選手と相性の悪い選手がいなければ
          if(!(team & hate[now])){
            // チームに入れる
            team ^= 1U << now;
            ans += f(f, teams, now + 1);
            // チームから外す
            team ^= 1U << now;
          }
      // チーム数に余裕があるとき、新しいチームを作る
      if(size(teams) < T){
        teams.emplace_back(1U << now);
        ans += f(f, teams, now + 1);
        teams.pop_back();
      }
      return ans;
  }}, T]{
      vector<unsigned> team;
      team.reserve(T);
      return dfs(dfs, team, 0);
  }() << endl;
  return 0;
}