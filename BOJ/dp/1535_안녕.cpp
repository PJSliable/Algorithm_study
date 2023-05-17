#include <bits/stdc++.h>
using namespace std;
int N, ret;
int L[20], J[20], dp[100];
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
        cin >> L[i];
    }
    for (int i = 0; i < N; i++){
        cin >> J[i];
    }
    for (int i = 0; i < N; i++){
        for (int j = 99; j >= L[i]; j--){
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    for (int j = 99; j >= 0; j--)ret = max(ret, dp[j]);
    cout << ret << '\n';
}