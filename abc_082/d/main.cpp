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

const ll MAXN = 8020;

int main()
{
  string s;
  cin >> s;
  int x,y;
  cin >> x >> y;

  vector<int> t;
  int cnt = 0;
  //文字列を変形する
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'T'){
      if(cnt != 0) t.push_back(cnt);
      t.push_back(0);
      cnt = 0;
    }else{
      cnt++;
      // もし文字の最後なら追加する
      if(i == s.size()-1) t.push_back(cnt);
    }
  }

  // 初期化
  vvb dp_x(MAXN,vb(MAXN*2,false)), dp_y(MAXN,vb(MAXN*2,false));
  // 最初の位置
  dp_x[0][8000] = true;
  dp_y[0][8000] = true;

  // 2回目以降かどうか
  bool flag = false;
  // trueならx軸について見ている
  // 最初はx軸の正の方向を向いている
  bool xy = true;
  int cnt_x = 0,cnt_y = 0;

  // tのサイズ分だけ行う
  for(int i = 0; i < t.size(); i++){
    // このとき軸を変える
    if(t[i] == 0){
      xy  = !xy;
    }else if(xy){
      // このときx軸について見ている
      cnt_x++;
      // 座標を全探索
      for(int j = 0; j < MAXN*2; j++){
        // 1つ前の状態がtrueなら
        if(dp_x[cnt_x-1][j]){
          // 移動可能ならtrueにする
          if(j+t[i] < MAXN*2) dp_x[cnt_x][j+t[i]] = true;
          // 最初は正の向きを向いているので、負の方向には移動できない
          if(j-t[i] >= 0 && flag) dp_x[cnt_x][j-t[i]] = true;
        }
      }
    }else if(!xy){
      // このときy軸について見ている
      cnt_y++;
      // 座標を全探索
      for(int j = 0; j < MAXN*2; j++){
        if(dp_y[cnt_y-1][j]){
          // 移動可能ならtrueにする
          if(j+t[i] < MAXN*2) dp_y[cnt_y][j+t[i]] = true;
          if(j-t[i] >= 0) dp_y[cnt_y][j-t[i]] = true;
        }
      }
    }

    // フラグが立っていないならフラグを立てる
    // つまり最初のイテレーションでフラグを立てる
    if(!flag) flag = true;
  }

  // 8000を足しているのは、負の座標を扱えるようにするため
  // 答えを出力
  // 全ての移動が終わった時に、x,yに到達できるかどうか
  cout << ((dp_x[cnt_x][x+8000] && dp_y[cnt_y][y+8000]) ? "Yes" : "No") << endl;

  return 0;
}