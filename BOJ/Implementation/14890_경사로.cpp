#include <bits/stdc++.h>
using namespace std;
int N, L, m[100][100], m1[100][100], ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void solve(int m[100][100]){
    for (int i = 0; i < N; i++){
        int cnt = 1;
        int j;
        for (j = 0; j < N - 1; j++)
        {
            if (m[i][j] == m[i][j+1])
                cnt++;
            else if (m[i][j] + 1 == m[i][j+1] && cnt >= L)
                cnt = 1;
            else if(m[i][j] - 1 == m[i][j+1] && cnt >= 0)
                cnt = -L + 1;
            else
                break;
        }
        if (j == N-1 && cnt >=0)
            ret++;
    }
    return;
}
int main()
{
    fastIO();
    cin >> N >> L;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> m[i][j];
            m1[j][i] = m[i][j];
        }
    }
    solve(m);
    solve(m1);
    cout << ret << '\n';
    return 0;
}