#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> p(N + 1);  // 카드팩 가격
    vector<int> dp(N + 1, 0); // dp[i] = i장을 사는 최대 금액

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + p[j]);
        }
    }

    cout << dp[N];
    return 0;
}