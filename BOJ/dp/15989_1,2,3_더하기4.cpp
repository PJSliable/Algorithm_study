#include <bits/stdc++.h>
using namespace std;
int T, dp[10001], n;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fastIO();
    cin >> T;
    dp[0] = 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j < 10001; j++){
            if(j-i >= 0)dp[j] += dp[j - i];
        }
    }
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}