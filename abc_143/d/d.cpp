// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_d d.cpp


#include <bits/stdc++.h>
// #define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
using namespace std;

ll MAX = 1 << 18;

#define rep(i,a,b) for(int i=a;i<b;i++)

ll X;
// int L[100007];
vector<vector<ll>> a(100007, vector<ll>());
ll ans = 0;

int N, L[2010], cnt[2010];

int main() {
  cin >> N;
  rep(i, 0, N) cin >> L[i];

  rep(i, 0, N) cnt[L[i]]++;
  rep(i, 1, 2010) cnt[i] += cnt[i - 1];

  ll ans = 0;
  rep(a, 0, N) rep(b, 0, N) if (a != b) {
    int mi = max(L[a] - L[b], L[b] - L[a]);
    int ma = L[a] + L[b];

    int cn = 0;
    if (0 <= ma - 1) cn = cnt[ma - 1];
    cn -= cnt[mi];

    // AやBで選択した棒が範囲にある時
    if (mi < L[a] and L[a] < ma) cn--;
    if (mi < L[b] and L[b] < ma) cn--;

    ans += cn;
  }
  ans /= 6;
  cout << ans << endl;
}


