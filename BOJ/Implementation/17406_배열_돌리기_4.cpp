#include <bits/stdc++.h>
using namespace std;
int N, M, K, a[51][51], temp[51][51], r, c, s, turn[6][3], ret= 50 * 100 +1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void cal(){
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j:temp[i])sum += j;
        ret = min(ret, sum);
    }
    return;
}
void move(int r, int c, int s){
    int cnt = s;
    while (cnt){
        int x = r - cnt;
        int y = c - cnt;
        int di = 0;
        while (true)
        {
            int nx = x + dx[di];
            int ny = y + dy[di];
            if (nx == r - cnt && ny == c-cnt)
                break;
            swap(temp[x][y], temp[nx][ny]);
            if ((nx == r - cnt || nx == r + cnt) && (ny == c-cnt || ny == c+cnt))
                di++;
            x = nx, y = ny;
        }
        cnt--;
    }
}
int main(){
    fastIO();
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < K; i++)
    {
        cin >> r >> c >> s;
        v.push_back({r - 1, c - 1, s});
    }
    sort(v.begin(), v.end());
    do
    {
        memcpy(temp, a, sizeof(a));
        for (auto now : v){
            move(now[0], now[1], now[2]);
        }
        cal();
    } while (next_permutation(v.begin(), v.end()));
    cout << ret << '\n';
    return 0;
}