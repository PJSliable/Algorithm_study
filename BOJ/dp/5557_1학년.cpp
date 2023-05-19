#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100], dp[101][21], N;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    dp[0][a[0]] = 1;

    for (int i = 1; i < N - 1; i++){
        for (int j = 0; j <= 20; j++){
            if (dp[i-1][j] == 0)
                continue;
            if (j + a[i]>= 0 && j + a[i] <= 20)
                dp[i][j + a[i]] += dp[i-1][j];
            if (j - a[i] >= 0 && j - a[i] <= 20)
                dp[i][j - a[i]] += dp[i-1][j];
        }
    }
    cout << dp[N-2][a[N - 1]] << '\n';
}