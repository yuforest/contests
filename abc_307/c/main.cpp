// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int main(void){
  string a[3][10];
  char tmp[10][11];
  int h[3],w[3];
  bool flag;
  for(int k=0;k<3;k++){
    cin>>h[k]>>w[k];
    for(int i=0;i<h[k];i++)cin>>a[k][i];
  }
  // どのようにずらすかを全探索する
  // AとCは領域を1マス以上共有する必要がある
  for(int dh0=-h[0]+1;dh0<h[2];dh0++){
    for(int dw0=-w[0]+1;dw0<w[2];dw0++){
      // BとCは領域を1マス以上共有する必要がある
      for(int dh1=-h[1]+1;dh1<h[2];dh1++){
        for(int dw1=-w[1]+1;dw1<w[2];dw1++){
          // 初期化
          for(int i=0;i<h[2];i++)for(int j=0;j<w[2];j++)tmp[i][j]='.';
          flag=true;

          // AをCに重ねる
          for(int i=0;i<h[0];i++){
            for(int j=0;j<w[0];j++){
              if(a[0][i][j]=='#'){
                // #であるにもかかわらず、Cの範囲外になる場合はNG
                if(i+dh0<0)flag=false;
                if(i+dh0>=h[2])flag=false;
                if(j+dw0<0)flag=false;
                if(j+dw0>=w[2])flag=false;
                // 問題なければ重ねる
                if(flag)tmp[i+dh0][j+dw0]='#';
              }
            }
          }
          // BをCに重ねる
          for(int i=0;i<h[1];i++){
            for(int j=0;j<w[1];j++){
              if(a[1][i][j]=='#'){
                if(i+dh1<0)flag=false;
                if(i+dh1>=h[2])flag=false;
                if(j+dw1<0)flag=false;
                if(j+dw1>=w[2])flag=false;
                // 問題なければ重ねる
                if(flag)tmp[i+dh1][j+dw1]='#';
              }
            }
          }
          // 同じか調べる
          for(int i=0;i<h[2];i++){
            for(int j=0;j<w[2];j++){
              if(a[2][i][j]!=tmp[i][j])flag=false;
            }
          }

          // 同じなら終了
          if(flag){
            cout<<"Yes"<<endl;
            return 0;
          }
        }
      }
    }
  }

    cout<<"No"<<endl;
  return 0;
}
