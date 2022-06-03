// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc232/tasks/abc232_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc232/tasks/abc232_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

int main() {
    int n, m;
    cin >> n >> m;
    vector x(n, vector<bool>(n)), y(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a -= 1, b -= 1;
        x[a][b] = x[b][a] = true;
    }
    for (int i = 0; i < m; ++i) {
        int c, d;
        cin >> c >> d;
        c -= 1, d -= 1;
        y[c][d] = y[d][c] = true;
    }
    vector<int> p(n);
    iota(begin(p), end(p), 0);
    do {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (x[i][j] != y[p[i]][p[j]]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << "Yes\n";
            return 0;
        }
    } while (next_permutation(begin(p), end(p)));
    cout << "No\n";
}
