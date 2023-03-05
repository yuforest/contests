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


#define maxn 2086
const int p = 1e9 + 7;
int n, m;
char s[maxn][maxn];
int ans, sum;
int a[maxn][maxn][4];
int pw[maxn * maxn];

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
  // 左から右への散らかっていないマスの累積カウント
  for(int i = 1;i <= n;i++){
    int cnt = 0;
    for(int j = 1;j <= m;j++){
      // 散らかっていないマスの総数を数えておく
      sum += s[i][j] == '.';
      if(s[i][j] == '.') cnt++;
      else cnt = 0;
      a[i][j][0] = cnt;
    }
  }
  // 右から左への散らかっていないマスの累積カウント
  for(int i = 1;i <= n;i++){
    int cnt = 0;
    for(int j = m;j;j--){
      if(s[i][j] == '.') cnt++;
      else cnt = 0;
      a[i][j][1] = cnt;
    }
  }
  // 上から下への散らかっていないマスの累積カウント
  for(int j = 1;j <= m;j++){
    int cnt = 0;
    for(int i = 1;i <= n;i++){
      if(s[i][j] == '.') cnt++;
      else cnt = 0;
      a[i][j][2] = cnt;
    }
  }
  // 下から上への散らかっていないマスの累積カウント
  for(int j = 1;j <= m;j++){
    int cnt = 0;
    for(int i = n;i;i--){
      if(s[i][j] == '.') cnt++;
      else cnt = 0;
      a[i][j][3] = cnt;
    }
  }
  pw[0] = 1;
  // 添字の数だけ照明を配置する点があったとして何通りの置き方があるか
  for(int i = 1;i < maxn * maxn;i++) pw[i] = 1ll * pw[i - 1] * 2 % p;
  // 主客転倒のテクニック
  // 散らかっていないが照らされないマスの数を求める
  // 全ての照らされるマスの合計はK*2^K通りある
  // K通りのマスに対して、今見ているマスが照らされない時の通り数を求める
  // そして最後に全ての通り数から、照らされないマスの通り数を引く
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      // 散らかっているマスは無視
      if(s[i][j] != '.') continue;
      // (a[i][j][0] + a[i][j][1] + a[i][j][2] + a[i][j][3] - 3)は、
      // そのマスを中心とした四方向の散らかっていないマスの数
      // sumから四方向の散らかっていないマスの数を引くと
      // そのマスに照明を設置した時に照らされないマスの数となる
      // あるマスが照らされないようにするには、そのマス伸びる空きますとそのマス自身には照明を設置できない
      // ただし他のマスは正面が置かれていても問題ない
      // よってそのマスから4方向に伸びる空きマスとそのマス自身を合わせた個数をTとすると
      // 2^(K-T)通りの置き方がある
      ans = (ans + pw[sum - (a[i][j][0] + a[i][j][1] + a[i][j][2] + a[i][j][3] - 3)]) % p;
    }
  }
  // 散らかっていない全てのマスが照らされる場合の数から
  // 散らかっていないが照らされないマスの数を引くと
  // 散らかっていないが照らされるマスの数となる
  // 答えが負になる場合があるのでpを足しておく
  ll val = (1ll * sum * pw[sum] + p - ans) % p;
  cout << val << endl;
}