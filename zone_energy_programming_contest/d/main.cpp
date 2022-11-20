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

// 遅めの解法
// int main() {
//   string S;
//   cin >> S;
//   int N = S.size();
//   string T = "";
//   bool reversed = false;
//   rep(i, N) {
//     if (S[i] == 'R') {
//       reversed = !reversed;
//       continue;
//     }
//     if (!reversed) {
//       T += S[i];
//       if (T[T.size()-1] == T[T.size()-2]) T = T.substr(0, T.size()-2);
//     } else {
//       T = S[i] + T;
//       if (T[0] == T[1]) T = T.substr(2, T.size()-2);
//     }
//   }
//   if (reversed) reverse(T.begin(),T.end());
//   cout << T << endl;
// }

int main(){
  string S;
  cin >> S;

  deque<char> deq;
  bool rev = false;

  // 重複を消す前の文字の入ったdequeの構築
  fore(c, S) {
    if (c == 'R') rev = !rev;
    else {
      if (rev) deq.push_front(c);
      else deq.push_back(c);
    }
  }

  // 終わった時に反対を向いていれば逆向きにする操作
  if (rev) {
    deque<char> deq2;
    while (!deq.empty()) {
      deq2.push_back(deq.back());
      deq.pop_back();
    }
    deq = deq2;
  }

  deque<char> ans;
  while (!deq.empty()) {
    // 前から見ていく
    char c = deq.front();
    deq.pop_front();

    // ansに前回入れた値と同じであれば、ansの最後も削除
    // そうでなければ今回の値を挿入
    if (!ans.empty() && ans.back() == c) {
      ans.pop_back();
    } else {
      ans.push_back(c);
    }
  }

  string T = "";
  while (!ans.empty()) {
    T += ans.front();
    ans.pop_front();
  }
  cout << T << endl;
}