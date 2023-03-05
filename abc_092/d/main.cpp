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

int a,b;
int h=100,w=100;
char grid[101][101];
int main(){
  int i,j,bl=1,wh=1;
  cin >> a >> b;
  // 上半分を白、下半分を黒で埋める
  // つまり1から50行目までを白、51から100行目までを黒で埋める
  // これで白の連結成分と黒の連結成分の数はそれぞれ1つずつになる
  for(i=1;i<=50;i++){
    for(j=1;j<=100;j++){
      grid[i][j] = '.';
      grid[i+50][j] = '#';
    }
  }
  // 黒の連結成分を増やす
  // 1行目から1行飛ばしで塗っていく
  // 3,5,7,...,99列目を塗っていく(49個)
  while(bl<b){
    // bl=1の時、grid[1][3]を黒にする
    // bl=2の時、grid[1][5]を黒にする
    // bl=3の時、grid[1][7]を黒にする
    // bl=50の時、grid[3][3]を黒にする
    // bl=100の時、grid[5][3]を黒にする
    // bl=200の時、grid[9][3]を黒にする
    // bl=300の時、grid[13][3]を黒にする
    // bl=400の時、grid[17][3]を黒にする
    // bl=500の時、grid[21][3]を黒にする
    // といった形で塗って連結成分を増やすことができる
    grid[2*(bl/50)+1][2*(bl%50)+1] = '#';
    bl++;
  }
  // 白の連結成分を増やす
  // 52行目から1行飛ばしで塗っていく
  // 3,5,7,...,99列目を塗っていく(49個)
  while(wh<a){
    // wh=1の時、grid[52][3]を白にする
    // wh=2の時、grid[52][5]を白にする
    // wh=3の時、grid[52][7]を白にする
    // wh=50の時、grid[54][3]を白にする
    // wh=100の時、grid[56][3]を白にする
    // wh=200の時、grid[60][3]を白にする
    // wh=300の時、grid[64][3]を白にする
    // wh=400の時、grid[68][3]を白にする
    // wh=500の時、grid[72][3]を白にする
    grid[2*(wh/50)+52][2*(wh%50)+1] = '.';
    wh++;
  }
  // 答えを出力する
  cout << h << ' ' <<  w << endl;
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++) cout << grid[i][j];
    cout << endl;
  }
  return 0;
}