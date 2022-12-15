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

int n;
string st,tmp,ans;

int main(){
  cin>>n;
  cin>>st;
  ans=st;
  char tmp1 = 'd'^20;
  char tmp2 = 'p'^20;
  debug(tmp1);
  debug(tmp2);
  // n文字を全探索する、これはLを探索しているということ
  // 全体の計算量はO(N^2)
  // 5000^2=25000000で間に合う
  for(int i=0;i<n;i++) {
    // 文字列がdならばスキップ、pならば最初にいてほしくないので操作を行う
    // 探索していって最初にpが現れる箇所がLとして固定することができる
    // なぜならこれは反転しないと辞書順最小にならないから
    if(st[i]=='d') continue;
    // iからn文字目までを全探索
    // これはRを探索しているということになる
    // ここの計算量はO(N)
    for(int j=i;j<n;j++){
      // 現在の文字列を保存
      tmp=st;
      // i文字目からj文字目までを反転
      // これで文字の種類は変えずに180度反転したことになるので
      // あとはi文字目からj文字目までの文字の種類を現在とは別のものに変えてあげれば良い
      reverse(tmp.begin()+i,tmp.begin()+j+1);
      // i文字目からj文字目までに対して操作を行う
      for(int k=i;k<=j;k++){
        // k番目の文字列を反転させる処理
        // 'p'^'d'は20となる
        // 'd'^20='p'
        // 'p'^20='d'
        // 'p'^'d'ではXORを取ることで'p'と'd'で片方だけフラグが立っているところを調べている
        // その結果を文字にXORすることでフラグが立っていれば立てて、フラグが下がっているなら立てる
        // その結果文字を反転するという操作になる
        // 文字列反転の方法は覚えておきたい
        tmp[k]^='p'^'d';
      }
      // 辞書順に小さい方でansを更新
      debug(tmp);
      ans = min(ans, tmp);
    }
    // 最初にpが現れたところで操作をしたら終了
    break;
  }
  cout << ans << endl;
	return 0;
}