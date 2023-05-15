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
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

int main(){
  int n;
  cin >> n;
  map<int,ll>tate, yoko;
  map<pair<ll, ll>,int> data;
  for(int i=0;i<n;i++){
    int x,y,c;
    cin >> x >> y >> c;
    // その行の合計値を保存
    tate[x]+=c;
    // その列の合計値を保存
    yoko[y]+=c;
    // 行と列に対する値を保存
    data[make_pair(x,y)]=c;
  }

  vector<array<ll,2>>tates,yokos;
  // 値と行をペアにして保存
  for(auto[i,v]:tate)tates.push_back({v,i});
  // 値と列をペアにして保存
  for(auto[i,v]:yoko)yokos.push_back({v,i});
  // 値の降順にソート
  sort(tates.rbegin(),tates.rend());
  sort(yokos.rbegin(),yokos.rend());

  // 行と列が与えられた時にその合計値のどちらが大きいかを返す
  auto comp=[&](array<int,2>&a,array<int,2>&b){
    return tates[a[0]][0]+yokos[a[1]][0] < tates[b[0]][0]+yokos[b[1]][0];
  };

  priority_queue<
    array<int,2>,
    vector<array<int,2>>,
    decltype(comp)
  >q{comp};

  // 全ての行と列は最初の要素からスタートする
  for(int i=0;i<tates.size();i++)q.push({i,0});

  ll ans=0;
  // 「行に含まれる数の和 ＋ 列に含まれる数の和」が大きい順に
  // N+1個を調べると、その中に必ず「行に含まれる数の和 ＋ 列に含まれる数の和 － 行と列の交点の数」
  // が最大のものが含まれます
  while(!q.empty()){
    auto [i,j]=q.top();q.pop();
    ll v=tates[i][0]+yokos[j][0];
    // この時点で答えより小さくなったらもう更新する必要はない
    if(v<=ans)break;
    // その値がある行と列を取り出す
    ll row=tates[i][1], col=yokos[j][1];
    ll cur = v-data[make_pair(row,col)];
    ans = max(ans, cur);
    // 行は固定して列を一つ進める
    if(j+1<yokos.size())q.push({i,j+1});
  }
  cout << ans << endl;
}