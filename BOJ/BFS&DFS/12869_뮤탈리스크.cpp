#include <bits/stdc++.h>
using namespace std;
int N, a[3], visited[61][61][61];
int combi[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}};
struct A{
    int a, b, c;
};
queue<A> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    q.push({a[0], a[1], a[2]});
    visited[a[0]][a[1]][a[2]] = 1;
    while (q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int na = max(0, a - combi[i][0]);
            int nb = max(0, b - combi[i][1]);
            int nc = max(0, c - combi[i][2]);
            if (na == 0 && nb == 0 && nc == 0){
                cout << visited[a][b][c] << '\n';
                return 0;
            }
            if (visited[na][nb][nc])continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
}