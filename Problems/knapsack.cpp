#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cin >> n;

    int weight[100], value[100];

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cin >> capacity;

    int dp[101][101] = {0};

    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= capacity; w++) {

            if (weight[i - 1] <= w) {

                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );

            } else {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[n][capacity];

    return 0;
}
