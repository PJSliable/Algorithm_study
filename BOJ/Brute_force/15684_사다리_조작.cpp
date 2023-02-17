#include <bits/stdc++.h>
using namespace std;

int N, M, H, a, b, ret, m[31][11], idx;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(){
    for (int i = 1; i <= N; i++){
        int temp = i;
        for (int j = 1; j <= H; j++)
        {
            if (m[j][temp])temp++;
            else if(m[j][temp-1])temp--;
        }
        if (i != temp)return 0;
    }
    return 1;
}
void combi(int cnt, pair<int, int> start){
    if (idx)
        return;
    if (cnt == ret)
    {
        if (check())idx = 1;
        return;
    }

    for (int j = start.second+1; j <= N-1; j++){
        if (m[start.first][j] || m[start.first][j+1] || m[start.first][j-1] )
            continue;
        m[start.first][j] = 1;
        combi(cnt+1, {start.first, j});
        m[start.first][j] = 0;
    }

    for (int i = start.first + 1; i <= H; i++){
        for (int j = 1; j <= N-1; j++){
            if (m[i][j] || m[i][j+1] || m[i][j-1] )continue;
            m[i][j] = 1;
            combi(cnt+1, {i, j});
            m[i][j] = 0;
        }
    }
    return;
}

int main(){
    fastIO();
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        m[a][b] = 1;
    }

    while (ret <= 3){
        combi(0, {1,0});
        if (idx)
            break;
        ret++;
    }

    if (ret > 3)
        ret = -1;
    cout << ret << '\n';
}