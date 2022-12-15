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
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

int N;
string S;
int main() {
  cin>>N>>S;
  multiset<int>A;
  // A...ARC...Cとなっているような文字列を探索して、ブロックに分解する
  for(int i=0;i<N;i++)if(S[i]=='R') {
    int l=0;
    while(i-l-1>=0&&S[i-l-1]=='A')l++;
    int r=0;
    while(i+r+1<N&&S[i+r+1]=='C')r++;
    // rの方が小さければrの値を使う
    if(l>r)l=r;
    // lの値をinsertする
    // つまりS[i]がRであるiから見て左にあるAと右にあるCのうち小さい方を
    // それが共に1つ以上あれば挿入している
    if(l>0)A.insert(l);
  }
  debug(A);
  // tmは偶奇を管理する変数
  int ans=0,tm=0;
  // Aが空になるまでやる、貪欲法を使って解くことができる
  while(!A.empty()) {
    ans++;
    // 奇数回目の時
    if(++tm%2) {
      // 最後の要素を取得する
      auto it=A.end();it--;
      int v=*it;
      // 最後の要素を削除して
      A.erase(it);
      // vが1より大きければv-1を入れる
      // A...ARC...CのARCを削除するため1より大きければ操作を継続できる
      // 大きいものから操作していく必要がある(2以上ならば悪化しないが、単に大きいものから操作して問題ない)
      if(v>1)A.insert(v-1);
    } else {
      // 偶数回目のとき、残っている回数が最小の要素を削除する
      A.erase(A.begin());
    }
  }
  cout<<ans<<endl;
}