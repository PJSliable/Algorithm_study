#include <bits/stdc++.h>
using namespace std;
int n, k, v, dp[10001], INF = 987654321;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> n >> k;
    fill(dp, dp + 10001, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++){
        cin >> v;
        for (int j = v; j <= k; j++){
            dp[j] = min(dp[j - v] + 1, dp[j]);
        }
    }
    cout << (dp[k] == INF ? -1 : dp[k]) << '\n';
}

// g++ -std=c++14 -Wall 7week/2294.cpp -o test.out