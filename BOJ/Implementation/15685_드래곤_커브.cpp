#include <bits/stdc++.h>
using namespace std;
int N, x, y , d, g, a[101][101];
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int counting(){
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++){
            if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1])
                cnt++;
        }
    }
    return cnt;
}
void move(int x, int y, int pointx, int pointy, int g, vector<pair<int, int>> v){
    if (g == 0){
        return;
    }
    vector<pair<int, int>> nowadd;
    for (auto now : v){
        int nextx = pointx + (now.second - pointy);
        int nexty = pointy - (now.first - pointx);
        a[nextx][nexty] = 1;
        nowadd.push_back({nextx, nexty});
    }
    for(auto now: nowadd)v.push_back({now.first, now.second});
    move(x, y, pointx + (y - pointy), pointy - (x - pointx), g - 1, v);
    return;
}

int main(){
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        vector<pair<int, int>> b;
        int temp = x;
        x = y;
        y = temp;
        b.push_back({x, y});
        b.push_back({x + dx[d], y + dy[d]});
        a[x][y] = 1;
        a[x + dx[d]][y + dy[d]] = 1;
        move(x, y, x + dx[d], y + dy[d], g, b);
    }
    cout << counting() << '\n';
    return 0;
}