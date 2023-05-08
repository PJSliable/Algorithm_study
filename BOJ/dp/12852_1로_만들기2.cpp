#include <bits/stdc++.h>
using namespace std;
int n, dp[1000001];
map<int, int> mp;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> n;
    fill(dp, dp + 1000001, 1000001);
    dp[1] = 0;
    for (int i = 1; i <= n; i++){
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]){
            dp[i] = dp[i / 3] + 1;
            mp[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i/2] + 1 < dp[i]){
            dp[i] = dp[i/2] + 1;
            mp[i] = i / 2;
        }
        if (dp[i-1]+1 < dp[i]){
            dp[i] = dp[i-1]+1;
            mp[i] = i - 1;
        }
    }
    cout << dp[n] << '\n';
    while (n != 0){
        cout << n << ' ';
        n = mp[n];
    }
}