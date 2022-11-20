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

// string S[10];
// int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

// int id(int h, int w) {
//   return h * 10 + w;
// }
// bool check(int h, int w) {
//   dsu uf(100);
//   rep(i, 10) {
//     rep(j, 10) {
//       if ((i == h && j == w) || S[i][j] == 'o') {
//         rep(k, 4) {
//           int nx = i + dx[k];
//           int ny = j + dy[k];
//           if (nx < 0 || nx > 9 || ny < 0 || ny > 9) continue;
//           if (S[nx][ny] == 'o') uf.merge(id(i, j), id(nx, ny));
//         }
//       }
//     }
//   }
//   bool ok = true;
//   int first_i = -1;
//   int first_j = -1;
//   rep(i, 10) {
//     rep(j, 10) {
//       if (S[i][j] == 'o') {
//         if (first_i == -1) {
//           first_i = i;
//           first_j = j;
//         }
//         if (!uf.same(id(first_i, first_j), id(i, j))) ok = false;
//       }
//     }
//   }
//   return ok;
// }

// // 100 * 100
// int main() {
//   rep(i, 10) {
//     cin >> S[i];
//   }
//   // 全てを試して一つの連結成分にできるかを試す
//   rep(i, 10) {
//     rep(j, 10) {
//       if (check(i, j)) {
//         cout << "YES" << endl;
//         return 0;
//       }
//     }
//   }
//   cout << "NO" << endl;
//   return 0;
// }

// 深さ優先探索でも解ける
vector<int> dh={0,1,-1,0};
vector<int> dw={1,0,0,-1};
// 埋め立てるマスを起点に連結成分を探索していく
void dfs(vector<string> &s,int i,int j){
  s[i][j]='x';
  for(int k=0;k<4;k++){
    int h=i+dh[k];
    int w=j+dw[k];
    if(w<0 or h<0 or w>=10 or h>=10) continue;
    if(s[h][w]=='x') continue;
    dfs(s,h,w);
  }
  return;
}
int main(){

  vector<string> xxx(10,"xxxxxxxxxx");
  vector<string> s1(10);

  for(int i=0;i<10;i++){
    cin>>s1[i];
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      vector<string> s=s1;
        dfs(s,i,j);
        // 探索したところはxになるので全てxと一致するかを見ればよい
        if(s==xxx){
          cout<<"YES"<<endl;
          return 0;
        }
    }
  }
  cout<<"NO"<<endl;
}