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

#define yes "Yes"
#define no "No"

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// ランレングス圧縮を行う関数
vector<pair<char, int>> runLengthEncoding(string S) {
  int N = S.length();

  vector<pair<char, int>> res;

  for(int i = 0; i < N;) {
    int j = i;
    while(j < N && S[i] == S[j]) j++;
    int count = j - i;
    res.push_back({ S[i], count });
    i = j;
  }
	return res;
}



int main(){
  // 区間に含まれる0のグループがK以下である区間の最大長を求める問題
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  auto blocks = runLengthEncoding(S);
  debug(blocks);
  int M = blocks.size();
  int ans = 0;
  int sm = 0;
  int L = 0;
  int zero = 0;
  // しゃくとり法を行う
  rep3(R, 0, M) {
    // smは連続する数字の数を示している
    sm += blocks[R].second;
    if (blocks[R].first == '0') zero++;

    // 0区間がK以下になるまでLを増やす
    while (K < zero) {
      sm -= blocks[L].second;
      if (blocks[L].first == '0') zero--;
      L++;
    }

    chmax(ans, sm);
  }
  cout << ans << endl;

  return 0;
}


// 累積和でも解ける
// int main() {
//   int N, K; cin >> N >> K;
//   string S; cin >> S;

//   // 「1 の個数」「0 の個数」を交互に記録していく
//   vector<int> nums;
//   // 紛らわしさを防ぐために、両端が「1」じゃないならば、両端に「0 個の 1」があるものとみなして0を書いておく
//   // これによって下記のようにインデックスを定めることができる
//   // 0, 2, 4, ... 番目の値は「連続する 1 の個数」
//   // 1, 3, 5, ... 番目の値は「連続する 0 の個数」
//   // 下手に場合分けしたりせずに、同じコードで扱えるようにデータ構造に前処理を加える
//   if (S[0] == '0') nums.push_back(0); // 先頭が 0 だったら
//   for (int i = 0; i < S.size();) {
//     int j = i;
//     while (j < S.size() && S[j] == S[i]) ++j; // S[i] の数値がどこまで続くか
//     nums.push_back(j - i);
//     i = j;
//   }
//   if (S.back() == '0') nums.push_back(0); // 最後尾が 0 だったら

//   // 累積和(sums[0]は常に0、numsのサイズは最初や最後に0があるかで変わるので、そのサイズで初期化)
//   vector<int> sums((int)nums.size() + 1, 0);
//   for (int i = 0; i < nums.size(); ++i) sums[i+1] = sums[i] + nums[i];

//   // 偶数番目()の添字から始まる、長さ 2K+1 (以下) の区間の総和のうち、最大値を求める
//   // 求める範囲は1に囲まれた範囲になるため(最初や最後が0なら次の1の範囲と繋げることでより大きい連続文字列を作ることができる)
//   // 2K+1の区間は間に0の区間をK個含んでいる
//   int res = 0;
//   for (int left = 0; left < sums.size(); left += 2) {
//     int right = left + K*2+1;
//     // rightが最後を超えてしまった場合はrightを累積和配列の最後に更新
//     if (right >= sums.size()) right = (int)sums.size() - 1;
//     res = max(res, sums[right] - sums[left]);
//   }
//   cout << res << endl;
// }