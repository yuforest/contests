// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];


int main()
{
  ll N;
  cin >> N;
  ll A[N+2];
  A[0] = 0;
  A[N+1] = 0;
  ll sum = 0;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= N+1; i++) {
    sum += abs(A[i] - A[i-1]);
  }

  for (int i = 1; i <= N; i++) {
    // i番目が前後のスポットの間にある場合は全てを訪れた場合と変わらない
    if ((A[i-1] <= A[i] && A[i] <= A[i+1]) || (A[i-1] >= A[i] && A[i] >= A[i+1])) {
      cout << sum << endl;
    } else {
      // そうでなければ全てを訪れた場合からスキップした部分を飛ばすように足し引きする
      int tmp = sum - abs(A[i] - A[i-1]) - abs(A[i] - A[i+1]) + abs(A[i-1] - A[i+1]);
      cout << tmp  << endl;
    }
  }
}