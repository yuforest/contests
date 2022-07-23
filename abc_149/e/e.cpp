#include <iostream>
using namespace std;

long long solve(long long N) {
  if (N % 2 == 1) return 0;

  long long res = 0;
  N /= 2;
  while (N) {
    res += N / 5;
    N /= 5;
  }
  return res;
}

int main() {
  long long N; cin >> N;
  cout << solve(N) << endl;
}