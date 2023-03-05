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
  int n;
  scanf("%d", &n);
  // ペアの個数を数えるためのmap
  map<pair<int,int>, int> cnt;
  // 2^a*5^bとしてa+a'>=0 && b+b'>=0となる時に2つの数の積は整数となる
  for(int rep = 0; rep < n; ++rep) {
    double x;
    scanf("%lf", &x);
    // 全ての数を整数として扱うために1e9をかけて四捨五入する
    long long i = llround(x * 1e9);
    debug(i);
    int two = 0, five = 0;
    // その数を2で割れるだけ割って2の個数を数える
    while(i % 2 == 0) {
      two++;
      i /= 2;
    }
    // その数を5で割れるだけ割って5の個数を数える
    while(i % 5 == 0) {
      five++;
      i /= 5;
    }
    // この数の2の個数と5の個数をペアとしてmapに保存する
    ++cnt[{two,five}];
  }
  debug(cnt);
  long long answer = 0;
  // このmapを2重ループで回す
  // cntの個数は2と5の10^13くらいまでのペアなので大した数にはならない
  // O(log(10^13))
  for(auto p1 : cnt) {
    for(auto p2 : cnt) {
      // 2の個数と5の個数の合計がそれぞれ18以上であれば、
      // 2つの数にそれぞれ1e9をかけているので、2の因数の合計と5の因数の合計がそれぞれ18以上である
      // 必要がある
      if(p1.first.first+p2.first.first >= 18 && p1.first.second+p2.first.second >= 18) {
        // 2つのペアが異なれば、その2つのペアの個数を掛け合わせる
        // ここでp1 > p2の場合は重複して数えることになるので、答えに足さない
        if(p1 < p2) {
          answer += (long long) p1.second * p2.second;
        }
        // 2つのペアが同じであれば、その中から2つを選ぶ組み合わせを数える
        // nC2 = n(n-1)/2
        else if(p1 == p2) {
          answer += (long long) p1.second * (p1.second - 1) / 2;
        }
      }
    }
  }
  printf("%lld\n", answer);
}