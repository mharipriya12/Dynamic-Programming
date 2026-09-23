#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int p[100];

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int dp[100][100];

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << dp[1][n];

    return 0;
}
