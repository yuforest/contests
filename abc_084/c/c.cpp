// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N, C[505], S[505], F[505];
  cin >> N;
  // N-1まで
  N--;
  rep(i, N) cin >> C[i] >> S[i] >> F[i];

  rep(i, N) {
    int ans = 0;
    // この駅からN駅までをシミュレーション
    for(int j = i; j < N; j++) {
      // 現在の答えより最初の発車時刻が大きければ更新
      // 発車時刻まで待つということ
      ans = max(ans, S[j]);

      int d = ans;
      // 割り切れないなら次の鉄道を待つ
      // 周期から既に経過した時間をひいている
      if (d % F[j]) d = F[j] - (d % F[j]);
      // 駅に到着した時間をFで割り切れるならそのまま乗れる
      else d = 0;

      // 待ち時間+次の列車の移動時間
      ans += d + C[j];
    }
    cout << ans << endl;
  }
  cout << 0 << endl;
}