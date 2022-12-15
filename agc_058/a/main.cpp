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

// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll N;
  cin >> N;
  vl P(2*N);
  rep(i, 2*N) cin >> P[i];
  vl ans;

  // スワップ操作を関数化
  auto work=[&](int i){
    ans.push_back(i+1);
    swap(P[i], P[i+1]);
  };
  for(int i=0;i+1<2*N;){
    // 奇数回目かどうかを記録する変数
    bool tar=i%2==0;
    // 奇数回目はP[i]<P[i+1]であればどちらも1、偶数回目はP[i]>P[i+1]であればどちらも0
    // になり単にiをインクリメントするだけ
    if(tar==(P[i]<P[i+1])){
      i++;
    } else{
      // そうでない時は入れ替えの操作をする必要がある
      // iが2N-2より小さく(最後から2番目より小さい)
      // 奇数回目でP[i]<P[i+2]であればP[i+1]とP[i+2]をスワップ(どちらも1)
      // 偶数回目でP[i]>=P[i+2](実際は順列なのでP[i]>P[i+2])
      // であればP[i+1]とP[i+2]をスワップ(どちらも0)
      // この分岐に入る時点で奇数回目はP[i]>P[i+1]、偶数回目はP[i]<P[i+1]であることは確定
      // よって後はi+2との比較をしてより少ないスワップ回数で条件を達成できないか考える
      // 奇数回目でi+2の方が大きければi+1とi+2をスワップすることで2つ揃えることができる(213みたいな並びから山を作りたい)
      // 偶数回目でi+2の方が小さければi+1とi+2をスワップすることで2つ揃えることができる(231みたいな並びから谷を作りたい)
      // 上の操作で効率的に2つを1つの操作で揃えられる
      if(i+2<2*N&&tar==(P[i]<P[i+2])) work(i+1);
      // それ以外の時はP[i]とP[i+1]をスワップ
      // 上の条件に当てはまらない時
      // 奇数回目で312みたいな並びもしくは
      // 偶数回目で132みたいな並びとなる
      // この時はiとi+1を並び替えることでやはりiとi+1に関して条件を満たすことができる
      // i+2を考慮しないiとi+1の関係だけ見る方法ではほとんどの場合で問題ないが確実に2つ揃うとは言えない
      // よって弾かれることがある
      else work(i);
      // このように操作すると，i=x,x+1 で条件が満たされる
      // i,i+1で揃うので2つ進める
      i+=2;
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i) cout << " ";
    cout << ans[i];
  }
  if (ans.size() > 0) cout << endl;
}