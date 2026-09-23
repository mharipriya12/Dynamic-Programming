#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    cin >> n;

    int coins[100];

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cin >> amount;

    int dp[1001];

    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {

        for (int j = 0; j < n; j++) {

            if (coins[j] <= i) {
                dp[i] = min(
                    dp[i],
                    dp[i - coins[j]] + 1
                );
            }
        }
    }

    if (dp[amount] > amount) {
        cout << -1;
    } else {
        cout << dp[amount];
    }

    return 0;
}
