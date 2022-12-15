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
#define all(x) (x).begin(), (x).end()
#define per(i, b) per3(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define sz(x) (int)(x).size()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int N, a;
int b[100000];
int ts[100000];
string K;
int main(){
  cin >> N >> a;
  --a;
  cin >> K;

  for(int i=0;i<N;i++){
    cin >> b[i];
    --b[i];
  }

  // Kが6桁以内であればシミュレーションするだけで答えが出せる
  // 愚直解
  if(K.size() < 7){
    int k = stoi(K);
    for(int i=0;i<k;i++){
      a = b[a];
    }
    cout << a+1 << endl;
    return 0;
  }

  // tsの配列に全て-1を入れる
  memset(ts, -1, sizeof(ts));

  // tsの配列に辞書の番号に対する遷移する順番をaから順に入れていく
  int t = 0;
  // ts[a]に値が入っていない限り続ける
  for(;ts[a]==-1;){
    ts[a] = t;
    ++t;
    debug(a);
    debug(b[a]);
    a = b[a];
  }

  debug(ts[a]);
  rep(i, N) debug(ts[i]);
  // 一度通った点にたどり着くまでの移動回数-ループの始点までの移動回数
  // つまり閉路の頂点数がmodになる
  int mod = t - ts[a];
  int k = 0;
  debug(mod);

  // Kを初めから見ていって、(10k + 今の桁)をmodで割ったあまりを見ていけば
  // 最終的に最初の位置から何回遷移すれば良いのかわかる
  // modはN以下なので10^5程度となり間に合う
  // 最初から見ていき10倍しながらmodを取るのはループ回数が非常に大きい時の典型テクニック
  for(char& c : K){
    k = (k * 10 + c - '0') % mod;
  }
  // 閉路の最初の点からどれだけ移動すればよいのか求める
  // (k - ts[a])によって閉路の最初の点に移動する回数を引いている
  // (k - ts[a])は負になる可能性があるので、
  // 負にならないようにmodを足して、再度あまりを取っている
  k = ((k - ts[a]) % mod + mod) % mod;

  // k回遷移する
  for(;k>0;k--){
    a = b[a];
  }

  cout << a+1 << endl;
}