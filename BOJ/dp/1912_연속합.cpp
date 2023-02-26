#include <bits/stdc++.h>
using namespace std;
int n, a[100001], dp[2][100001];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[0][0] = a[0];
    dp[1][0] = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[0][i - 1] + a[i], a[i]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i]);
    }
    cout << dp[1][n-1];
    return 0;
}