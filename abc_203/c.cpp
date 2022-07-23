#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

long long int N, M, K, T, H, W, L, R;

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  vector<pair<ll, ll>> villages;
  rep(i, N) {
    cin >> A[i] >> B[i];
    pair<ll, ll> tmp = {A[i], B[i]};
    villages.push_back(tmp);
  }
  sort(villages.begin(), villages.end());
  // rep(i, N) {
  //   cout << villages[i].first << endl;
  //   cout << villages[i].second << endl;
  // }
  ll ans = K;
  ll index = 0;
  while(index < N) {
    ll next_village = villages[index].first;
    if (ans >= next_village) {
      ans += villages[index].second;
      index++;
    } else {
      break;
    }
  }
  cout << ans << endl;
}


// 10 1000000000
// 1 1000000000
// 2 1000000000
// 3 1000000000
// 4 1000000000
// 5 1000000000
// 6 1000000000
// 6 1000000000
// 6 1000000000
// 6 1000000000
// 6 1000000000


