#include<iostream>
#include<vector>

using namespace std;

struct UnionFind {
  // 根を入れる配列
  vector<int> p;
  UnionFind(int n) {
    p.resize(n, -1);
  }

  int find(int x) {
    if (p[x] == -1) return x;
    // 親を更新して
    else {
      p[x] = find(p[x]);
      return p[x];
    }
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    // 親を書き換え
    p[x] = y;
  }
};

int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  UnionFind uf(n);
  for(int i = 0; i < q; i++) {
    cin >> com >> x >> y;
    if (com == 0) {
      uf.unite(x, y);
    }
    if (com == 1) {
      if (uf.find(x) == uf.find(y)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}