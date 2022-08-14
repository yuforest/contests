#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {

  int N;
  cin>>N;

  vector<int> a(N);
  for(int i=0;i<N;i++)cin>>a[i];

  mint ans = 0;

  // 1~Nまでに対してそれぞれ計算する
  for(int i=1;i<=N;i++){
    // 3次元配列
    vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(i+1,vector<mint>(i,0)));
    dp[0][0][0] = 1;
    // A の先頭j項から、k個の項を選ぶ方法であって、選んだ項の総和を
    // i で割った余りが l となるようなものの個数を 998244353 で割った余り
    for(int j=0;j<N;j++){
      // 最大でi個選べる
      for(int k=0;k<=i;k++) {
        // 余りはiより小さくなる
        for(int l=0;l<i;l++) {
          // 選ばない場合
          dp[j+1][k][l] += dp[j][k][l];
          // k == j の時は次に遷移できない
          if(k != i) {
            // a[j]を選ぶ場合
            // (l+a[j])%iが次の遷移先
            dp[j+1][k+1][(l+a[j])%i] += dp[j][k][l];
          }
        }
      }
    }
    // iで割り切れる数の総数
    ans += dp[N][i][0];
  }

  cout << ans.val() << endl;

  return 0;
}
