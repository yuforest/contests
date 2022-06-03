#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, K;
  string S;
  cin >> N >> K >> S;
  S.at(K-1) = tolower(S.at(K-1));
  cout << S << endl;
}