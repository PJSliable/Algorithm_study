#include <bits/stdc++.h>
using namespace std;
int N, a[1001], dp[1001], ret;
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
    fill(dp, dp + N, 1);
    for (int i = 1; i < N; i++){
        for (int j = 0; j < i; j++){
            if (a[j] < a[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < N; i++){
        ret = max(ret, dp[i]);
    }
    cout << ret << '\n';
    return 0;
}