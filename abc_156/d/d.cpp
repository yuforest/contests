// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_d d.cpp

// #include <bits/stdc++.h>
// using namespace std;
// int n, k;
// int c[300005];
// map<int, int> mp;
// long long mod = 1000000007;
// // 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
// int dp[301][301][301];
// #define rep(i, n) for (int i = 0; i < (n); ++i)
// using ll = long long;

// // long long modinv(long long a, long long m) {
// //   long long b = m, u = 1, v = 0;
// //   while (b) {
// //     long long t = a / b;
// //     a -= t * b; swap(a, b);
// //     u -= t * v; swap(u, v);
// //   }
// //   u %= m;
// //   if (u < 0) u += m;
// //   return u;
// // }

// // modであまりを取りながら累乗
// long long modpow(long long a,long long b) {
//   long long ans = 1;
//   // bが0以上
//   while(b) {
//     // この桁は二進数でbitのフラグが立っている
//     if(b & 1) {
//       ans *= a;
//       ans %= mod;
//     }
//     a *= a;
//     a %= mod;
//     b /= 2;
//   }
//   return ans;
// }

// // 逆元の計算
// long long modinv(long long a) {
//   return modpow(a, mod - 2);
// }

// ll nCk(ll n, ll k) {
//   ll x = 1; // 分子の初期値
//   ll z = 1; // 分母の初期値

//   // 分子を計算
//   for(ll i = n-k+1; i <= n; i++) {
//     x *= i;
//     x %= mod;
//   }
//   // 分母を計算(k!)
//   for(ll i = 1; i <= k; i++) {
//     z *= i;
//     z %= mod;
//   }
//   // 逆元を使って掛け算に変換する
//   ll z_inv = modinv(z);
//   // cout << z << endl;
//   // cout << z_inv << endl;

//   return (x * z_inv % mod);
// }

// int main(void)
// {
//   ll N, A, B;
//   cin >> N >> A >> B;
//   ll ans = modpow(2, N);
//   ans -= 1;
//   ans -= nCk(N, A);
//   ans -= nCk(N, B);
//   ans %= mod;
//   cout << ans << endl;
//   return 0;
// }



#include <bits/stdc++.h>
using namespace std;

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

const int MOD = 1000000007;
using mint = Fp<MOD>;

// N(N-1)...(N-K+1)/K!を計算している
mint calc(long long N, long long K) {
  mint res = 1;
  for (long long n = 0; n < K; ++n) {
    res *= (N - n);
    res /= (n + 1);
  }
  return res;
}

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  mint res = modpow(mint(2), N) - 1;
  res -= calc(N, A) + calc(N, B);
  cout << res << endl;
}