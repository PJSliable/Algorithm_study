#include <bits/stdc++.h>
using namespace std;
int N, M, a[9][9], ret = 8 * 8 + 1;
const int dx[] = {-1, 0, 1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1, 0, 1};
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
vector<pair<int, int>> v3;
vector<pair<int, int>> v4;
vector<pair<int, int>> v5;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void dfs(vector<pair<int, int>> v1,vector<pair<int, int>> v2,vector<pair<int, int>> v3,vector<pair<int, int>> v4,vector<pair<int, int>> v5,vector<pair<int, int>> b){
    if (v1.size()){
        int x = v1.back().first;
        int y = v1.back().second;
        v1.pop_back();
        for (int di = 0; di < 4; di++)
        {
            int cnt = 1;
            while (true){
                int nx = x + dx[di] * cnt;
                int ny = y + dy[di] * cnt;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt++;
            }
            dfs(v1, v2, v3, v4, v5, b);
            while(--cnt){
                b.pop_back();
            }
        }
        return;
    }
    else if (v2.size())
    {
        int x = v2.back().first;
        int y = v2.back().second;
        v2.pop_back();
        for (int di = 0; di < 2; di++){
            int cnt1 = 1;
            while (true){
                int nx = x + dx[di] * cnt1;
                int ny = y + dy[di] * cnt1;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt1++;
            }
            int cnt2 = 1;
            while (true){
                int nx = x + dx[di+2] * cnt2;
                int ny = y + dy[di+2] * cnt2;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt2++;
            }
            dfs(v1, v2, v3, v4, v5, b);
            while(--cnt1)
                b.pop_back();
            while(--cnt2)
                b.pop_back();
        }
        return;
    }
    else if (v3.size()){
        int x = v3.back().first;
        int y = v3.back().second;
        v3.pop_back();
        for (int di = 0; di < 4; di++){
            int cnt1 = 1;
            while (true){
                int nx = x + dx[di] * cnt1;
                int ny = y + dy[di] * cnt1;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt1++;
            }
            int cnt2 = 1;
            while (true){
                int nx = x + dx[di+1] * cnt2;
                int ny = y + dy[di+1] * cnt2;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt2++;
            }
            dfs(v1, v2, v3, v4, v5, b);
            while(--cnt1)
                b.pop_back();
            while(--cnt2)
                b.pop_back();
        }
        return;
    }
    else if (v4.size()){
        int x = v4.back().first;
        int y = v4.back().second;
        v4.pop_back();
        for (int di = 0; di < 4; di++){
            int cnt1 = 1;
            while (true){
                int nx = x + dx[di] * cnt1;
                int ny = y + dy[di] * cnt1;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt1++;
            }
            int cnt2 = 1;
            while (true){
                int nx = x + dx[di+1] * cnt2;
                int ny = y + dy[di+1] * cnt2;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt2++;
            }
            int cnt3 = 1;
            while (true){
                int nx = x + dx[di+2] * cnt3;
                int ny = y + dy[di+2] * cnt3;
                if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                    break;
                b.push_back({nx, ny});
                cnt3++;
            }
            dfs(v1, v2, v3, v4, v5, b);
            while(--cnt1)
                b.pop_back();
            while(--cnt2)
                b.pop_back();
            while(--cnt3)
                b.pop_back();
        }
        return;
    }
    else if (v5.size()){
        while (v5.size()){
            int x = v5.back().first;
            int y = v5.back().second;
            v5.pop_back();
            for (int di = 0; di < 4; di++){
                int cnt1 = 1;
                while (true){
                    int nx = x + dx[di] * cnt1;
                    int ny = y + dy[di] * cnt1;
                    if (nx <0 || ny <0 || nx >= N || ny >= M || a[nx][ny] == 6)
                        break;
                    b.push_back({nx, ny});
                    cnt1++;
                }
            }
        }
        dfs(v1, v2, v3, v4, v5, b);
        return;
    }
    else{
        int temp[9][9];
        memcpy(temp, a, sizeof(a));
        for (auto now: b){
            if (temp[now.first][now.second] == 0)
                temp[now.first][now.second] = -1;
        }
        int nowcnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M;j++){
                if (temp[i][j] == 0)
                    nowcnt++;
            }
        }
        ret = min(ret, nowcnt);
        return;
    }
}
int main(){
    fastIO();
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> a[i][j];
            if (a[i][j] == 1)
                v1.push_back({i, j});
            else if (a[i][j] == 2)
                v2.push_back({i, j});
            else if (a[i][j] == 3)
                v3.push_back({i, j});
            else if (a[i][j] == 4)
                v4.push_back({i, j});
            else if (a[i][j] == 5)
                v5.push_back({i, j});
        }
    }
    vector<pair<int, int>> b;
    dfs(v1,v2,v3,v4,v5, b);
    cout << ret << '\n';
    return 0;
}