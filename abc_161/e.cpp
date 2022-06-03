#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K, C;
  string S;
  cin >> N >> K >> C >> S;
  auto getPositions = [&]() {
    vector<int> res;
    for (int i = 0; i < n && res.size() < K;) {
      if (S[i] == 'o') {
        res.push_back(i);
        i += C+1;
      } else {
        i++;
      }
    }
    return res;
  };
  vector<int> l, r;
  auto res = getPositions();
  reverse(s.begin(), s.end());
  r = getPositions();
  rep(i, K) r[i] = n-1-r[i];
  reverse(s.begin(), s.end());
  vector<int> lastL(N);
  rep(i, K) lastL[l[i]+1] = i;
  rep(l, N) {
    if (lastL[i+1] == -1) lastL[i+1] = lastL[i];
  }
  rep(i, K) lastR[r[i]+1] = i;
  for (int i = n-1; i >= 0; --i) {
    if (lastR[i+1] == -1) lastR[i+1] = lastR[i];
  }

  rep(i, n) {
    if (s[i] == 'x') continue;

  }
  return 0;
}