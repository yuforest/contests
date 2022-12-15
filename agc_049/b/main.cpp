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

// 累積XORを計算して返す関数、vectorを返す
vi imos(string s){
  int n=s.size();
  vi res(n);
  int cur=0;
  rep(i,n){
    // 1^1=0,0^1=1^0=1,0^0=0と推移する
    cur^=s[i]-'0';
    // 現在の値を入れる
    res[i]=cur;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout<<fixed<<setprecision(20);
  // 入力
  int n;cin>>n;
  string as,bs;
  cin>>as>>bs;
  // 累積XOR
  vi a=imos(as),b=imos(bs);

  debug(a);
  debug(b);

  // S_i!=Si+1なるiを選び、S_iをS_i+1で置き換える
  // つまり連続する2文字が異なるものを選んで、1文字目を2文字目で置き換える
  // 一致させるためにはS_j=T_i(j>=i)となる最小のjを探し、
  // S_j->S_j-1->S_j-2->S_iとS_jを伝播させていく
  ll ans=0;
  ll j=0;
  // 累積XORを使ってbのインデックスを順番に探索し
  // 同じになるまでaのインデックスを進める
  // このインデックスの差j-iがaをbに揃えるまでに必要な操作回数である
  // bの最後までいく前にaの最後に到達してしまったら、実現できない
  rep(i,n){
    // jはi以上である必要がある
    // もしくは前回までで進んだところのインデックスが入っている
    chmax(j,i * 1LL);
    // もし同じならcontinue
    // 何も変更する必要がない
    if(b[i]==a[j])continue;
    // jを現在見ているb[i]と同じでないところまで進める
    while(j<n&&a[j]!=b[i])j++;
    // 最後まで到達してしまったら実現できない
    debug(i);
    debug(j);
    if(j==n){
      cout << -1 << endl;
      return 0;
    }
    ans+=j-i;
  }

  cout<<ans<<endl;
}