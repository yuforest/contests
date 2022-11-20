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
// usng namespace atcoder;

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


template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int main() {
  long long N; cin >> N;
    long long K = 1;
    bool exist = false;
    for (K = 1; K <= N; ++K) {
      if (K * (K+1) / 2 == N) {
        exist = true;
        break;
      }
    }
    if (!exist) puts("No");
    else {
      puts("Yes");
      cout << K+1 << endl;
      // 2次元配列
      vector<vector<long long> > res(K+1, vector<long long>());
      long long sum = 1;
      // 例えばN=10の時K=4
      // Kは配列の要素数
      for (int k = K; k >= 1; --k) {
        for (int i = 0; i < k; ++i) {
          // 同じ数は2回まで使える
          // N=10の時
          // k=4,i=0の時は添字が0と1の配列に追加される(追加される数は1)
          // k=4,i=1の時は添字が0と2の配列に追加される(追加される数は2)
          // k=4,i=2の時は添字が0と3の配列に追加される(追加される数は3)
          // k=4,i=3の時は添字が0と4の配列に追加される(追加される数は4)
          // k=3,i=0の時は添字が1と2の配列に追加される(追加される数は5)
          // k=3,i=1の時は添字が1と3の配列に追加される(追加される数は6)
          // k=3,i=2の時は添字が1と4の配列に追加される(追加される数は7)
          // k=2,i=0の時は添字が2と3の配列に追加される(追加される数は8)
          // k=3,i=1の時は添字が2と4の配列に追加される(追加される数は9)
          // k=1,i=0の時は添字が3と4の配列に追加される(追加される数は10)
          res[K-k].push_back(sum + i);
          res[K-k + i + 1].push_back(sum + i);
        }
        // 1の次は5となる(1+4)
        // 5の次は3となる(5+3)
        // 8の次は10となる(8+2)
        // 10の次は11となるがこの後にループは行われない(10+1)
        sum += k;
      }
      for (int i = 0; i < K+1; ++i) {
        cout << res[i].size();
        for (int j = 0; j < res[i].size(); ++j) cout << " " << res[i][j];
        cout << endl;
      }
    }
}
