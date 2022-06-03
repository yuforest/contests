// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
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

bool is_prime(long long n) {  // is n prime or not
  for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  bool is_takahasi = false;
  for (int i = A; i <= B; i++) {
    bool tmp_prime = false;
    for (int j = C; j <= D; j++) {
      if (is_prime(i + j)) {
        tmp_prime = true;
      }
    }
    if (!tmp_prime) {
      is_takahasi = true;
    }
  }
  if (is_takahasi) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}
