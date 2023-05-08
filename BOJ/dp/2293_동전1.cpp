#include <bits/stdc++.h>
using namespace std;
int n, k, v, dp[10001], rec[100001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        cin >> v;
        for (int j = v; j <= k; j++){
            dp[j] += dp[j - v];
        }
    }
    cout << dp[k] << '\n';
}