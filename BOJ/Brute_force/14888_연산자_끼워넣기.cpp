#include <bits/stdc++.h>
using namespace std;
int N, A[11], cal[4], minret = 1000000000+1 , maxret = -1000000000-1;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void dfs(int idx, int cal[4], int sum){
    if (idx == N){
        minret = min(minret, sum);
        maxret = max(maxret, sum);
        return;
    }
    for (int i = 0; i < 4; i++){
        if (cal[i]){
            cal[i]--;
            if (i == 0)dfs(idx+1, cal, sum+A[idx]);
            else if (i == 1)dfs(idx+1, cal, sum-A[idx]);
            else if (i == 2)dfs(idx+1, cal, sum*A[idx]);
            else if (i == 3)dfs(idx+1, cal, sum/A[idx]);
            cal[i]++;
        }
    }
}
int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> cal[i];
    }
    dfs(1, cal, A[0]);
    cout << maxret << '\n'
         << minret << '\n';
    return 0;
}