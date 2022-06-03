// g++ -o d.out d.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc213/tasks/abc213_d d.cpp




#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

bool used[200007];
vector<int> G[1 << 18];
vector<int> I;

void dfs(int pos) {
	used[pos] = true;
  I.push_back(pos);
	for (int i : G[pos]) {
		if (used[i] == false) dfs(i);
    if (I[I.size() - 1] != pos) {
      I.push_back(pos);
    }
	}
}

int main(void)
{
  int N;
  cin >> N;
  int A[N];
  int B[N];

  for (int i = 0; i < N - 1; i++) {
    cin >> A[i];
    cin >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  for (int i = 1; i <= N; i++) {
    sort(G[i].begin(), G[i].end());
  }

  dfs(1);
  for (int i = 0; i < I.size(); i++) {
    cout << I.at(i);
    if (i != I.size() - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}