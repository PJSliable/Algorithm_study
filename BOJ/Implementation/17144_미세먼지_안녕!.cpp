#include <bits/stdc++.h>
using namespace std;
#define y1 aa
int R, C, T, a[51][51], temp[51][51], x, y;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {-1, 0, 1, 0, -1};
vector<pair<int, int>> cleaner;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int cal(){
    int ret = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            ret += a[i][j];
    }
    return ret;
}
void spread(){
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++){
            if (a[i][j] != 0)
            {
                int cnt = 0;
                vector<pair<int, int>> s;
                for (int di = 0; di < 4; di++)
                {
                    int nx = i + dx[di];
                    int ny = j + dy[di];
                    if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                        continue;
                    if ((nx == cleaner[0].first && ny == cleaner[0].second) || (nx == cleaner[1].first && ny == cleaner[1].second) )
                        continue;
                    cnt++;
                    temp[nx][ny] += a[i][j] / 5;
                }
                temp[i][j] -= (a[i][j] / 5) * cnt;
            }
        }
    }
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            a[i][j] += temp[i][j];
        }
    }
    return;
}
void wind(){
    tie(x, y) = cleaner[0];
    int di = 3;
    while (true){
        int nx = x + dx[di];
        int ny = y + dy[di];
        if (nx == cleaner[0].first && ny == cleaner[0].second)
            break;
        swap(a[nx][ny], a[x][y]);
        if ((nx == 0 || nx == cleaner[0].first) && (ny == 0 || ny == C - 1 ))di--;
        x = nx, y = ny;
    }
    a[cleaner[0].first][cleaner[0].second] = 0;
    tie(x, y) = cleaner[1];
    di = 1;
    while (true){
        int nx = x + dx[di];
        int ny = y + dy[di];
        if (nx == cleaner[1].first && ny == cleaner[1].second)
            break;
        swap(a[nx][ny], a[x][y]);
        if ((nx == R - 1 || nx == cleaner[1].first) && (ny == 0 || ny == C - 1))di++;
        x = nx, y = ny;
    }
    a[cleaner[1].first][cleaner[1].second] = 0;
}
int main(){
    fastIO();
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> a[i][j];
            if (a[i][j]==-1){
                cleaner.push_back({i, j});
                a[i][j] = 0;
            }
        }
    }
    while(T--){
        spread();
        wind();
    }
    cout << cal() << '\n';
    return 0;
}