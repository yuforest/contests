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

//   int N;
//   cin>>N;
//   vector<bool> vol(N+2,false);
//   vector<int> a(N);

//   int sold = 0;
//   // 入力を受け取り最初の時点で売ってしまって良い巻を求める
//   for(int i=0;i<N;i++){
//     cin>>a[i];
//     // 重複している巻とN+2より大きい巻は売る
//     if(a[i] >= vol.size())sold++;
//     else if(vol[a[i]]) sold++;
//     else vol[a[i]] = true;
//   }

//   int L = 1;
//   int R = N+1;
//   while(true){
//     // 読めるだけ読む
//     while(vol[L])L++;
//     // 持っている巻のうち最大のものを求める
//     while(R!=0&&!vol[R])R--;
//     // 売って持ってない巻を買う
//     // 売れる本がない場合
//     if(sold>=2){
//       sold-=2;
//       vol[L] = true;
//     } else{
//       // LがRと同じか追い抜いたら終わり
//       if(L>=R)break;
//       vol[R] = false;
//       sold++;
//     }
//   }
//   // 実際にはL-1が答え
//   cout<<L-1<<endl;
//   return 0;

// }


int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  sort(a.begin(), a.end());

  int l = 0;
  int r = N+1;
  while (r - l > 1) {
    int m = (l+r) / 2;
    // m巻まで読めるか
    vector<int> v(m);
    iota(v.begin(), v.end(), 1); // v に 1, 2, ... N を設定
    vector<int> c;
    set_intersection(a.begin(), a.end(), v.begin(), v.end(), std::back_inserter(c));
    int count = c.size();
    debug(c);
    if (count + (N-count) / 2 >= m) l = m;
    else r = m;
  }
  cout << l << endl;
}