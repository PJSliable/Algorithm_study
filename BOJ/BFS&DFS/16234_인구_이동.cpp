#include <bits/stdc++.h>
using namespace std;
int N, L, R, m[50][50], visited[50][50], ret, sum;
vector<pair<int, int>> v;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void dfs(int x, int y){
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx< 0 || ny <0|| nx >= N || ny >= N|| visited[nx][ny])continue;
        int now = abs(m[nx][ny] - m[x][y]);
        if (now >= L && now <= R)
        {
            v.push_back({nx, ny});
            visited[nx][ny] = 1;
            sum += m[nx][ny];
            dfs(nx, ny);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)cin >> m[i][j];
    while (true){
        bool flag = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (visited[i][j] == 0){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = m[i][j];
                    dfs(i, j);
                    if(v.size() == 1)
                        continue;
                    for (auto b : v)
                    {
                        m[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag)
            break;
        ret++;
    }
    cout << ret << '\n';
    return 0;
}