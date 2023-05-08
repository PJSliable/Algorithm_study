#include <bits/stdc++.h>
using namespace std;
int N, K, dp[100001], temp, W, V;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N >> K;
    while(N--){
        cin >> W >> V;
        for (int i = K; i >= W; i--){
            dp[i] = max(dp[i], dp[i - W] + V);
        }
    }
    cout << dp[K] << '\n';
}