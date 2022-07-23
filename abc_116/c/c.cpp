// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for(int i=a;i<b;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];
const int inf = INT_MAX / 2;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int N, H[101];
//---------------------------------------------------------------------------------------------------
int ans = 0;
void f(int L, int R) {
    // ベースケース
    if (L >= R) return;

    // 区間の最小値を検索
    int mi = inf;
    rep2(i, L, R) chmin(mi, H[i]);

    ans += mi;
    rep2(i, L, R) H[i] -= mi;

    // 現時点で0がある地点のインデックスの配列(番兵を配置)
    vector<int> zero;
    zero.push_back(-1);
    rep2(i, L, R) if(H[i] == 0) zero.push_back(i);
    zero.push_back(R);

    int n = zero.size();
    // 最初が0でもf(0, 0)となるので最初で弾かれる
    rep2(i, 0, n - 1) f(zero[i] + 1, zero[i + 1]);
}
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> N;
  rep2(i, 0, N) cin >> H[i];

  f(0, N);
  cout << ans << endl;
  return 0;
}