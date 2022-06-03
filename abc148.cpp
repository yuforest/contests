#include <bits/stdc++.h>
using namespace std;

// long yugrid(long max_num, long min_num)
// {
//     long r = max_num - min_num;
//     return r;
// }

int main()
{
    // int A, B;
    // cin >> A >> B;
    // vector<int> nums{1,2,3};
    // nums.erase(remove(nums.begin(), nums.end(), A), nums.end());
    // nums.erase(remove(nums.begin(), nums.end(), B), nums.end());
    // int ans = nums.at(0);
    // cout << ans << endl;
    // int N;
    // cin >> N;
    // string S, T;
    // cin >> S >> T;
    // string ans = "";
    // for (int i = 0; i < N; i++) {
    //     ans += S.at(i);
    //     ans += T.at(i);
    // }
    // cout << ans << endl;

    // long A, B;
    // cin >> A >> B;

    // long max_num;
    // long min_num;
    // long G;

    // long A_multi_B = A * B;

    // while(true) {
    //     if (A > B)
    //     {
    //         max_num = A;
    //         min_num = B;
    //     }
    //     else
    //     {
    //         max_num = B;
    //         min_num = A;
    //     }
    //     if (A == B) {
    //         G = A;
    //         break;
    //     }
    //     A = yugrid(max_num, min_num);
    //     B = min_num;
    // }
    // long ans = A_multi_B / G;

    // cout << ans << endl;

    // int N;
    // cin >> N;
    // vector<int> blocks(N, 0);
    // for (int i; i < N; i++) {
    //     cin >> blocks.at(i);
    // }

    // int count = 0;
    // int current_index = 0;
    // int current_num = 1;

    // for (int i; i < N; i++)
    // {
    //     if (blocks.at(i) == current_num) {
    //         current_num++;
    //         continue;
    //     }
    // }
    // int ans;
    // if (current_num == 1) {
    //     ans = -1;
    // } else {
    //     ans = N - (current_num - 1);
    // }
    // cout << ans << endl;

    long N;
    long ans = 0;
    long tmp;

    cin >> N;

    // if (N%2==1) {
    //     cout << 0 << endl;
    //     return 0;
    // }
    tmp = N;
    while(tmp != 0) {
        tmp /= 5;
        ans += tmp;
    }



    cout << ans << endl;
}
