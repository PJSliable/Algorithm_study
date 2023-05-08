#include <bits/stdc++.h>
using namespace std;
int N, a[16][16], dp[16][16][3];
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
        for (int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    // dp[0][1] = [가로로 끝난 경우, 대각선으로 끝난 경우, 세로로 끝난 경우] 각각의 개수 
    dp[0][1][0] = 1;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (a[i][j] == 1)
                continue;
            if (j - 1 >= 0)
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];
            if(i-1>=0)
                dp[i][j][2] += dp[i-1][j][1] + dp[i-1][j][2];
            if(i-1>=0 && j-1>=0 && a[i][j-1] != 1 && a[i-1][j] != 1)
                dp[i][j][1] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }   
    }
    cout << dp[N - 1][N - 1][0]+dp[N - 1][N - 1][1]+dp[N - 1][N - 1][2] << '\n';
}