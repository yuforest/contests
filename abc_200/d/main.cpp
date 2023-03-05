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

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// 鳩ノ巣原理
// 201 個の数列を、含まれる要素の総和を 200 で割った余りという 200 個のグループに分けるとき、
// 2 個以上の数列を含んだグループが少なくとも 1 つ以上存在する
// 200で割った余りにグルーピングするという少しおかしな制約に気付けるかがポイント
void output(vector<int> &a){
  cout << a.size();
  for(auto &nx : a){
    cout << ' ' << nx;
  }
  cout << '\n';
}

int main(){
  // 入力
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}

  vector<vector<int>> bk(200,vector<int>(0));
  // 8とnの小さい方、2^8=256でこれだけ探索すれば、
  int cnt = min(n,8);
  // bit全探索,全く選ばないということはないので1からスタート
  for(int i=1;i<(1<<cnt);i++){
    int sig=0;
    // 現在の数列を保存する用の配列
    vector<int> s;
    for(int j=0;j<cnt;j++){
      if(i&(1<<j)){
        s.push_back(j+1);
        // この数字を選んだ時の和を200で割った余りを計算する
        sig+=a[j];
        sig%=200;
      }
    }
    // この時点で既に余りがsigの箇所に数列があれば、実現可能なので
    // その数列とsigを出力する
    if(bk[sig].size()!=0){
      cout << "Yes\n";
      output(bk[sig]);
      output(s);
      return 0;
    }
    // 現時点で0個なら保存しておく
    else{bk[sig]=s;}
  }
  // 最後まで見つけられなければ実現不可能
  cout << "No\n";
  return 0;
}