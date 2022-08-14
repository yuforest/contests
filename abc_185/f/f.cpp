#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

// セグメント木の二項演算 (XOR 和)
int op(int a, int b) {
  return a ^ b;
}

// 単位元 (今回は 0)
int e() {
  return 0;
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  // セグメントツリーによって特定範囲の和やxorを高速に計算することができる
  segtree<int, op, e> seg(A);
  for (int q = 0; q < Q; ++q) {
    int t, x, y;
    cin >> t >> x >> y;
    --x;
    if (t == 1) {
      // 元の値
      int v = seg.get(x);

      // 変更後の値
      v ^= y;

      // 更新
      seg.set(x, v);
    }
    else {
      cout << seg.prod(x, y) << endl;
    }
  }
}