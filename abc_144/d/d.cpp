// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];

using namespace std;

// 別解: 二分探索
// const double PI = acos(-1.0);
// double a, b, x;
// cin >> a >> b >> x;
// x /= a;
// auto f = [&](double t) {
//     // 前者
//     if (tan(t) <= b/a) return a*b - a*(a*tan(t))/2;
//     // 後者
//     else return b*(b/tan(t))/2;
// };
// double left = 0, right = PI/2;
// for (int iter = 0; iter < 100; ++iter) {
//     double theta = (left + right) / 2;
//     if (f(theta) >= x) left = theta;
//     else right = theta;
// }
// cout << fixed << setprecision(10) << left*180/PI << endl;

int main() {
    const double PI = acos(-1.0);
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;
    cout << fixed << setprecision(10);
    if (x > a*b/2) cout << atan2((a*b-x)*2, a*a) * 180 / PI << endl;
    else cout << atan2(b*b, x*2) * 180 / PI << endl;
}