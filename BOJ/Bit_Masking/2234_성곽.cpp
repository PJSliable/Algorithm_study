#include <bits/stdc++.h>
using namespace std;
int N, M, m[50][50], compSize[50 * 50 +1], visited[50][50], cnt, v, ret;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int dfs(int i, int j, int cnt){
    int ret = 1;
    for (int di = 0; di < 4; di++){
        if (m[i][j] & (1<<di))
            continue;
        int nx = i + dx[di];
        int ny = j + dy[di];
        if (visited[nx][ny])
            continue;
        visited[nx][ny] = cnt;
        ret += dfs(nx, ny, cnt);
    }
    return ret;
}
int main(){
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if(visited[i][j])
                continue;
            cnt++;
            visited[i][j] = cnt;
            int now_value = dfs(i, j, cnt);
            compSize[cnt] = now_value;
            v = max(v, now_value);
        }
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (j < N-1 && visited[i][j] != visited[i][j+1])
                ret = max(ret, compSize[visited[i][j]] + compSize[visited[i][j + 1]]);
            if (i < M-1 && visited[i][j] != visited[i+1][j])
                ret = max(ret, compSize[visited[i][j]] + compSize[visited[i + 1][j]]);
        }
    }

        cout << cnt << '\n'
             << v << '\n'
             << ret;
    return 0;
}