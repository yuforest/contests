#include <bits/stdc++.h>
using namespace std;

const int MAX_D = 1000; // nの最大値
const int MAX_C = 5000; // Wの最大値

// 入力
int H, N;
int damages[MAX_D], costs[MAX_C];

// メモ化テーブル
// dp[i][j]はi番目以降の品物から重さの和がj以下になるように選んだ時の価値の和の最大値を表す
// -1なら値が未決定
int dp[MAX_D+1][MAX_C+1];

// i番目以降の魔法からdamageの和がj以上になるように選んだ時の、
// 取りうるcostsの総和の最小値を返す関数
int magic(int i, int j) {
  if (dp[i][j] != -1) {
    // 既に調べたことがあるならその結果を再利用
    return dp[i][j];
  }
  int res;
  if (i == N) {
    // HPがもう残っていない時は、価値の和の最大値は0で確定
    res = 0;
  } else if (j < damages[i]) {
    // 残りのHPが足りず品物iを入れられないので、入れないパターンだけ処理
    // i+1以降の品物のみを使った時の最小値をそのままこの場合の最小値にする
    res = magic(i+1, j);
  } else {
    // 魔法を使うか使わないか選べるので、両方試してcostsの和が小さい方を選ぶ
    res = min(
      magic(i + 1, j),
      magic(i + 1, j - damages[i]) + costs[i]
    );
  }
  return dp[i][j] = res;
}

int main() {
  // int A, H;
  // cin >> H >> A;
  // int ans = H / A;
  // if (H % A != 0) {
  //   cout << ans + 1 << endl;
  // } else {
  //   cout << ans << endl;
  // }

  // int H, N;
  // cin >> H >> N;
  // vector<int> A(N, 0);
  // for (int i; i < N; i++) {
  //   int val;
  //   cin >> val;
  //   A.at(i) = val;
  //   H = H - val;
  // }
  // if (H <= 0) {
  //   cout << "Yes" << endl;
  // } else {
  //   cout << "No" << endl;
  // }
  // int N, K;
  // cin >> N >> K;
  // vector<long long> H(N, 0);
  // long long ans = 0;
  // for (int i; i < N; i++) {
  //   int val;
  //   cin >> val;
  //   H.at(i) = val;
  // }
  // sort(H.begin(), H.end(), std::greater<int>());
  // if (N <= K) {
  //   cout << 0 << endl;
  // } else{
  //   for (int i; i < K; i++){
  //     H.at(i) = 0;
  //   }
  //   ans = accumulate(H.begin(), H.end(), 0LL);
  //   cout << ans << endl;
  // }
  // long long H;
  // cin >> H;
  // long long ans = 0;
  // long long pow_int = 0;
  // while (H != 0) {
  //   H = H / 2;
  //   pow_int += 1;
  // }
  // pow_int -= 1;
  // for (int i = 0; i <= pow_int; i++)
  // {
  //   ans += pow(2, i);
  // }
  // cout << ans << endl;

  cin >> H >> N;
  for (int i=0; i < N; i++) {
    double A, B;
    cin >> A >> B;
    damages[i] = A;
    costs[i] = B;
  }
  memset(dp, -1, sizeof(dp));
  cout << magic(0, H) << endl;

}