// ここは競プロではサボりがちです
#include <bits/stdc++.h>
using namespace std;

// デバッグ用マクロです。詳しくは https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 節操ないですが、競プロでは便利です。
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

map<int, int> mp;
long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
// #include <atcoder/all>
// using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

vector<int> Era(int n) {
  vector<int> res;
  vector<bool> isprime(n, true);  // ふるい
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2; i < n; ++i) {
    if (isprime[i]) {
      res.push_back(i);
      // 調和級数
      for (int j = i*2; j < n; j += i) {
        isprime[j] = false;
      }
    }
  }
  return res;
}

int main() {
    long long N;
    cin >> N;

    // エラトステネスのふるい、O(NlogN)
    vector<int> prs = Era(1000000);
    // debug(prs);
    debug(prs.size());

    long long res = 0;
    // qを固定して考える
    // prsの大きさを便宜上Nとすると
    // O(NlogN)
    for (long long q : prs) {
        if (q * q * q > N) break;

        // pの最大値はq-1もしくはN/q^3の小さい方である
        // 例えばN=1024, q=2の時N/q^3は128となるが、pはqよりも小さい必要があるため、
        // pmaxは1となりこのような条件を満たす素数は存在しないということになる
        long long pmax = min(q - 1, N / q / q / q);

        // pmax 以下の素数の個数を二分探索で求める、O(logN)
        long long low = -1, high = prs.size();
        while (high - low > 1) {
          long long x = (low + high) / 2;
          // lowとhighの中間の添字の値が、pmaxより大きければ上限をxまで下げる
          // 逆に同じか大きければ下限をそこまで上げる
          // lowは常に条件を満たす、highは常に満たさない
          if (prs[x] > pmax) high = x;
          else low = x;
        }
        // 満たす個数は0-indexなのでhighの方を足せば良い(low+1)
        // 仮にpmaxが1でlowが-1のままの場合highが0までくるので足される数は0になる
        res += high;
    }
    cout << res << endl;
}